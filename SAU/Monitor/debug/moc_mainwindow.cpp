/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[359];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "displayMsg"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "std::string"
QT_MOC_LITERAL(4, 35, 19), // "updateTrapsListView"
QT_MOC_LITERAL(5, 55, 24), // "updateUnitsStateListView"
QT_MOC_LITERAL(6, 80, 24), // "updateFireEventsListView"
QT_MOC_LITERAL(7, 105, 29), // "displayNewestPictureRelatives"
QT_MOC_LITERAL(8, 135, 14), // "const PicList*"
QT_MOC_LITERAL(9, 150, 18), // "displayNewestPhoto"
QT_MOC_LITERAL(10, 169, 19), // "openCountDownWindow"
QT_MOC_LITERAL(11, 189, 28), // "on_fireEventListView_clicked"
QT_MOC_LITERAL(12, 218, 11), // "QModelIndex"
QT_MOC_LITERAL(13, 230, 5), // "index"
QT_MOC_LITERAL(14, 236, 43), // "on_firePicsListComboBox_curre..."
QT_MOC_LITERAL(15, 280, 4), // "arg1"
QT_MOC_LITERAL(16, 285, 27), // "on_newWinPushButton_clicked"
QT_MOC_LITERAL(17, 313, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(18, 335, 23) // "on_pushButton_2_clicked"

    },
    "MainWindow\0displayMsg\0\0std::string\0"
    "updateTrapsListView\0updateUnitsStateListView\0"
    "updateFireEventsListView\0"
    "displayNewestPictureRelatives\0"
    "const PicList*\0displayNewestPhoto\0"
    "openCountDownWindow\0on_fireEventListView_clicked\0"
    "QModelIndex\0index\0"
    "on_firePicsListComboBox_currentIndexChanged\0"
    "arg1\0on_newWinPushButton_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    0,   77,    2, 0x0a /* Public */,
       5,    0,   78,    2, 0x0a /* Public */,
       6,    0,   79,    2, 0x0a /* Public */,
       7,    2,   80,    2, 0x0a /* Public */,
       9,    1,   85,    2, 0x0a /* Public */,
      10,    2,   88,    2, 0x0a /* Public */,
      11,    1,   93,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,
      17,    0,  100,    2, 0x08 /* Private */,
      18,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    2,    2,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayMsg((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->updateTrapsListView(); break;
        case 2: _t->updateUnitsStateListView(); break;
        case 3: _t->updateFireEventsListView(); break;
        case 4: _t->displayNewestPictureRelatives((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< const PicList*(*)>(_a[2]))); break;
        case 5: _t->displayNewestPhoto((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->openCountDownWindow((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 7: _t->on_fireEventListView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_firePicsListComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_newWinPushButton_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
