/****************************************************************************
** Meta object code from reading C++ file 'receivecoinsdialog.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/receivecoinsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receivecoinsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReceiveCoinsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      28,   19,   19,   19, 0x0a,
      37,   19,   19,   19, 0x0a,
      46,   19,   19,   19, 0x08,
      73,   19,   19,   19, 0x08,
     104,   19,   19,   19, 0x08,
     143,  137,   19,   19, 0x08,
     212,  192,   19,   19, 0x08,
     279,   19,   19,   19, 0x08,
     305,  299,   19,   19, 0x08,
     322,   19,   19,   19, 0x08,
     332,   19,   19,   19, 0x08,
     344,   19,   19,   19, 0x08,
     358,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ReceiveCoinsDialog[] = {
    "ReceiveCoinsDialog\0\0clear()\0reject()\0"
    "accept()\0on_receiveButton_clicked()\0"
    "on_showRequestButton_clicked()\0"
    "on_removeRequestButton_clicked()\0index\0"
    "on_recentRequestsView_doubleClicked(QModelIndex)\0"
    "selected,deselected\0"
    "recentRequestsView_selectionChanged(QItemSelection,QItemSelection)\0"
    "updateDisplayUnit()\0point\0showMenu(QPoint)\0"
    "copyURI()\0copyLabel()\0copyMessage()\0"
    "copyAmount()\0"
};

void ReceiveCoinsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ReceiveCoinsDialog *_t = static_cast<ReceiveCoinsDialog *>(_o);
        switch (_id) {
        case 0: _t->clear(); break;
        case 1: _t->reject(); break;
        case 2: _t->accept(); break;
        case 3: _t->on_receiveButton_clicked(); break;
        case 4: _t->on_showRequestButton_clicked(); break;
        case 5: _t->on_removeRequestButton_clicked(); break;
        case 6: _t->on_recentRequestsView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->recentRequestsView_selectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 8: _t->updateDisplayUnit(); break;
        case 9: _t->showMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 10: _t->copyURI(); break;
        case 11: _t->copyLabel(); break;
        case 12: _t->copyMessage(); break;
        case 13: _t->copyAmount(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ReceiveCoinsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ReceiveCoinsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ReceiveCoinsDialog,
      qt_meta_data_ReceiveCoinsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReceiveCoinsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReceiveCoinsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReceiveCoinsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReceiveCoinsDialog))
        return static_cast<void*>(const_cast< ReceiveCoinsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ReceiveCoinsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
