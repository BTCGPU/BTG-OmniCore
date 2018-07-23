/****************************************************************************
** Meta object code from reading C++ file 'sendcoinsdialog.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/sendcoinsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sendcoinsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SendCoinsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      37,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   16,   16,   16, 0x0a,
      75,   16,   16,   16, 0x0a,
      84,   16,   16,   16, 0x0a,
     109,   16,   93,   16, 0x0a,
     120,   16,   16,   16, 0x0a,
     242,  142,   16,   16, 0x0a,
     302,   16,   16,   16, 0x08,
     326,   16,   16,   16, 0x08,
     355,   16,   16,   16, 0x08,
     392,  386,   16,   16, 0x08,
     421,   16,   16,   16, 0x08,
     441,   16,   16,   16, 0x08,
     473,   16,   16,   16, 0x08,
     500,   16,   16,   16, 0x08,
     530,   16,   16,   16, 0x08,
     563,   16,   16,   16, 0x08,
     589,   16,   16,   16, 0x08,
     620,   16,   16,   16, 0x08,
     649,   16,   16,   16, 0x08,
     675,   16,   16,   16, 0x08,
     706,   16,   16,   16, 0x08,
     734,   16,   16,   16, 0x08,
     766,   16,   16,   16, 0x08,
     795,   16,   16,   16, 0x08,
     811,   16,   16,   16, 0x08,
     838,   16,   16,   16, 0x08,
     858,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SendCoinsDialog[] = {
    "SendCoinsDialog\0\0title,message,style\0"
    "message(QString,QString,uint)\0clear()\0"
    "reject()\0accept()\0SendCoinsEntry*\0"
    "addEntry()\0updateTabsAndLabels()\0"
    "balance,unconfirmedBalance,immatureBalance,watchOnlyBalance,watchUncon"
    "fBalance,watchImmatureBalance\0"
    "setBalance(CAmount,CAmount,CAmount,CAmount,CAmount,CAmount)\0"
    "on_sendButton_clicked()\0"
    "on_buttonChooseFee_clicked()\0"
    "on_buttonMinimizeFee_clicked()\0entry\0"
    "removeEntry(SendCoinsEntry*)\0"
    "updateDisplayUnit()\0coinControlFeatureChanged(bool)\0"
    "coinControlButtonClicked()\0"
    "coinControlChangeChecked(int)\0"
    "coinControlChangeEdited(QString)\0"
    "coinControlUpdateLabels()\0"
    "coinControlClipboardQuantity()\0"
    "coinControlClipboardAmount()\0"
    "coinControlClipboardFee()\0"
    "coinControlClipboardAfterFee()\0"
    "coinControlClipboardBytes()\0"
    "coinControlClipboardLowOutput()\0"
    "coinControlClipboardChange()\0"
    "setMinimumFee()\0updateFeeSectionControls()\0"
    "updateMinFeeLabel()\0updateSmartFeeLabel()\0"
};

void SendCoinsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SendCoinsDialog *_t = static_cast<SendCoinsDialog *>(_o);
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 1: _t->clear(); break;
        case 2: _t->reject(); break;
        case 3: _t->accept(); break;
        case 4: { SendCoinsEntry* _r = _t->addEntry();
            if (_a[0]) *reinterpret_cast< SendCoinsEntry**>(_a[0]) = _r; }  break;
        case 5: _t->updateTabsAndLabels(); break;
        case 6: _t->setBalance((*reinterpret_cast< const CAmount(*)>(_a[1])),(*reinterpret_cast< const CAmount(*)>(_a[2])),(*reinterpret_cast< const CAmount(*)>(_a[3])),(*reinterpret_cast< const CAmount(*)>(_a[4])),(*reinterpret_cast< const CAmount(*)>(_a[5])),(*reinterpret_cast< const CAmount(*)>(_a[6]))); break;
        case 7: _t->on_sendButton_clicked(); break;
        case 8: _t->on_buttonChooseFee_clicked(); break;
        case 9: _t->on_buttonMinimizeFee_clicked(); break;
        case 10: _t->removeEntry((*reinterpret_cast< SendCoinsEntry*(*)>(_a[1]))); break;
        case 11: _t->updateDisplayUnit(); break;
        case 12: _t->coinControlFeatureChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->coinControlButtonClicked(); break;
        case 14: _t->coinControlChangeChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->coinControlChangeEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->coinControlUpdateLabels(); break;
        case 17: _t->coinControlClipboardQuantity(); break;
        case 18: _t->coinControlClipboardAmount(); break;
        case 19: _t->coinControlClipboardFee(); break;
        case 20: _t->coinControlClipboardAfterFee(); break;
        case 21: _t->coinControlClipboardBytes(); break;
        case 22: _t->coinControlClipboardLowOutput(); break;
        case 23: _t->coinControlClipboardChange(); break;
        case 24: _t->setMinimumFee(); break;
        case 25: _t->updateFeeSectionControls(); break;
        case 26: _t->updateMinFeeLabel(); break;
        case 27: _t->updateSmartFeeLabel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SendCoinsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SendCoinsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SendCoinsDialog,
      qt_meta_data_SendCoinsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SendCoinsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SendCoinsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SendCoinsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SendCoinsDialog))
        return static_cast<void*>(const_cast< SendCoinsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SendCoinsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void SendCoinsDialog::message(const QString & _t1, const QString & _t2, unsigned int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_SendConfirmationDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,
      36,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SendConfirmationDialog[] = {
    "SendConfirmationDialog\0\0countDown()\0"
    "updateYesButton()\0"
};

void SendConfirmationDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SendConfirmationDialog *_t = static_cast<SendConfirmationDialog *>(_o);
        switch (_id) {
        case 0: _t->countDown(); break;
        case 1: _t->updateYesButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SendConfirmationDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SendConfirmationDialog::staticMetaObject = {
    { &QMessageBox::staticMetaObject, qt_meta_stringdata_SendConfirmationDialog,
      qt_meta_data_SendConfirmationDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SendConfirmationDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SendConfirmationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SendConfirmationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SendConfirmationDialog))
        return static_cast<void*>(const_cast< SendConfirmationDialog*>(this));
    return QMessageBox::qt_metacast(_clname);
}

int SendConfirmationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMessageBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
