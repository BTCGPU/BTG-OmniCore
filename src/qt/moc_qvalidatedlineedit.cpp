/****************************************************************************
** Meta object code from reading C++ file 'qvalidatedlineedit.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/qvalidatedlineedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qvalidatedlineedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QValidatedLineEdit[] = {

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
      38,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,   79,   19,   19, 0x0a,
     108,  100,   19,   19, 0x0a,
     125,   19,   19,   19, 0x08,
     137,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QValidatedLineEdit[] = {
    "QValidatedLineEdit\0\0validatedLineEdit\0"
    "validationDidChange(QValidatedLineEdit*)\0"
    "valid\0setValid(bool)\0enabled\0"
    "setEnabled(bool)\0markValid()\0"
    "checkValidity()\0"
};

void QValidatedLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QValidatedLineEdit *_t = static_cast<QValidatedLineEdit *>(_o);
        switch (_id) {
        case 0: _t->validationDidChange((*reinterpret_cast< QValidatedLineEdit*(*)>(_a[1]))); break;
        case 1: _t->setValid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->markValid(); break;
        case 4: _t->checkValidity(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QValidatedLineEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QValidatedLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_QValidatedLineEdit,
      qt_meta_data_QValidatedLineEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QValidatedLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QValidatedLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QValidatedLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QValidatedLineEdit))
        return static_cast<void*>(const_cast< QValidatedLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int QValidatedLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
void QValidatedLineEdit::validationDidChange(QValidatedLineEdit * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
