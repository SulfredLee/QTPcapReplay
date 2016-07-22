/****************************************************************************
** Meta object code from reading C++ file 'qtpcapreplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtpcapreplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtpcapreplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_JobReplay_t {
    QByteArrayData data[14];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JobReplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JobReplay_t qt_meta_stringdata_JobReplay = {
    {
QT_MOC_LITERAL(0, 0, 9), // "JobReplay"
QT_MOC_LITERAL(1, 10, 14), // "updateProgress"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "progress"
QT_MOC_LITERAL(4, 35, 22), // "updateNextPacketNumber"
QT_MOC_LITERAL(5, 58, 4), // "line"
QT_MOC_LITERAL(6, 63, 24), // "updateCurrentPlayingFile"
QT_MOC_LITERAL(7, 88, 19), // "updatePlayingStatus"
QT_MOC_LITERAL(8, 108, 8), // "inStatus"
QT_MOC_LITERAL(9, 117, 28), // "updateRegularReplayingStatus"
QT_MOC_LITERAL(10, 146, 14), // "sendMessageBox"
QT_MOC_LITERAL(11, 161, 27), // "sendUpdateRegularButtonText"
QT_MOC_LITERAL(12, 189, 11), // "StartReplay"
QT_MOC_LITERAL(13, 201, 18) // "startRegularReplay"

    },
    "JobReplay\0updateProgress\0\0progress\0"
    "updateNextPacketNumber\0line\0"
    "updateCurrentPlayingFile\0updatePlayingStatus\0"
    "inStatus\0updateRegularReplayingStatus\0"
    "sendMessageBox\0sendUpdateRegularButtonText\0"
    "StartReplay\0startRegularReplay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JobReplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       7,    1,   68,    2, 0x06 /* Public */,
       9,    1,   71,    2, 0x06 /* Public */,
      10,    1,   74,    2, 0x06 /* Public */,
      11,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   80,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void JobReplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JobReplay *_t = static_cast<JobReplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgress((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->updateNextPacketNumber((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateCurrentPlayingFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->updatePlayingStatus((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->updateRegularReplayingStatus((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 5: _t->sendMessageBox((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->sendUpdateRegularButtonText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->StartReplay(); break;
        case 8: _t->startRegularReplay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (JobReplay::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JobReplay::updateProgress)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (JobReplay::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JobReplay::updateNextPacketNumber)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (JobReplay::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JobReplay::updateCurrentPlayingFile)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (JobReplay::*_t)(const bool & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JobReplay::updatePlayingStatus)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (JobReplay::*_t)(const bool & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JobReplay::updateRegularReplayingStatus)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (JobReplay::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JobReplay::sendMessageBox)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (JobReplay::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JobReplay::sendUpdateRegularButtonText)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject JobReplay::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_JobReplay.data,
      qt_meta_data_JobReplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *JobReplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JobReplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_JobReplay.stringdata0))
        return static_cast<void*>(const_cast< JobReplay*>(this));
    return QThread::qt_metacast(_clname);
}

int JobReplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void JobReplay::updateProgress(const int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JobReplay::updateNextPacketNumber(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JobReplay::updateCurrentPlayingFile(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JobReplay::updatePlayingStatus(const bool & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JobReplay::updateRegularReplayingStatus(const bool & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JobReplay::sendMessageBox(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void JobReplay::sendUpdateRegularButtonText(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
struct qt_meta_stringdata_QTPcapReplay_t {
    QByteArrayData data[29];
    char stringdata0[411];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTPcapReplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTPcapReplay_t qt_meta_stringdata_QTPcapReplay = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QTPcapReplay"
QT_MOC_LITERAL(1, 13, 10), // "onFileOpen"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "onItemActivated"
QT_MOC_LITERAL(4, 41, 10), // "onFileExit"
QT_MOC_LITERAL(5, 52, 12), // "onFolderOpen"
QT_MOC_LITERAL(6, 65, 7), // "onPause"
QT_MOC_LITERAL(7, 73, 10), // "removeFile"
QT_MOC_LITERAL(8, 84, 11), // "onNewWindow"
QT_MOC_LITERAL(9, 96, 18), // "onNewWindowDynamic"
QT_MOC_LITERAL(10, 115, 11), // "getProgress"
QT_MOC_LITERAL(11, 127, 8), // "progress"
QT_MOC_LITERAL(12, 136, 19), // "getNextPacketNumber"
QT_MOC_LITERAL(13, 156, 4), // "line"
QT_MOC_LITERAL(14, 161, 12), // "getCurStatus"
QT_MOC_LITERAL(15, 174, 19), // "updatePlayingStatus"
QT_MOC_LITERAL(16, 194, 8), // "bPlaying"
QT_MOC_LITERAL(17, 203, 28), // "updateRegularReplayingStatus"
QT_MOC_LITERAL(18, 232, 11), // "StopPlaying"
QT_MOC_LITERAL(19, 244, 18), // "onSchedulerDynamic"
QT_MOC_LITERAL(20, 263, 13), // "handleTimeout"
QT_MOC_LITERAL(21, 277, 21), // "updateNetSpeedMeasure"
QT_MOC_LITERAL(22, 299, 5), // "speed"
QT_MOC_LITERAL(23, 305, 15), // "PrintTimeReport"
QT_MOC_LITERAL(24, 321, 10), // "timeReport"
QT_MOC_LITERAL(25, 332, 14), // "showMessageBox"
QT_MOC_LITERAL(26, 347, 23), // "updateRegularButtonText"
QT_MOC_LITERAL(27, 371, 19), // "save_config_setting"
QT_MOC_LITERAL(28, 391, 19) // "load_config_setting"

    },
    "QTPcapReplay\0onFileOpen\0\0onItemActivated\0"
    "onFileExit\0onFolderOpen\0onPause\0"
    "removeFile\0onNewWindow\0onNewWindowDynamic\0"
    "getProgress\0progress\0getNextPacketNumber\0"
    "line\0getCurStatus\0updatePlayingStatus\0"
    "bPlaying\0updateRegularReplayingStatus\0"
    "StopPlaying\0onSchedulerDynamic\0"
    "handleTimeout\0updateNetSpeedMeasure\0"
    "speed\0PrintTimeReport\0timeReport\0"
    "showMessageBox\0updateRegularButtonText\0"
    "save_config_setting\0load_config_setting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTPcapReplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x08 /* Private */,
       3,    0,  125,    2, 0x08 /* Private */,
       4,    0,  126,    2, 0x08 /* Private */,
       5,    0,  127,    2, 0x08 /* Private */,
       6,    0,  128,    2, 0x08 /* Private */,
       7,    0,  129,    2, 0x08 /* Private */,
       8,    0,  130,    2, 0x08 /* Private */,
       9,    0,  131,    2, 0x08 /* Private */,
      10,    1,  132,    2, 0x08 /* Private */,
      12,    1,  135,    2, 0x08 /* Private */,
      14,    1,  138,    2, 0x08 /* Private */,
      15,    1,  141,    2, 0x08 /* Private */,
      17,    1,  144,    2, 0x08 /* Private */,
      18,    0,  147,    2, 0x08 /* Private */,
      19,    0,  148,    2, 0x08 /* Private */,
      20,    0,  149,    2, 0x08 /* Private */,
      21,    1,  150,    2, 0x08 /* Private */,
      23,    1,  153,    2, 0x08 /* Private */,
      25,    1,  156,    2, 0x08 /* Private */,
      26,    1,  159,    2, 0x08 /* Private */,
      27,    0,  162,    2, 0x08 /* Private */,
      28,    0,  163,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   22,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QTPcapReplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTPcapReplay *_t = static_cast<QTPcapReplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onFileOpen(); break;
        case 1: _t->onItemActivated(); break;
        case 2: _t->onFileExit(); break;
        case 3: _t->onFolderOpen(); break;
        case 4: _t->onPause(); break;
        case 5: _t->removeFile(); break;
        case 6: _t->onNewWindow(); break;
        case 7: _t->onNewWindowDynamic(); break;
        case 8: _t->getProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->getNextPacketNumber((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->getCurStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->updatePlayingStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->updateRegularReplayingStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->StopPlaying(); break;
        case 14: _t->onSchedulerDynamic(); break;
        case 15: _t->handleTimeout(); break;
        case 16: _t->updateNetSpeedMeasure((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->PrintTimeReport((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->showMessageBox((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->updateRegularButtonText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->save_config_setting(); break;
        case 21: _t->load_config_setting(); break;
        default: ;
        }
    }
}

const QMetaObject QTPcapReplay::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QTPcapReplay.data,
      qt_meta_data_QTPcapReplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QTPcapReplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTPcapReplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QTPcapReplay.stringdata0))
        return static_cast<void*>(const_cast< QTPcapReplay*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QTPcapReplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
