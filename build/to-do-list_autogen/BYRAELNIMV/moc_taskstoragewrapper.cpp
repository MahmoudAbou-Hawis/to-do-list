/****************************************************************************
** Meta object code from reading C++ file 'taskstoragewrapper.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/src/wrappers/taskstoragewrapper.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskstoragewrapper.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaskStorageWrapper_t {
    QByteArrayData data[17];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskStorageWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskStorageWrapper_t qt_meta_stringdata_TaskStorageWrapper = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TaskStorageWrapper"
QT_MOC_LITERAL(1, 19, 8), // "makeTask"
QT_MOC_LITERAL(2, 28, 11), // "TaskWrapper"
QT_MOC_LITERAL(3, 40, 0), // ""
QT_MOC_LITERAL(4, 41, 4), // "name"
QT_MOC_LITERAL(5, 46, 9), // "completed"
QT_MOC_LITERAL(6, 56, 6), // "status"
QT_MOC_LITERAL(7, 63, 13), // "originalIndex"
QT_MOC_LITERAL(8, 77, 5), // "notes"
QT_MOC_LITERAL(9, 83, 5), // "email"
QT_MOC_LITERAL(10, 89, 4), // "date"
QT_MOC_LITERAL(11, 94, 4), // "time"
QT_MOC_LITERAL(12, 99, 7), // "addTask"
QT_MOC_LITERAL(13, 107, 4), // "task"
QT_MOC_LITERAL(14, 112, 10), // "removeTask"
QT_MOC_LITERAL(15, 123, 10), // "updateTask"
QT_MOC_LITERAL(16, 134, 11) // "getAllTasks"

    },
    "TaskStorageWrapper\0makeTask\0TaskWrapper\0"
    "\0name\0completed\0status\0originalIndex\0"
    "notes\0email\0date\0time\0addTask\0task\0"
    "removeTask\0updateTask\0getAllTasks"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskStorageWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    8,   39,    3, 0x02 /* Public */,
      12,    1,   56,    3, 0x02 /* Public */,
      14,    1,   59,    3, 0x02 /* Public */,
      15,    1,   62,    3, 0x02 /* Public */,
      16,    0,   65,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,    8,    9,   10,   11,
    QMetaType::Bool, 0x80000000 | 2,   13,
    QMetaType::Bool, 0x80000000 | 2,   13,
    QMetaType::Bool, 0x80000000 | 2,   13,
    QMetaType::QVariantList,

       0        // eod
};

void TaskStorageWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TaskStorageWrapper *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { TaskWrapper _r = _t->makeTask((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< TaskWrapper*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->addTask((*reinterpret_cast< TaskWrapper(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->removeTask((*reinterpret_cast< TaskWrapper(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->updateTask((*reinterpret_cast< TaskWrapper(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVariantList _r = _t->getAllTasks();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaskWrapper >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaskWrapper >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaskWrapper >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TaskStorageWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TaskStorageWrapper.data,
    qt_meta_data_TaskStorageWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TaskStorageWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskStorageWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TaskStorageWrapper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TaskStorageWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
