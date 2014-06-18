/****************************************************************************
** Meta object code from reading C++ file 'datathread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FabricGenerator/datathread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datathread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataThread_t {
    QByteArrayData data[15];
    char stringdata[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataThread_t qt_meta_stringdata_DataThread = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 8),
QT_MOC_LITERAL(4, 43, 8),
QT_MOC_LITERAL(5, 52, 17),
QT_MOC_LITERAL(6, 70, 3),
QT_MOC_LITERAL(7, 74, 10),
QT_MOC_LITERAL(8, 85, 4),
QT_MOC_LITERAL(9, 90, 4),
QT_MOC_LITERAL(10, 95, 14),
QT_MOC_LITERAL(11, 110, 5),
QT_MOC_LITERAL(12, 116, 15),
QT_MOC_LITERAL(13, 132, 4),
QT_MOC_LITERAL(14, 137, 17)
    },
    "DataThread\0pageData_loadComplete\0\0"
    "pageData\0totalNum\0imageLoadedSignal\0"
    "num\0loadByPage\0page\0read\0QNetworkReply*\0"
    "reply\0loadImageByList\0list\0imageLoadComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   52,    2, 0x0a /* Public */,
       9,    1,   55,    2, 0x0a /* Public */,
      12,    1,   58,    2, 0x0a /* Public */,
      14,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantList, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QStringList,   13,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void DataThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataThread *_t = static_cast<DataThread *>(_o);
        switch (_id) {
        case 0: _t->pageData_loadComplete((*reinterpret_cast< QList<QVariant>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->imageLoadedSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->loadByPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->read((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->loadImageByList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->imageLoadComplete((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataThread::*_t)(QList<QVariant> , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataThread::pageData_loadComplete)) {
                *result = 0;
            }
        }
        {
            typedef void (DataThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataThread::imageLoadedSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DataThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DataThread.data,
      qt_meta_data_DataThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *DataThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataThread.stringdata))
        return static_cast<void*>(const_cast< DataThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DataThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void DataThread::pageData_loadComplete(QList<QVariant> _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataThread::imageLoadedSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
