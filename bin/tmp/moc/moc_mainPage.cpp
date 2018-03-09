/****************************************************************************
** Meta object code from reading C++ file 'mainPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/mainPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ios__MainPage_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ios__MainPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ios__MainPage_t qt_meta_stringdata_ios__MainPage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ios::MainPage"
QT_MOC_LITERAL(1, 14, 15), // "slotPageChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5) // "_page"

    },
    "ios::MainPage\0slotPageChanged\0\0_page"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ios__MainPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void ios::MainPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainPage *_t = static_cast<MainPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotPageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ios::MainPage::staticMetaObject = {
    { &BaseWidget::staticMetaObject, qt_meta_stringdata_ios__MainPage.data,
      qt_meta_data_ios__MainPage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ios::MainPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ios::MainPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ios__MainPage.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int ios::MainPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
