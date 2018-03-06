/****************************************************************************
** Meta object code from reading C++ file 'inputPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/inputPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ios__InputPage_t {
    QByteArrayData data[11];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ios__InputPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ios__InputPage_t qt_meta_stringdata_ios__InputPage = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ios::InputPage"
QT_MOC_LITERAL(1, 15, 19), // "signalExcuteClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "_text"
QT_MOC_LITERAL(4, 42, 16), // "slotDigitClicked"
QT_MOC_LITERAL(5, 59, 16), // "slotPointClicked"
QT_MOC_LITERAL(6, 76, 16), // "slotMinusClicked"
QT_MOC_LITERAL(7, 93, 15), // "slotBackClicked"
QT_MOC_LITERAL(8, 109, 16), // "slotClearClicked"
QT_MOC_LITERAL(9, 126, 17), // "slotCancelClicked"
QT_MOC_LITERAL(10, 144, 17) // "slotExcuteClicked"

    },
    "ios::InputPage\0signalExcuteClicked\0\0"
    "_text\0slotDigitClicked\0slotPointClicked\0"
    "slotMinusClicked\0slotBackClicked\0"
    "slotClearClicked\0slotCancelClicked\0"
    "slotExcuteClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ios__InputPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ios::InputPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputPage *_t = static_cast<InputPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalExcuteClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slotDigitClicked(); break;
        case 2: _t->slotPointClicked(); break;
        case 3: _t->slotMinusClicked(); break;
        case 4: _t->slotBackClicked(); break;
        case 5: _t->slotClearClicked(); break;
        case 6: _t->slotCancelClicked(); break;
        case 7: _t->slotExcuteClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (InputPage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputPage::signalExcuteClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ios::InputPage::staticMetaObject = {
    { &BaseWidget::staticMetaObject, qt_meta_stringdata_ios__InputPage.data,
      qt_meta_data_ios__InputPage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ios::InputPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ios::InputPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ios__InputPage.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int ios::InputPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ios::InputPage::signalExcuteClicked(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
