/****************************************************************************
** Meta object code from reading C++ file 'FenetrePrincipale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Qt_Projet/FenetrePrincipale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenetrePrincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FenetrePrincipale_t {
    QByteArrayData data[15];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FenetrePrincipale_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FenetrePrincipale_t qt_meta_stringdata_FenetrePrincipale = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FenetrePrincipale"
QT_MOC_LITERAL(1, 18, 15), // "reaffichageNote"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "updateFenetre"
QT_MOC_LITERAL(4, 49, 5), // "Note&"
QT_MOC_LITERAL(5, 55, 1), // "n"
QT_MOC_LITERAL(6, 57, 11), // "sauvegarder"
QT_MOC_LITERAL(7, 69, 10), // "newArticle"
QT_MOC_LITERAL(8, 80, 8), // "newTache"
QT_MOC_LITERAL(9, 89, 13), // "newMultimedia"
QT_MOC_LITERAL(10, 103, 13), // "voirRelations"
QT_MOC_LITERAL(11, 117, 12), // "editRelation"
QT_MOC_LITERAL(12, 130, 14), // "createRelation"
QT_MOC_LITERAL(13, 145, 14), // "viderCorbeille"
QT_MOC_LITERAL(14, 160, 18) // "restaurerCorbeille"

    },
    "FenetrePrincipale\0reaffichageNote\0\0"
    "updateFenetre\0Note&\0n\0sauvegarder\0"
    "newArticle\0newTache\0newMultimedia\0"
    "voirRelations\0editRelation\0createRelation\0"
    "viderCorbeille\0restaurerCorbeille"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenetrePrincipale[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    1,   75,    2, 0x0a /* Public */,
       3,    0,   78,    2, 0x0a /* Public */,
       6,    0,   79,    2, 0x0a /* Public */,
       7,    0,   80,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FenetrePrincipale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FenetrePrincipale *_t = static_cast<FenetrePrincipale *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reaffichageNote(); break;
        case 1: _t->updateFenetre((*reinterpret_cast< Note(*)>(_a[1]))); break;
        case 2: _t->updateFenetre(); break;
        case 3: _t->sauvegarder(); break;
        case 4: _t->newArticle(); break;
        case 5: _t->newTache(); break;
        case 6: _t->newMultimedia(); break;
        case 7: _t->voirRelations(); break;
        case 8: _t->editRelation(); break;
        case 9: _t->createRelation(); break;
        case 10: _t->viderCorbeille(); break;
        case 11: _t->restaurerCorbeille(); break;
        default: ;
        }
    }
}

const QMetaObject FenetrePrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenetrePrincipale.data,
      qt_meta_data_FenetrePrincipale,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FenetrePrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenetrePrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenetrePrincipale.stringdata0))
        return static_cast<void*>(const_cast< FenetrePrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenetrePrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
