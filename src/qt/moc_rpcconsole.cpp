/****************************************************************************
** Meta object code from reading C++ file 'rpcconsole.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/rpcconsole.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rpcconsole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RPCConsole[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      35,   27,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   11,   11,   11, 0x08,
      89,   83,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     164,  158,   11,   11, 0x08,
     226,  199,   11,   11, 0x08,
     268,  262,   11,   11, 0x08,
     295,  262,   11,   11, 0x08,
     318,  262,   11,   11, 0x08,
     347,  341,   11,   11, 0x08,
     381,  341,   11,   11, 0x08,
     413,   11,   11,   11, 0x08,
     444,   11,   11,   11, 0x08,
     477,  464,   11,   11, 0x0a,
     489,   11,   11,   11, 0x2a,
     497,   11,   11,   11, 0x0a,
     510,   11,   11,   11, 0x0a,
     532,  524,   11,   11, 0x0a,
     571,  549,   11,   11, 0x0a,
     614,  597,   11,   11, 0x2a,
     641,  635,   11,   11, 0x0a,
     678,  664,   11,   11, 0x0a,
     747,  701,   11,   11, 0x0a,
     808,  787,   11,   11, 0x0a,
     843,  836,   11,   11, 0x0a,
     862,   11,   11,   11, 0x0a,
     896,  876,   11,   11, 0x0a,
     940,   11,   11,   11, 0x0a,
     966,   11,   11,   11, 0x0a,
     986,   11,   11,   11, 0x0a,
    1019, 1011,   11,   11, 0x0a,
    1040,   11,   11,   11, 0x0a,
    1068, 1060,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RPCConsole[] = {
    "RPCConsole\0\0stopExecutor()\0command\0"
    "cmdRequest(QString)\0on_lineEdit_returnPressed()\0"
    "index\0on_tabWidget_currentChanged(int)\0"
    "on_openDebugLogfileButton_clicked()\0"
    "value\0on_sldGraphRange_valueChanged(int)\0"
    "totalBytesIn,totalBytesOut\0"
    "updateTrafficStats(quint64,quint64)\0"
    "event\0resizeEvent(QResizeEvent*)\0"
    "showEvent(QShowEvent*)\0hideEvent(QHideEvent*)\0"
    "point\0showPeersTableContextMenu(QPoint)\0"
    "showBanTableContextMenu(QPoint)\0"
    "showOrHideBanTableIfRequired()\0"
    "clearSelectedNode()\0clearHistory\0"
    "clear(bool)\0clear()\0fontBigger()\0"
    "fontSmaller()\0newSize\0setFontSize(int)\0"
    "category,message,html\0message(int,QString,bool)\0"
    "category,message\0message(int,QString)\0"
    "count\0setNumConnections(int)\0networkActive\0"
    "setNetworkActive(bool)\0"
    "count,blockDate,nVerificationProgress,headers\0"
    "setNumBlocks(int,QDateTime,double,bool)\0"
    "numberOfTxs,dynUsage\0setMempoolSize(long,size_t)\0"
    "offset\0browseHistory(int)\0scrollToEnd()\0"
    "selected,deselected\0"
    "peerSelected(QItemSelection,QItemSelection)\0"
    "peerLayoutAboutToChange()\0peerLayoutChanged()\0"
    "disconnectSelectedNode()\0bantime\0"
    "banSelectedNode(int)\0unbanSelectedNode()\0"
    "tabType\0setTabFocus(TabTypes)\0"
};

void RPCConsole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RPCConsole *_t = static_cast<RPCConsole *>(_o);
        switch (_id) {
        case 0: _t->stopExecutor(); break;
        case 1: _t->cmdRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_returnPressed(); break;
        case 3: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_openDebugLogfileButton_clicked(); break;
        case 5: _t->on_sldGraphRange_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateTrafficStats((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 7: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 8: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 9: _t->hideEvent((*reinterpret_cast< QHideEvent*(*)>(_a[1]))); break;
        case 10: _t->showPeersTableContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->showBanTableContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: _t->showOrHideBanTableIfRequired(); break;
        case 13: _t->clearSelectedNode(); break;
        case 14: _t->clear((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->clear(); break;
        case 16: _t->fontBigger(); break;
        case 17: _t->fontSmaller(); break;
        case 18: _t->setFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->message((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 20: _t->message((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 21: _t->setNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->setNetworkActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->setNumBlocks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 24: _t->setMempoolSize((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 25: _t->browseHistory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->scrollToEnd(); break;
        case 27: _t->peerSelected((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 28: _t->peerLayoutAboutToChange(); break;
        case 29: _t->peerLayoutChanged(); break;
        case 30: _t->disconnectSelectedNode(); break;
        case 31: _t->banSelectedNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->unbanSelectedNode(); break;
        case 33: _t->setTabFocus((*reinterpret_cast< TabTypes(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RPCConsole::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RPCConsole::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RPCConsole,
      qt_meta_data_RPCConsole, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RPCConsole::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RPCConsole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RPCConsole::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RPCConsole))
        return static_cast<void*>(const_cast< RPCConsole*>(this));
    return QWidget::qt_metacast(_clname);
}

int RPCConsole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void RPCConsole::stopExecutor()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RPCConsole::cmdRequest(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
