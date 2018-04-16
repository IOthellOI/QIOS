/****************************************************************************
** Meta object code from reading C++ file 'externalData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/data/externalData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'externalData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExternalData_t {
    QByteArrayData data[5];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExternalData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExternalData_t qt_meta_stringdata_ExternalData = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ExternalData"
QT_MOC_LITERAL(1, 13, 16), // "signalDataUpdate"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "_value"
QT_MOC_LITERAL(4, 38, 14) // "slotDataUpdate"

    },
    "ExternalData\0signalDataUpdate\0\0_value\0"
    "slotDataUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExternalData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       1,    1,   67,    2, 0x06 /* Public */,
       1,    1,   70,    2, 0x06 /* Public */,
       1,    1,   73,    2, 0x06 /* Public */,
       1,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   79,    2, 0x0a /* Public */,
       4,    1,   82,    2, 0x0a /* Public */,
       4,    1,   85,    2, 0x0a /* Public */,
       4,    1,   88,    2, 0x0a /* Public */,
       4,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Double,    3,

       0        // eod
};

void ExternalData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExternalData *_t = static_cast<ExternalData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalDataUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->signalDataUpdate((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 2: _t->signalDataUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalDataUpdate((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->signalDataUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->slotDataUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->slotDataUpdate((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 7: _t->slotDataUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotDataUpdate((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->slotDataUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ExternalData::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExternalData::signalDataUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ExternalData::*_t)(unsigned short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExternalData::signalDataUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ExternalData::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExternalData::signalDataUpdate)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ExternalData::*_t)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExternalData::signalDataUpdate)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ExternalData::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExternalData::signalDataUpdate)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject ExternalData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ExternalData.data,
      qt_meta_data_ExternalData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ExternalData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExternalData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExternalData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ExternalData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ExternalData::signalDataUpdate(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExternalData::signalDataUpdate(unsigned short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ExternalData::signalDataUpdate(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ExternalData::signalDataUpdate(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ExternalData::signalDataUpdate(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
