/****************************************************************************
** Meta object code from reading C++ file 'imageprocessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/imageprocessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageProcessor_t {
    QByteArrayData data[57];
    char stringdata0[720];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcessor_t qt_meta_stringdata_ImageProcessor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ImageProcessor"
QT_MOC_LITERAL(1, 15, 15), // "importRequested"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "filePath"
QT_MOC_LITERAL(4, 41, 19), // "backgroundRequested"
QT_MOC_LITERAL(5, 61, 16), // "enhanceRequested"
QT_MOC_LITERAL(6, 78, 19), // "blackWhiteRequested"
QT_MOC_LITERAL(7, 98, 14), // "sepiaRequested"
QT_MOC_LITERAL(8, 113, 13), // "blurRequested"
QT_MOC_LITERAL(9, 127, 16), // "sharpenRequested"
QT_MOC_LITERAL(10, 144, 14), // "edgesRequested"
QT_MOC_LITERAL(11, 159, 16), // "cartoonRequested"
QT_MOC_LITERAL(12, 176, 20), // "neuralStyleRequested"
QT_MOC_LITERAL(13, 197, 15), // "invertRequested"
QT_MOC_LITERAL(14, 213, 15), // "adjustRequested"
QT_MOC_LITERAL(15, 229, 10), // "brightness"
QT_MOC_LITERAL(16, 240, 8), // "contrast"
QT_MOC_LITERAL(17, 249, 10), // "saturation"
QT_MOC_LITERAL(18, 260, 19), // "adjustLiveRequested"
QT_MOC_LITERAL(19, 280, 25), // "commitAdjustmentRequested"
QT_MOC_LITERAL(20, 306, 13), // "undoRequested"
QT_MOC_LITERAL(21, 320, 14), // "resetRequested"
QT_MOC_LITERAL(22, 335, 15), // "exportRequested"
QT_MOC_LITERAL(23, 351, 21), // "originalSourceChanged"
QT_MOC_LITERAL(24, 373, 19), // "resultSourceChanged"
QT_MOC_LITERAL(25, 393, 17), // "statusTextChanged"
QT_MOC_LITERAL(26, 411, 11), // "busyChanged"
QT_MOC_LITERAL(27, 423, 15), // "hasImageChanged"
QT_MOC_LITERAL(28, 439, 14), // "canUndoChanged"
QT_MOC_LITERAL(29, 454, 16), // "handleStateReady"
QT_MOC_LITERAL(30, 471, 8), // "original"
QT_MOC_LITERAL(31, 480, 7), // "current"
QT_MOC_LITERAL(32, 488, 7), // "canUndo"
QT_MOC_LITERAL(33, 496, 10), // "statusText"
QT_MOC_LITERAL(34, 507, 9), // "errorText"
QT_MOC_LITERAL(35, 517, 7), // "process"
QT_MOC_LITERAL(36, 525, 16), // "removeBackground"
QT_MOC_LITERAL(37, 542, 7), // "enhance"
QT_MOC_LITERAL(38, 550, 10), // "blackWhite"
QT_MOC_LITERAL(39, 561, 5), // "sepia"
QT_MOC_LITERAL(40, 567, 4), // "blur"
QT_MOC_LITERAL(41, 572, 7), // "sharpen"
QT_MOC_LITERAL(42, 580, 5), // "edges"
QT_MOC_LITERAL(43, 586, 7), // "cartoon"
QT_MOC_LITERAL(44, 594, 11), // "neuralStyle"
QT_MOC_LITERAL(45, 606, 6), // "invert"
QT_MOC_LITERAL(46, 613, 6), // "adjust"
QT_MOC_LITERAL(47, 620, 10), // "adjustLive"
QT_MOC_LITERAL(48, 631, 16), // "commitAdjustment"
QT_MOC_LITERAL(49, 648, 4), // "undo"
QT_MOC_LITERAL(50, 653, 5), // "reset"
QT_MOC_LITERAL(51, 659, 12), // "exportResult"
QT_MOC_LITERAL(52, 672, 5), // "clear"
QT_MOC_LITERAL(53, 678, 14), // "originalSource"
QT_MOC_LITERAL(54, 693, 12), // "resultSource"
QT_MOC_LITERAL(55, 706, 4), // "busy"
QT_MOC_LITERAL(56, 711, 8) // "hasImage"

    },
    "ImageProcessor\0importRequested\0\0"
    "filePath\0backgroundRequested\0"
    "enhanceRequested\0blackWhiteRequested\0"
    "sepiaRequested\0blurRequested\0"
    "sharpenRequested\0edgesRequested\0"
    "cartoonRequested\0neuralStyleRequested\0"
    "invertRequested\0adjustRequested\0"
    "brightness\0contrast\0saturation\0"
    "adjustLiveRequested\0commitAdjustmentRequested\0"
    "undoRequested\0resetRequested\0"
    "exportRequested\0originalSourceChanged\0"
    "resultSourceChanged\0statusTextChanged\0"
    "busyChanged\0hasImageChanged\0canUndoChanged\0"
    "handleStateReady\0original\0current\0"
    "canUndo\0statusText\0errorText\0process\0"
    "removeBackground\0enhance\0blackWhite\0"
    "sepia\0blur\0sharpen\0edges\0cartoon\0"
    "neuralStyle\0invert\0adjust\0adjustLive\0"
    "commitAdjustment\0undo\0reset\0exportResult\0"
    "clear\0originalSource\0resultSource\0"
    "busy\0hasImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       6,  304, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  224,    2, 0x06 /* Public */,
       4,    0,  227,    2, 0x06 /* Public */,
       5,    0,  228,    2, 0x06 /* Public */,
       6,    0,  229,    2, 0x06 /* Public */,
       7,    0,  230,    2, 0x06 /* Public */,
       8,    0,  231,    2, 0x06 /* Public */,
       9,    0,  232,    2, 0x06 /* Public */,
      10,    0,  233,    2, 0x06 /* Public */,
      11,    0,  234,    2, 0x06 /* Public */,
      12,    0,  235,    2, 0x06 /* Public */,
      13,    0,  236,    2, 0x06 /* Public */,
      14,    3,  237,    2, 0x06 /* Public */,
      18,    3,  244,    2, 0x06 /* Public */,
      19,    0,  251,    2, 0x06 /* Public */,
      20,    0,  252,    2, 0x06 /* Public */,
      21,    0,  253,    2, 0x06 /* Public */,
      22,    0,  254,    2, 0x06 /* Public */,
      23,    0,  255,    2, 0x06 /* Public */,
      24,    0,  256,    2, 0x06 /* Public */,
      25,    0,  257,    2, 0x06 /* Public */,
      26,    0,  258,    2, 0x06 /* Public */,
      27,    0,  259,    2, 0x06 /* Public */,
      28,    0,  260,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      29,    5,  261,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      35,    1,  272,    2, 0x02 /* Public */,
      36,    0,  275,    2, 0x02 /* Public */,
      37,    0,  276,    2, 0x02 /* Public */,
      38,    0,  277,    2, 0x02 /* Public */,
      39,    0,  278,    2, 0x02 /* Public */,
      40,    0,  279,    2, 0x02 /* Public */,
      41,    0,  280,    2, 0x02 /* Public */,
      42,    0,  281,    2, 0x02 /* Public */,
      43,    0,  282,    2, 0x02 /* Public */,
      44,    0,  283,    2, 0x02 /* Public */,
      45,    0,  284,    2, 0x02 /* Public */,
      46,    3,  285,    2, 0x02 /* Public */,
      47,    3,  292,    2, 0x02 /* Public */,
      48,    0,  299,    2, 0x02 /* Public */,
      49,    0,  300,    2, 0x02 /* Public */,
      50,    0,  301,    2, 0x02 /* Public */,
      51,    0,  302,    2, 0x02 /* Public */,
      52,    0,  303,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::QImage, QMetaType::Bool, QMetaType::QString, QMetaType::QString,   30,   31,   32,   33,   34,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      53, QMetaType::QString, 0x00495001,
      54, QMetaType::QString, 0x00495001,
      33, QMetaType::QString, 0x00495001,
      55, QMetaType::Bool, 0x00495001,
      56, QMetaType::Bool, 0x00495001,
      32, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
      17,
      18,
      19,
      20,
      21,
      22,

       0        // eod
};

void ImageProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageProcessor *_t = static_cast<ImageProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->importRequested((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->backgroundRequested(); break;
        case 2: _t->enhanceRequested(); break;
        case 3: _t->blackWhiteRequested(); break;
        case 4: _t->sepiaRequested(); break;
        case 5: _t->blurRequested(); break;
        case 6: _t->sharpenRequested(); break;
        case 7: _t->edgesRequested(); break;
        case 8: _t->cartoonRequested(); break;
        case 9: _t->neuralStyleRequested(); break;
        case 10: _t->invertRequested(); break;
        case 11: _t->adjustRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->adjustLiveRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->commitAdjustmentRequested(); break;
        case 14: _t->undoRequested(); break;
        case 15: _t->resetRequested(); break;
        case 16: _t->exportRequested(); break;
        case 17: _t->originalSourceChanged(); break;
        case 18: _t->resultSourceChanged(); break;
        case 19: _t->statusTextChanged(); break;
        case 20: _t->busyChanged(); break;
        case 21: _t->hasImageChanged(); break;
        case 22: _t->canUndoChanged(); break;
        case 23: _t->handleStateReady((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 24: _t->process((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->removeBackground(); break;
        case 26: _t->enhance(); break;
        case 27: _t->blackWhite(); break;
        case 28: _t->sepia(); break;
        case 29: _t->blur(); break;
        case 30: _t->sharpen(); break;
        case 31: _t->edges(); break;
        case 32: _t->cartoon(); break;
        case 33: _t->neuralStyle(); break;
        case 34: _t->invert(); break;
        case 35: _t->adjust((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 36: _t->adjustLive((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 37: _t->commitAdjustment(); break;
        case 38: _t->undo(); break;
        case 39: _t->reset(); break;
        case 40: _t->exportResult(); break;
        case 41: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageProcessor::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::importRequested)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::backgroundRequested)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::enhanceRequested)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::blackWhiteRequested)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::sepiaRequested)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::blurRequested)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::sharpenRequested)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::edgesRequested)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::cartoonRequested)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::neuralStyleRequested)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::invertRequested)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::adjustRequested)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::adjustLiveRequested)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::commitAdjustmentRequested)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::undoRequested)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::resetRequested)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::exportRequested)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::originalSourceChanged)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::resultSourceChanged)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::statusTextChanged)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::busyChanged)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::hasImageChanged)) {
                *result = 21;
                return;
            }
        }
        {
            typedef void (ImageProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcessor::canUndoChanged)) {
                *result = 22;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ImageProcessor *_t = static_cast<ImageProcessor *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->originalSource(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->resultSource(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->statusText(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->busy(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->hasImage(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->canUndo(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ImageProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageProcessor.data,
      qt_meta_data_ImageProcessor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessor.stringdata0))
        return static_cast<void*>(const_cast< ImageProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 42;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ImageProcessor::importRequested(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageProcessor::backgroundRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ImageProcessor::enhanceRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ImageProcessor::blackWhiteRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ImageProcessor::sepiaRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ImageProcessor::blurRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void ImageProcessor::sharpenRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void ImageProcessor::edgesRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void ImageProcessor::cartoonRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void ImageProcessor::neuralStyleRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void ImageProcessor::invertRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void ImageProcessor::adjustRequested(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ImageProcessor::adjustLiveRequested(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ImageProcessor::commitAdjustmentRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}

// SIGNAL 14
void ImageProcessor::undoRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void ImageProcessor::resetRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void ImageProcessor::exportRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 16, Q_NULLPTR);
}

// SIGNAL 17
void ImageProcessor::originalSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, Q_NULLPTR);
}

// SIGNAL 18
void ImageProcessor::resultSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, Q_NULLPTR);
}

// SIGNAL 19
void ImageProcessor::statusTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, Q_NULLPTR);
}

// SIGNAL 20
void ImageProcessor::busyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, Q_NULLPTR);
}

// SIGNAL 21
void ImageProcessor::hasImageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, Q_NULLPTR);
}

// SIGNAL 22
void ImageProcessor::canUndoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
