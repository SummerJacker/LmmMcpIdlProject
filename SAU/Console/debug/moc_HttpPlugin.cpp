/****************************************************************************
** Meta object code from reading C++ file 'HttpPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HttpPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HttpPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpServerWorker_t {
    QByteArrayData data[8];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpServerWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpServerWorker_t qt_meta_stringdata_HttpServerWorker = {
    {
QT_MOC_LITERAL(0, 0, 16), // "HttpServerWorker"
QT_MOC_LITERAL(1, 17, 12), // "listenOnPort"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "port"
QT_MOC_LITERAL(4, 36, 12), // "QHostAddress"
QT_MOC_LITERAL(5, 49, 11), // "bindAddress"
QT_MOC_LITERAL(6, 61, 15), // "onNewConnection"
QT_MOC_LITERAL(7, 77, 16) // "broadcastXy2dSse"

    },
    "HttpServerWorker\0listenOnPort\0\0port\0"
    "QHostAddress\0bindAddress\0onNewConnection\0"
    "broadcastXy2dSse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpServerWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       6,    0,   34,    2, 0x08 /* Private */,
       7,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HttpServerWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpServerWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listenOnPort((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2]))); break;
        case 1: _t->onNewConnection(); break;
        case 2: _t->broadcastXy2dSse(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpServerWorker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HttpServerWorker.data,
    qt_meta_data_HttpServerWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpServerWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpServerWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpServerWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpServerWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_HttpPlugin_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpPlugin_t qt_meta_stringdata_HttpPlugin = {
    {
QT_MOC_LITERAL(0, 0, 10) // "HttpPlugin"

    },
    "HttpPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void HttpPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject HttpPlugin::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HttpPlugin.data,
    qt_meta_data_HttpPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpPlugin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
