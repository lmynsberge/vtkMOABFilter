/****************************************************************************
** Meta object code from reading C++ file 'MyToolBarActions.h'
**
** Created: Sun Mar 10 21:09:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyToolBarActions.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyToolBarActions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyToolBarActions[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyToolBarActions[] = {
    "MyToolBarActions\0\0onAction()\0"
};

void MyToolBarActions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyToolBarActions *_t = static_cast<MyToolBarActions *>(_o);
        switch (_id) {
        case 0: _t->onAction(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyToolBarActions::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyToolBarActions::staticMetaObject = {
    { &QActionGroup::staticMetaObject, qt_meta_stringdata_MyToolBarActions,
      qt_meta_data_MyToolBarActions, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyToolBarActions::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyToolBarActions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyToolBarActions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyToolBarActions))
        return static_cast<void*>(const_cast< MyToolBarActions*>(this));
    return QActionGroup::qt_metacast(_clname);
}

int MyToolBarActions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QActionGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
