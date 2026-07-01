/****************************************************************************
** Meta object code from reading C++ file 'monitorImpl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../monitorImpl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitorImpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MonitorImpl_t {
    QByteArrayData data[10];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MonitorImpl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MonitorImpl_t qt_meta_stringdata_MonitorImpl = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MonitorImpl"
QT_MOC_LITERAL(1, 12, 10), // "displayMsg"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "std::string"
QT_MOC_LITERAL(4, 36, 11), // "updateTraps"
QT_MOC_LITERAL(5, 48, 16), // "updateFireEvents"
QT_MOC_LITERAL(6, 65, 17), // "updateNewestPhoto"
QT_MOC_LITERAL(7, 83, 28), // "updateFireEventsPicRelatives"
QT_MOC_LITERAL(8, 112, 14), // "const PicList*"
QT_MOC_LITERAL(9, 127, 19) // "openCountDownWindow"

    },
    "MonitorImpl\0displayMsg\0\0std::string\0"
    "updateTraps\0updateFireEvents\0"
    "updateNewestPhoto\0updateFireEventsPicRelatives\0"
    "const PicList*\0openCountDownWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonitorImpl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,
       7,    2,   52,    2, 0x06 /* Public */,
       9,    2,   57,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    2,    2,

       0        // eod
};

void MonitorImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MonitorImpl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayMsg((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->updateTraps(); break;
        case 2: _t->updateFireEvents(); break;
        case 3: _t->updateNewestPhoto((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->updateFireEventsPicRelatives((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< const PicList*(*)>(_a[2]))); break;
        case 5: _t->openCountDownWindow((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MonitorImpl::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorImpl::displayMsg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MonitorImpl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorImpl::updateTraps)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MonitorImpl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorImpl::updateFireEvents)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MonitorImpl::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorImpl::updateNewestPhoto)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MonitorImpl::*)(std::string , const PicList * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorImpl::updateFireEventsPicRelatives)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MonitorImpl::*)(std::string , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorImpl::openCountDownWindow)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MonitorImpl::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MonitorImpl.data,
    qt_meta_data_MonitorImpl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MonitorImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonitorImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonitorImpl.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "SRIO_Monitor::Monitor"))
        return static_cast< SRIO_Monitor::Monitor*>(this);
    return QObject::qt_metacast(_clname);
}

int MonitorImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MonitorImpl::displayMsg(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MonitorImpl::updateTraps()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MonitorImpl::updateFireEvents()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MonitorImpl::updateNewestPhoto(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MonitorImpl::updateFireEventsPicRelatives(std::string _t1, const PicList * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MonitorImpl::openCountDownWindow(std::string _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
