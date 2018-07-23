/****************************************************************************
** Meta object code from reading C++ file 'modaloverlay.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/modaloverlay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modaloverlay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModalOverlay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      52,   14,   13,   13, 0x0a,
     100,   84,   13,   13, 0x0a,
     134,   13,   13,   13, 0x0a,
     172,  153,   13,   13, 0x0a,
     197,  192,   13,   13, 0x2a,
     212,   13,   13,   13, 0x2a,
     223,   13,   13,   13, 0x0a,
     243,   13,  238,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ModalOverlay[] = {
    "ModalOverlay\0\0count,blockDate,nVerificationProgress\0"
    "tipUpdate(int,QDateTime,double)\0"
    "count,blockDate\0setKnownBestHeight(int,QDateTime)\0"
    "toggleVisibility()\0hide,userRequested\0"
    "showHide(bool,bool)\0hide\0showHide(bool)\0"
    "showHide()\0closeClicked()\0bool\0"
    "isLayerVisible()\0"
};

void ModalOverlay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModalOverlay *_t = static_cast<ModalOverlay *>(_o);
        switch (_id) {
        case 0: _t->tipUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: _t->setKnownBestHeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2]))); break;
        case 2: _t->toggleVisibility(); break;
        case 3: _t->showHide((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->showHide((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->showHide(); break;
        case 6: _t->closeClicked(); break;
        case 7: { bool _r = _t->isLayerVisible();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModalOverlay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModalOverlay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ModalOverlay,
      qt_meta_data_ModalOverlay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModalOverlay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModalOverlay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModalOverlay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModalOverlay))
        return static_cast<void*>(const_cast< ModalOverlay*>(this));
    return QWidget::qt_metacast(_clname);
}

int ModalOverlay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
