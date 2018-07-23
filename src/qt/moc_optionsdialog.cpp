/****************************************************************************
** Meta object code from reading C++ file 'optionsdialog.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/optionsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProxyAddressValidator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ProxyAddressValidator[] = {
    "ProxyAddressValidator\0"
};

void ProxyAddressValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ProxyAddressValidator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProxyAddressValidator::staticMetaObject = {
    { &QValidator::staticMetaObject, qt_meta_stringdata_ProxyAddressValidator,
      qt_meta_data_ProxyAddressValidator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProxyAddressValidator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProxyAddressValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProxyAddressValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProxyAddressValidator))
        return static_cast<void*>(const_cast< ProxyAddressValidator*>(this));
    return QValidator::qt_metacast(_clname);
}

int ProxyAddressValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QValidator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_OptionsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      37,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,   76,   14,   14, 0x08,
     106,   14,   14,   14, 0x08,
     131,   14,   14,   14, 0x08,
     166,   14,   14,   14, 0x08,
     188,   14,   14,   14, 0x08,
     214,   76,   14,   14, 0x08,
     260,  248,   14,   14, 0x08,
     285,   14,   14,   14, 0x28,
     306,   14,   14,   14, 0x08,
     325,   14,   14,   14, 0x08,
     354,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OptionsDialog[] = {
    "OptionsDialog\0\0pUiProxyIp,nProxyPort\0"
    "proxyIpChecks(QValidatedLineEdit*,int)\0"
    "fState\0setOkButtonState(bool)\0"
    "on_resetButton_clicked()\0"
    "on_openBitcoinConfButton_clicked()\0"
    "on_okButton_clicked()\0on_cancelButton_clicked()\0"
    "on_hideTrayIcon_stateChanged(int)\0"
    "fPersistent\0showRestartWarning(bool)\0"
    "showRestartWarning()\0clearStatusLabel()\0"
    "updateProxyValidationState()\0"
    "updateDefaultProxyNets()\0"
};

void OptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OptionsDialog *_t = static_cast<OptionsDialog *>(_o);
        switch (_id) {
        case 0: _t->proxyIpChecks((*reinterpret_cast< QValidatedLineEdit*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setOkButtonState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_resetButton_clicked(); break;
        case 3: _t->on_openBitcoinConfButton_clicked(); break;
        case 4: _t->on_okButton_clicked(); break;
        case 5: _t->on_cancelButton_clicked(); break;
        case 6: _t->on_hideTrayIcon_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->showRestartWarning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->showRestartWarning(); break;
        case 9: _t->clearStatusLabel(); break;
        case 10: _t->updateProxyValidationState(); break;
        case 11: _t->updateDefaultProxyNets(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OptionsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OptionsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionsDialog,
      qt_meta_data_OptionsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OptionsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsDialog))
        return static_cast<void*>(const_cast< OptionsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void OptionsDialog::proxyIpChecks(QValidatedLineEdit * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
