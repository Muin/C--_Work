/****************************************************************************
** Meta object code from reading C++ file 'user_interface.h'
**
** Created: Thu Feb 14 13:32:29 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "user_interface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_User_Interface[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x05,
      50,   41,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   15,   15,   15, 0x0a,
      80,   15,   15,   15, 0x0a,
      88,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_User_Interface[] = {
    "User_Interface\0\0Points\0PointsChange(int)\0"
    "numLines\0RowsRemoveChange(int)\0start()\0"
    "pause()\0autoplay()\0"
};

const QMetaObject User_Interface::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_User_Interface,
      qt_meta_data_User_Interface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &User_Interface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *User_Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *User_Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_User_Interface))
        return static_cast<void*>(const_cast< User_Interface*>(this));
    if (!strcmp(_clname, "Board"))
        return static_cast< Board*>(const_cast< User_Interface*>(this));
    if (!strcmp(_clname, "IPlayer"))
        return static_cast< IPlayer*>(const_cast< User_Interface*>(this));
    return QFrame::qt_metacast(_clname);
}

int User_Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: PointsChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: RowsRemoveChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: start(); break;
        case 3: pause(); break;
        case 4: autoplay(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void User_Interface::PointsChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void User_Interface::RowsRemoveChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
