/****************************************************************************
** Meta object code from reading C++ file 'splashscreen.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/splashscreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splashscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SplashScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x0a,
      67,   43,   13,   13, 0x0a,
     106,   99,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SplashScreen[] = {
    "SplashScreen\0\0mainWin\0slotFinish(QWidget*)\0"
    "message,alignment,color\0"
    "showMessage(QString,int,QColor)\0action\0"
    "setBreakAction(std::function<void(void)>)\0"
};

void SplashScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SplashScreen *_t = static_cast<SplashScreen *>(_o);
        switch (_id) {
        case 0: _t->slotFinish((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3]))); break;
        case 2: _t->setBreakAction((*reinterpret_cast< const std::function<void(void)>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SplashScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SplashScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SplashScreen,
      qt_meta_data_SplashScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SplashScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SplashScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SplashScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SplashScreen))
        return static_cast<void*>(const_cast< SplashScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int SplashScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
