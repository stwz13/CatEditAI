# ncnn для CatEdit AI

[ncnn](https://github.com/Tencent/ncnn) используется для офлайн-инференса на устройстве:

- **ИИ-стиль** — Fast Neural Style (Mosaic), `models/mosaic.bin`
- **ИИ-вырезка фона** — U2-NetP, `models/u2netp.ncnn.param` + `models/u2netp.ncnn.bin`

> **Важно:** библиотека ncnn **зависит от архитектуры процессора**.  
> Для эмулятора (x86_64) и для телефона (aarch64) нужны **две отдельные сборки**.

---

## Схема

| Цель | Kit в Qt Creator | Архитектура ncnn |
|------|----------------|------------------|
| Эмулятор на ПК | `AuroraOS-5.2.0.180-x86_64` | `x86_64` |
| Реальный телефон | `AuroraOS-5.2.0.180-aarch64` | `aarch64` |

Проект ищет `libncnn.so` здесь:

```
third_party/ncnn/build/<имя_папки_сборки>/lib/libncnn.so
```

Имя папки совпадает с каталогом shadow build в Qt Creator, например:

```
AuroraOS_5_2_0_180_aarch64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug
```

---

## Подготовка (один раз)

### 1. Исходники ncnn

В **Build Engine** (SSH, порт **2222**):

```bash
ssh -p 2222 -i C:/AuroraOS/vmshare/ssh/private_keys/sdk mersdk@localhost
cd /path/to/catedit-aurora
```

Если папки `third_party/ncnn/source` ещё нет:

```bash
git clone --depth 1 --branch 20240820 https://github.com/Tencent/ncnn.git third_party/ncnn/source
chmod +x third_party/ncnn/build_ncnn.sh
```

### 2. Модели (на хосте Windows или в Build Engine)

```bash
./tools/fetch_models.sh
```

Нужны файлы в `models/`:

- `mosaic.bin`
- `u2netp.ncnn.param`
- `u2netp.ncnn.bin`

Модели **одинаковы** для x86_64 и aarch64 — конвертировать повторно не нужно.

---

## Сборка ncnn для телефона (aarch64)

### Шаг 1. Узнать имя папки kit

В Qt Creator:

1. Откройте `ru.template.CatEditAiProSixSevenSigmaEditor.pro`
2. Выберите kit **`AuroraOS-5.2.0.180-aarch64`**
3. **Проекты → Сборка** — включите shadow build
4. Один раз нажмите **Сборка** (даже если появится предупреждение про ncnn)

Имя папки смотрите в **Проекты → Сборка → Каталог сборки**, например:

```
.../build/AuroraOS_5_2_0_180_aarch64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug
```

Скопируйте только **последний сегмент** пути — это аргумент для `build_ncnn.sh`.

### Шаг 2. Собрать ncnn в Build Engine

```bash
ssh -p 2222 -i C:/AuroraOS/vmshare/ssh/private_keys/sdk mersdk@localhost
cd /path/to/catedit-aurora

sb2 -t AuroraOS-5.2.0.180-aarch64.default -R -m sdk-build -c \
  "./third_party/ncnn/build_ncnn.sh AuroraOS_5_2_0_180_aarch64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug"
```

Замените имя папки на **ваше** (из шага 1).

Сборка занимает несколько минут. В конце должно появиться:

```
ncnn built into third_party/ncnn/build/AuroraOS_5_2_0_180_aarch64_.../lib
```

### Шаг 3. Проверить архитектуру

```bash
file third_party/ncnn/build/AuroraOS_5_2_0_180_aarch64_.../lib/libncnn.so
```

Ожидается:

```
ELF 64-bit LSB shared object, ARM aarch64, ...
```

Если видите `x86-64` — вы собрали не тот target (нужен `aarch64.default`).

### Шаг 4. Собрать и установить приложение на телефон

В Qt Creator:

1. Kit: **`AuroraOS-5.2.0.180-aarch64`**
2. Устройство: **ваш телефон** (не эмулятор)
3. На телефоне: режим разработчика, USB-отладка, доверие к ПК
4. **Ctrl+B** → **Ctrl+R**

Предупреждение `Local ncnn libraries were not found` должно исчезнуть.

---

## Сборка ncnn для эмулятора (x86_64)

Тот же процесс, но target и kit другие:

```bash
sb2 -t AuroraOS-5.2.0.180-x86_64.default -R -m sdk-build -c \
  "./third_party/ncnn/build_ncnn.sh AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug"
```

---

## Debug и Release

Для каждой конфигурации — **своя** папка сборки:

| Конфигурация | Суффикс папки |
|--------------|---------------|
| Debug | `...-Debug` |
| Release | `...-Release` |

Если собираете Release для телефона, повторите `build_ncnn.sh` с именем папки `...-Release`.

---

## Проверка на устройстве

После установки RPM:

1. Откройте фото
2. Нажмите **«ИИ-вырезка»** — в статусе должны быть времена prep / segmentation / post (нейросеть)
3. Нажмите **«ИИ-стиль»** — применится Mosaic

Если работает только эвристика (без таймингов нейросети) — `libncnn.so` не попал в пакет или собран под другую архитектуру.

Проверка на телефоне (SSH к устройству):

```bash
rpm -ql ru.template.CatEditAiProSixSevenSigmaEditor | grep -E 'libncnn|models/'
```

Должны быть:

```
/usr/share/ru.template.CatEditAiProSixSevenSigmaEditor/lib/libncnn.so
/usr/share/ru.template.CatEditAiProSixSevenSigmaEditor/models/mosaic.bin
/usr/share/ru.template.CatEditAiProSixSevenSigmaEditor/models/u2netp.ncnn.param
/usr/share/ru.template.CatEditAiProSixSevenSigmaEditor/models/u2netp.ncnn.bin
```

---

## Частые проблемы

### `Local ncnn libraries were not found for this kit/configuration`

- Не запускали `build_ncnn.sh` для **этого** kit (aarch64 vs x86_64)
- Неверное имя папки в аргументе скрипта
- Собираете Release, а ncnn есть только для Debug (или наоборот)

### `Пакет не прошёл проверку` (rpm-validator, libgomp)

Иногда ncnn тянет OpenMP. В `rpm/*.spec` уже есть исключение для `libncnn`. Если валидатор ругается на другие библиотеки — установите вручную:

```bash
pkcon install-local -y --allow-untrusted ru.template.CatEditAiProSixSevenSigmaEditor-0.1-1.aarch64.rpm
```

### Приложение падает при ИИ-операциях

```bash
file /usr/share/ru.template.CatEditAiProSixSevenSigmaEditor/lib/libncnn.so
```

На телефоне должно быть `aarch64`, не `x86-64`.

### Долгая первая инференс-операция

Первый запуск загружает модели в память — это нормально. U2-NetP на телефоне обычно 1–5 с на фото.

---

## Краткая шпаргалка (телефон)

```bash
# 1. Build Engine
ssh -p 2222 -i C:/AuroraOS/vmshare/ssh/private_keys/sdk mersdk@localhost
cd /path/to/catedit-aurora

# 2. ncnn для aarch64 (имя папки — ваше!)
sb2 -t AuroraOS-5.2.0.180-aarch64.default -R -m sdk-build -c \
  "./third_party/ncnn/build_ncnn.sh <ИМЯ_ПАПКИ_aarch64-Debug>"

# 3. Qt Creator: kit aarch64 → Ctrl+R на телефон
```
