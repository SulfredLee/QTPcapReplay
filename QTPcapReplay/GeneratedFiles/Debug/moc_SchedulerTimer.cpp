/****************************************************************************
** Meta object code from reading C++ file 'SchedulerTimer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SchedulerTimer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SchedulerTimer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SchedulerTimer_t {
    QByteArrayData data[10];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SchedulerTimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SchedulerTimer_t qt_meta_stringdata_SchedulerTimer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SchedulerTimer"
QT_MOC_LITERAL(1, 15, 8), // "setTimer"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "date"
QT_MOC_LITERAL(4, 30, 4), // "time"
QT_MOC_LITERAL(5, 35, 13), // "QVector<bool>"
QT_MOC_LITERAL(6, 49, 15), // "weeklySelection"
QT_MOC_LITERAL(7, 65, 8), // "isWeekly"
QT_MOC_LITERAL(8, 74, 9), // "isOneTime"
QT_MOC_LITERAL(9, 84, 17) // "ReStartForNextDay"

    },
    "SchedulerTimer\0setTimer\0\0date\0time\0"
    "QVector<bool>\0weeklySelection\0isWeekly\0"
    "isOneTime\0ReStartForNextDay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SchedulerTimer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,   24,    2, 0x0a /* Public */,
       9,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate, QMetaType::QTime, 0x80000000 | 5, QMetaType::Bool, QMetaType::Bool,    3,    4,    6,    7,    8,
    QMetaType::Void,

       0        // eod
};

void SchedulerTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SchedulerTimer *_t = static_cast<SchedulerTimer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTimer((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QTime(*)>(_a[2])),(*reinterpret_cast< const QVector<bool>(*)>(_a[3])),(*reinterpret_cast< const bool(*)>(_a[4])),(*reinterpret_cast< const bool(*)>(_a[5]))); break;
        case 1: _t->ReStartForNextDay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<bool> >(); break;
            }
            break;
        }
    }
}

const QMetaObject SchedulerTimer::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SchedulerTimer.data,
      qt_meta_data_SchedulerTimer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SchedulerTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SchedulerTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SchedulerTimer.stringdata0))
        return static_cast<void*>(const_cast< SchedulerTimer*>(this));
    return QThread::qt_metacast(_clname);
}

int SchedulerTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
