/****************************************************************************
** Meta object code from reading C++ file 'taskwrapper.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/src/wrappers/taskwrapper.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskwrapper.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaskWrapper_t {
    QByteArrayData data[9];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskWrapper_t qt_meta_stringdata_TaskWrapper = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TaskWrapper"
QT_MOC_LITERAL(1, 12, 4), // "name"
QT_MOC_LITERAL(2, 17, 7), // "checked"
QT_MOC_LITERAL(3, 25, 7), // "deleted"
QT_MOC_LITERAL(4, 33, 13), // "originalIndex"
QT_MOC_LITERAL(5, 47, 5), // "notes"
QT_MOC_LITERAL(6, 53, 5), // "email"
QT_MOC_LITERAL(7, 59, 4), // "date"
QT_MOC_LITERAL(8, 64, 4) // "time"

    },
    "TaskWrapper\0name\0checked\0deleted\0"
    "originalIndex\0notes\0email\0date\0time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       8,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095401,
       2, QMetaType::Bool, 0x00095401,
       3, QMetaType::Bool, 0x00095401,
       4, QMetaType::Int, 0x00095401,
       5, QMetaType::QString, 0x00095401,
       6, QMetaType::QString, 0x00095401,
       7, QMetaType::QString, 0x00095401,
       8, QMetaType::QString, 0x00095401,

       0        // eod
};

void TaskWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<TaskWrapper *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getName(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getChecked(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getDeleted(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getOriginalIndex(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getNotes(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getEmail(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->getDate(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->getTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject TaskWrapper::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_TaskWrapper.data,
    qt_meta_data_TaskWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };

QT_WARNING_POP
QT_END_MOC_NAMESPACE
