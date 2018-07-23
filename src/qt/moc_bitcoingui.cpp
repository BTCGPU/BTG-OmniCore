/****************************************************************************
** Meta object code from reading C++ file 'bitcoingui.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/bitcoingui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bitcoingui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BitcoinGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   37,   11,   11, 0x0a,
      80,   66,   11,   11, 0x0a,
     149,  103,   11,   11, 0x0a,
     213,  189,   11,   11, 0x0a,
     269,  249,   11,   11, 0x2a,
     306,  299,   11,   11, 0x0a,
     341,  331,   11,   11, 0x0a,
     373,  363,  358,   11, 0x0a,
     450,  414,   11,   11, 0x0a,
     515,   11,   11,   11, 0x08,
     534,   11,   11,   11, 0x08,
     552,   11,   11,   11, 0x08,
     580,  575,   11,   11, 0x08,
     607,   11,   11,   11, 0x28,
     627,  575,   11,   11, 0x08,
     655,   11,   11,   11, 0x28,
     676,  575,   11,   11, 0x08,
     706,   11,   11,   11, 0x28,
     729,   11,   11,   11, 0x08,
     743,   11,   11,   11, 0x08,
     760,   11,   11,   11, 0x08,
     775,   11,   11,   11, 0x08,
     793,   11,   11,   11, 0x08,
     826,   11,   11,   11, 0x08,
     858,  851,   11,   11, 0x08,
     925,  911,   11,   11, 0x08,
     953,   11,   11,   11, 0x28,
     977,   11,   11,   11, 0x08,
     992,   11,   11,   11, 0x08,
    1025, 1009,   11,   11, 0x08,
    1051,   11,   11,   11, 0x08,
    1076,   11,   11,   11, 0x08,
    1098,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BitcoinGUI[] = {
    "BitcoinGUI\0\0uri\0receivedURI(QString)\0"
    "count\0setNumConnections(int)\0networkActive\0"
    "setNetworkActive(bool)\0"
    "count,blockDate,nVerificationProgress,headers\0"
    "setNumBlocks(int,QDateTime,double,bool)\0"
    "title,message,style,ret\0"
    "message(QString,QString,uint,bool*)\0"
    "title,message,style\0message(QString,QString,uint)\0"
    "status\0setEncryptionStatus(int)\0"
    "hdEnabled\0setHDStatus(int)\0bool\0"
    "recipient\0handlePaymentRequest(SendCoinsRecipient)\0"
    "date,unit,amount,type,address,label\0"
    "incomingTransaction(QString,int,CAmount,QString,QString,QString)\0"
    "gotoOverviewPage()\0gotoHistoryPage()\0"
    "gotoReceiveCoinsPage()\0addr\0"
    "gotoSendCoinsPage(QString)\0"
    "gotoSendCoinsPage()\0gotoSignMessageTab(QString)\0"
    "gotoSignMessageTab()\0gotoVerifyMessageTab(QString)\0"
    "gotoVerifyMessageTab()\0openClicked()\0"
    "optionsClicked()\0aboutClicked()\0"
    "showDebugWindow()\0showDebugWindowActivateConsole()\0"
    "showHelpMessageClicked()\0reason\0"
    "trayIconActivated(QSystemTrayIcon::ActivationReason)\0"
    "fToggleHidden\0showNormalIfMinimized(bool)\0"
    "showNormalIfMinimized()\0toggleHidden()\0"
    "detectShutdown()\0title,nProgress\0"
    "showProgress(QString,int)\0"
    "setTrayIconVisible(bool)\0toggleNetworkActive()\0"
    "showModalOverlay()\0"
};

void BitcoinGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BitcoinGUI *_t = static_cast<BitcoinGUI *>(_o);
        switch (_id) {
        case 0: _t->receivedURI((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setNetworkActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setNumBlocks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 4: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< bool*(*)>(_a[4]))); break;
        case 5: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 6: _t->setEncryptionStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setHDStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { bool _r = _t->handlePaymentRequest((*reinterpret_cast< const SendCoinsRecipient(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->incomingTransaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const CAmount(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 10: _t->gotoOverviewPage(); break;
        case 11: _t->gotoHistoryPage(); break;
        case 12: _t->gotoReceiveCoinsPage(); break;
        case 13: _t->gotoSendCoinsPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->gotoSendCoinsPage(); break;
        case 15: _t->gotoSignMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->gotoSignMessageTab(); break;
        case 17: _t->gotoVerifyMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->gotoVerifyMessageTab(); break;
        case 19: _t->openClicked(); break;
        case 20: _t->optionsClicked(); break;
        case 21: _t->aboutClicked(); break;
        case 22: _t->showDebugWindow(); break;
        case 23: _t->showDebugWindowActivateConsole(); break;
        case 24: _t->showHelpMessageClicked(); break;
        case 25: _t->trayIconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 26: _t->showNormalIfMinimized((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->showNormalIfMinimized(); break;
        case 28: _t->toggleHidden(); break;
        case 29: _t->detectShutdown(); break;
        case 30: _t->showProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: _t->setTrayIconVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->toggleNetworkActive(); break;
        case 33: _t->showModalOverlay(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BitcoinGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BitcoinGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BitcoinGUI,
      qt_meta_data_BitcoinGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BitcoinGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BitcoinGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BitcoinGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BitcoinGUI))
        return static_cast<void*>(const_cast< BitcoinGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BitcoinGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void BitcoinGUI::receivedURI(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_UnitDisplayStatusBarControl[] = {

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
      38,   29,   28,   28, 0x08,
      68,   61,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UnitDisplayStatusBarControl[] = {
    "UnitDisplayStatusBarControl\0\0newUnits\0"
    "updateDisplayUnit(int)\0action\0"
    "onMenuSelection(QAction*)\0"
};

void UnitDisplayStatusBarControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UnitDisplayStatusBarControl *_t = static_cast<UnitDisplayStatusBarControl *>(_o);
        switch (_id) {
        case 0: _t->updateDisplayUnit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onMenuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UnitDisplayStatusBarControl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UnitDisplayStatusBarControl::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_UnitDisplayStatusBarControl,
      qt_meta_data_UnitDisplayStatusBarControl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UnitDisplayStatusBarControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UnitDisplayStatusBarControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UnitDisplayStatusBarControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UnitDisplayStatusBarControl))
        return static_cast<void*>(const_cast< UnitDisplayStatusBarControl*>(this));
    return QLabel::qt_metacast(_clname);
}

int UnitDisplayStatusBarControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
