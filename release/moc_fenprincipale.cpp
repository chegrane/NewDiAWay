/****************************************************************************
** Meta object code from reading C++ file 'fenprincipale.h'
**
** Created: Wed 29. Dec 13:05:27 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fenprincipale.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenprincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FenPrincipale[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      38,   36,   14,   14, 0x08,
      69,   14,   14,   14, 0x08,
      79,   14,   14,   14, 0x08,
      86,   14,   14,   14, 0x08,
      93,   14,   14,   14, 0x08,
     102,   14,   14,   14, 0x08,
     110,   14,   14,   14, 0x08,
     125,   14,   14,   14, 0x08,
     132,   14,   14,   14, 0x08,
     139,   14,   14,   14, 0x08,
     145,   14,   14,   14, 0x08,
     152,   14,   14,   14, 0x08,
     160,   14,   14,   14, 0x08,
     173,   14,   14,   14, 0x08,
     185,   14,   14,   14, 0x08,
     194,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FenPrincipale[] = {
    "FenPrincipale\0\0on_suivant_clicked()\0"
    "a\0LongDiagoPermi_Liste_Slot(int)\0"
    "newFile()\0open()\0save()\0saveAs()\0"
    "print()\0printPreview()\0undo()\0redo()\0"
    "cut()\0copy()\0paste()\0deleteText()\0"
    "selectAll()\0search()\0grapheADN()\0"
};

const QMetaObject FenPrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenPrincipale,
      qt_meta_data_FenPrincipale, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FenPrincipale::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FenPrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FenPrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenPrincipale))
        return static_cast<void*>(const_cast< FenPrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenPrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_suivant_clicked(); break;
        case 1: LongDiagoPermi_Liste_Slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: newFile(); break;
        case 3: open(); break;
        case 4: save(); break;
        case 5: saveAs(); break;
        case 6: print(); break;
        case 7: printPreview(); break;
        case 8: undo(); break;
        case 9: redo(); break;
        case 10: cut(); break;
        case 11: copy(); break;
        case 12: paste(); break;
        case 13: deleteText(); break;
        case 14: selectAll(); break;
        case 15: search(); break;
        case 16: grapheADN(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
