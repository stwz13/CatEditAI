/****************************************************************************
** Meta object code from reading C++ file 'processingworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/processingworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processingworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProcessingWorker_t {
    QByteArrayData data[29];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessingWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessingWorker_t qt_meta_stringdata_ProcessingWorker = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ProcessingWorker"
QT_MOC_LITERAL(1, 17, 10), // "stateReady"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "original"
QT_MOC_LITERAL(4, 38, 7), // "current"
QT_MOC_LITERAL(5, 46, 7), // "canUndo"
QT_MOC_LITERAL(6, 54, 10), // "statusText"
QT_MOC_LITERAL(7, 65, 9), // "errorText"
QT_MOC_LITERAL(8, 75, 11), // "importImage"
QT_MOC_LITERAL(9, 87, 8), // "filePath"
QT_MOC_LITERAL(10, 96, 16), // "removeBackground"
QT_MOC_LITERAL(11, 113, 7), // "enhance"
QT_MOC_LITERAL(12, 121, 10), // "blackWhite"
QT_MOC_LITERAL(13, 132, 5), // "sepia"
QT_MOC_LITERAL(14, 138, 4), // "blur"
QT_MOC_LITERAL(15, 143, 7), // "sharpen"
QT_MOC_LITERAL(16, 151, 5), // "edges"
QT_MOC_LITERAL(17, 157, 7), // "cartoon"
QT_MOC_LITERAL(18, 165, 11), // "neuralStyle"
QT_MOC_LITERAL(19, 177, 6), // "invert"
QT_MOC_LITERAL(20, 184, 6), // "adjust"
QT_MOC_LITERAL(21, 191, 10), // "brightness"
QT_MOC_LITERAL(22, 202, 8), // "contrast"
QT_MOC_LITERAL(23, 211, 10), // "saturation"
QT_MOC_LITERAL(24, 222, 10), // "adjustLive"
QT_MOC_LITERAL(25, 233, 16), // "commitAdjustment"
QT_MOC_LITERAL(26, 250, 4), // "undo"
QT_MOC_LITERAL(27, 255, 5), // "reset"
QT_MOC_LITERAL(28, 261, 12) // "exportResult"

    },
    "ProcessingWorker\0stateReady\0\0original\0"
    "current\0canUndo\0statusText\0errorText\0"
    "importImage\0filePath\0removeBackground\0"
    "enhance\0blackWhite\0sepia\0blur\0sharpen\0"
    "edges\0cartoon\0neuralStyle\0invert\0"
    "adjust\0brightness\0contrast\0saturation\0"
    "adjustLive\0commitAdjustment\0undo\0reset\0"
    "exportResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessingWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  115,    2, 0x0a /* Public */,
      10,    0,  118,    2, 0x0a /* Public */,
      11,    0,  119,    2, 0x0a /* Public */,
      12,    0,  120,    2, 0x0a /* Public */,
      13,    0,  121,    2, 0x0a /* Public */,
      14,    0,  122,    2, 0x0a /* Public */,
      15,    0,  123,    2, 0x0a /* Public */,
      16,    0,  124,    2, 0x0a /* Public */,
      17,    0,  125,    2, 0x0a /* Public */,
      18,    0,  126,    2, 0x0a /* Public */,
      19,    0,  127,    2, 0x0a /* Public */,
      20,    3,  128,    2, 0x0a /* Public */,
      24,    3,  135,    2, 0x0a /* Public */,
      25,    0,  142,    2, 0x0a /* Public */,
      26,    0,  143,    2, 0x0a /* Public */,
      27,    0,  144,    2, 0x0a /* Public */,
      28,    0,  145,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::QImage, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
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
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   21,   22,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   21,   22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProcessingWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProcessingWorker *_t = static_cast<ProcessingWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateReady((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 1: _t->importImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->removeBackground(); break;
        case 3: _t->enhance(); break;
        case 4: _t->blackWhite(); break;
        case 5: _t->sepia(); break;
        case 6: _t->blur(); break;
        case 7: _t->sharpen(); break;
        case 8: _t->edges(); break;
        case 9: _t->cartoon(); break;
        case 10: _t->neuralStyle(); break;
        case 11: _t->invert(); break;
        case 12: _t->adjust((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->adjustLive((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->commitAdjustment(); break;
        case 15: _t->undo(); break;
        case 16: _t->reset(); break;
        case 17: _t->exportResult(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProcessingWorker::*_t)(const QImage & , const QImage & , bool , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProcessingWorker::stateReady)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProcessingWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ProcessingWorker.data,
      qt_meta_data_ProcessingWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProcessingWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessingWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessingWorker.stringdata0))
        return static_cast<void*>(const_cast< ProcessingWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int ProcessingWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void ProcessingWorker::stateReady(const QImage & _t1, const QImage & _t2, bool _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
