/****************************************************************************
** Meta object code from reading C++ file 'HttpApiExecutor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HttpApiExecutor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HttpApiExecutor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpApiExecutor_t {
    QByteArrayData data[12];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpApiExecutor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpApiExecutor_t qt_meta_stringdata_HttpApiExecutor = {
    {
QT_MOC_LITERAL(0, 0, 15), // "HttpApiExecutor"
QT_MOC_LITERAL(1, 16, 18), // "processRequestSlot"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "method"
QT_MOC_LITERAL(4, 43, 4), // "path"
QT_MOC_LITERAL(5, 48, 5), // "query"
QT_MOC_LITERAL(6, 54, 4), // "body"
QT_MOC_LITERAL(7, 59, 28), // "buildXy2dMonitorEventPayload"
QT_MOC_LITERAL(8, 88, 14), // "lastHttpStatus"
QT_MOC_LITERAL(9, 103, 22), // "setAgentHttpController"
QT_MOC_LITERAL(10, 126, 20), // "AgentHttpController*"
QT_MOC_LITERAL(11, 147, 10) // "controller"

    },
    "HttpApiExecutor\0processRequestSlot\0\0"
    "method\0path\0query\0body\0"
    "buildXy2dMonitorEventPayload\0"
    "lastHttpStatus\0setAgentHttpController\0"
    "AgentHttpController*\0controller"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpApiExecutor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x0a /* Public */,
       7,    0,   43,    2, 0x0a /* Public */,
       8,    0,   44,    2, 0x0a /* Public */,
       9,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QByteArray, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,    3,    4,    5,    6,
    QMetaType::QByteArray,
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void HttpApiExecutor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpApiExecutor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QByteArray _r = _t->processRequestSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QByteArray(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 1: { QByteArray _r = _t->buildXy2dMonitorEventPayload();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->lastHttpStatus();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setAgentHttpController((*reinterpret_cast< AgentHttpController*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpApiExecutor::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HttpApiExecutor.data,
    qt_meta_data_HttpApiExecutor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpApiExecutor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpApiExecutor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpApiExecutor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpApiExecutor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
