/****************************************************************************
** Meta object code from reading C++ file 'navigation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/navigation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navigation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ios__Navigation_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ios__Navigation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ios__Navigation_t qt_meta_stringdata_ios__Navigation = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ios::Navigation"
QT_MOC_LITERAL(1, 16, 17), // "signalPageChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "_page"
QT_MOC_LITERAL(4, 41, 15) // "slotPageChanged"

    },
    "ios::Navigation\0signalPageChanged\0\0"
    "_page\0slotPageChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ios__Navigation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void ios::Navigation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Navigation *_t = static_cast<Navigation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalPageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slotPageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Navigation::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Navigation::signalPageChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ios::Navigation::staticMetaObject = {
    { &BaseWidget::staticMetaObject, qt_meta_stringdata_ios__Navigation.data,
      qt_meta_data_ios__Navigation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ios::Navigation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ios::Navigation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ios__Navigation.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int ios::Navigation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ios::Navigation::signalPageChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
