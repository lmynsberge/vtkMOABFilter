/****************************************************************************
** Meta object code from reading C++ file 'modelwidget.h'
**
** Created: Sun Mar 10 23:58:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modelwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModelWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   12,   12,   12, 0x0a,
      90,   66,   12,   12, 0x0a,
     124,   12,   12,   12, 0x0a,
     136,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ModelWidget[] = {
    "ModelWidget\0\0selected\0"
    "selectionChanged(QItemSelection)\0"
    "addEntry()\0volume,material,density\0"
    "addEntry(QString,QString,QString)\0"
    "editEntry()\0removeEntry()\0"
};

void ModelWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModelWidget *_t = static_cast<ModelWidget *>(_o);
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 1: _t->addEntry(); break;
        case 2: _t->addEntry((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->editEntry(); break;
        case 4: _t->removeEntry(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModelWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModelWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_ModelWidget,
      qt_meta_data_ModelWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModelWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModelWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelWidget))
        return static_cast<void*>(const_cast< ModelWidget*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int ModelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ModelWidget::selectionChanged(const QItemSelection & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
