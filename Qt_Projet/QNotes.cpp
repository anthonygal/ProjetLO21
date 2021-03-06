#include "QNotes.h"

QNoteReduite::QNoteReduite(Note& n, QWidget* parent) : QPushButton(parent), note(n)
{
    setMinimumSize(150,40);
    QHBoxLayout *layout = new QHBoxLayout;
        QLabel *Type = new QLabel(note.getTypeNote());
        QLabel *ID = new QLabel(QString::number(note.getID()));
        QLabel *Titre = new QLabel(note.getTitre());
        layout->addWidget(Type);
        layout->addWidget(ID);
        layout->addWidget(Titre);
    setLayout(layout);
    QObject::connect(this,SIGNAL(clicked()),SLOT(onClicked()));
    setStyleSheet("background-color: grey");
    setCursor(Qt::PointingHandCursor);
}

void QNoteReduite::onClicked(){
    FenetrePrincipale::donneInstance().updateFenetre(note);
}

QNote::QNote(Note& n, QWidget *parent) : QFrame(parent), note(n)
{
    QVBoxLayout *vlayout = new QVBoxLayout;

    QHBoxLayout *hlayout0 = new QHBoxLayout;
        QLabel *TypeNote = new QLabel(n.getTypeNote()); TypeNote->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        TypeNote->setFont(QFont("Comic Sans MS", 11));
        QLabel *Actuelle = new QLabel(n.isActuelle()?"(Version Actuelle)":"(Ancienne Version)",this);
        hlayout0->addWidget(TypeNote);
        hlayout0->addWidget(Actuelle);
    vlayout->addLayout(hlayout0);

    QHBoxLayout *hlayout1 = new QHBoxLayout;
        QLabel *lID = new QLabel("ID : ");
        lID->setStyleSheet("font-weight: bold;");
        QLabel *ID = new QLabel(QString::number(n.getID()));
        hlayout1->addWidget(lID);
        hlayout1->addWidget(ID);
    vlayout->addLayout(hlayout1);

    QHBoxLayout *hlayout2 = new QHBoxLayout;
        QLabel *lEtat = new QLabel("Etat : ");
        lEtat->setStyleSheet("font-weight: bold;");
        QLabel *Etat = new QLabel(n.NoteEtattoQString());
        hlayout2->addWidget(lEtat);
        hlayout2->addWidget(Etat);
    vlayout->addLayout(hlayout2);

    QHBoxLayout *hlayout3 = new QHBoxLayout;
        QLabel *lDateCrea = new QLabel("Date de création : ");
        lDateCrea->setStyleSheet("font-weight: bold;");
        QLabel *DateCrea = new QLabel(n.getDateCrea().toString(formatDateTime));
        hlayout3->addWidget(lDateCrea);
        hlayout3->addWidget(DateCrea);
    vlayout->addLayout(hlayout3);

    QHBoxLayout *hlayout4 = new QHBoxLayout;
        QLabel *lDateModif = new QLabel("Date de modification : ");
        lDateModif->setStyleSheet("font-weight: bold;");
        QLabel *DateModif = new QLabel(n.getDateModif().toString(formatDateTime));
        hlayout4->addWidget(lDateModif);
        hlayout4->addWidget(DateModif);
    vlayout->addLayout(hlayout4);

    QHBoxLayout *hlayout5 = new QHBoxLayout;
        QLabel *lTitre = new QLabel("Titre : ");
        lTitre->setStyleSheet("font-weight: bold;");
        QLabel *Titre = new QLabel(n.getTitre());
        hlayout5->addWidget(lTitre);
        hlayout5->addWidget(Titre);
    vlayout->addLayout(hlayout5);

    QHBoxLayout *boutonsLayout = new QHBoxLayout;

    if(n.getTypeNote() == "Article"){
        Article& a = dynamic_cast<Article&>(n);

        QHBoxLayout *hlayout6 = new QHBoxLayout;
            QLabel *lTexte = new QLabel("Texte : ");
            lTexte->setStyleSheet("font-weight: bold;");
            QLabel *Texte = new QLabel(a.getTexte());
            hlayout6->addWidget(lTexte);
            hlayout6->addWidget(Texte);
        vlayout->addLayout(hlayout6);
    }

    else if(n.getTypeNote() == "Tache"){
        Tache& t = dynamic_cast<Tache&>(n);

        QHBoxLayout *hlayout6 = new QHBoxLayout;
            QLabel *lStatut = new QLabel("Statut : ");
            lStatut->setStyleSheet("font-weight: bold;");
            QLabel *Statut = new QLabel(t.TacheStatuttoQString());
            hlayout6->addWidget(lStatut);
            hlayout6->addWidget(Statut);
        vlayout->addLayout(hlayout6);

        QHBoxLayout *hlayout7 = new QHBoxLayout;
            QLabel *lAction = new QLabel("Action : ");
            lAction->setStyleSheet("font-weight: bold;");
            QLabel *Action = new QLabel(t.getAction());
            hlayout7->addWidget(lAction);
            hlayout7->addWidget(Action);
        vlayout->addLayout(hlayout7);

        if(t.getPriorite()){
            QHBoxLayout *hlayout8 = new QHBoxLayout;
                QLabel *lPriorite = new QLabel("Priorite : ");
                lPriorite->setStyleSheet("font-weight: bold;");
                QLabel *Priorite = new QLabel(QString::number(t.getPriorite()));
                hlayout8->addWidget(lPriorite);
                hlayout8->addWidget(Priorite);
            vlayout->addLayout(hlayout8);
        }
        if(!t.getEcheance().isNull()){
            QHBoxLayout *hlayout9 = new QHBoxLayout;
                QLabel *lEcheance = new QLabel("Date d'echeance : ");
                lEcheance->setStyleSheet("font-weight: bold;");
                QLabel *Echeance = new QLabel(t.getEcheance().toString(formatDate));
                hlayout9->addWidget(lEcheance);
                hlayout9->addWidget(Echeance);
            vlayout->addLayout(hlayout9);
        }
        if(t.isActuelle()){
            if(t.getStatut() == encours){
                QPushButton *enAttente = new QPushButton("Mettre en attente");
                QPushButton *terminer = new QPushButton("Terminée");
                boutonsLayout->addWidget(enAttente);
                boutonsLayout->addWidget(terminer);
                QObject::connect(enAttente,SIGNAL(clicked()),this,SLOT(tacheEnAttente()));
                QObject::connect(terminer,SIGNAL(clicked()),this,SLOT(tacheTerminee()));
            }
            else if(t.getStatut() == attente){
                QPushButton *reprise = new QPushButton("Reprise");
                boutonsLayout->addWidget(reprise);
                QObject::connect(reprise,SIGNAL(clicked()),this,SLOT(tacheReprise()));
            }
        }
    }

    else if(n.getTypeNote() == "Multimedia"){
        Multimedia& m = dynamic_cast<Multimedia&>(n);

        QHBoxLayout *hlayout6 = new QHBoxLayout;
            QLabel *lType = new QLabel("Type de fichier : ");
            lType->setStyleSheet("font-weight: bold;");
            QLabel *Type = new QLabel(m.TypeMultimediatoQString());
            hlayout6->addWidget(lType);
            hlayout6->addWidget(Type);
        vlayout->addLayout(hlayout6);

        QHBoxLayout *hlayout7 = new QHBoxLayout;
            QLabel *lFichier = new QLabel("Adresse du fichier : ");
            lFichier->setStyleSheet("font-weight: bold;");
            QLabel *Fichier = new QLabel(m.getAdresseFichier());
            hlayout7->addWidget(lFichier);
            hlayout7->addWidget(Fichier);
        vlayout->addLayout(hlayout7);

        QHBoxLayout *hlayout8 = new QHBoxLayout;
            QLabel *lDescription = new QLabel("Description : ");
            lDescription->setStyleSheet("font-weight: bold;");
            QLabel *Description = new QLabel(m.getDescription());
            hlayout8->addWidget(lDescription);
            hlayout8->addWidget(Description);
        vlayout->addLayout(hlayout8);
    }

    if(n.getEtat() == active){
        if(n.isActuelle()){
            QPushButton *boutonModifier = new QPushButton("Modifier");
                boutonModifier->setToolTip("Editer une nouvelle version de la note");
                boutonModifier->setFont(QFont("Comic Sans MS", 10));
                boutonModifier->setCursor(Qt::PointingHandCursor);
            boutonsLayout->addWidget(boutonModifier);
            QPushButton *boutonSupprimer = new QPushButton("Supprimer");
                boutonSupprimer->setToolTip("Mettre dans la corbeille");
                boutonSupprimer->setFont(QFont("Comic Sans MS", 10));
                boutonSupprimer->setCursor(Qt::PointingHandCursor);
            boutonsLayout->addWidget(boutonSupprimer);
            QObject::connect(boutonModifier,SIGNAL(clicked()),this,SLOT(editer()));
            QObject::connect(boutonSupprimer,SIGNAL(clicked()),this,SLOT(supprimer()));
        }
        else{
            QPushButton *boutonRestaurerVersion = new QPushButton("Revenir à cette version");
            boutonRestaurerVersion->setCursor(Qt::PointingHandCursor);
            boutonRestaurerVersion->setFont(QFont("Comic Sans MS", 10));
            boutonsLayout->addWidget(boutonRestaurerVersion);
            QObject::connect(boutonRestaurerVersion,SIGNAL(clicked()),this,SLOT(restaurerVersion()));
        }
    }
    else{
        QPushButton *boutonRestaurer = new QPushButton("Restaurer");
            boutonRestaurer->setCursor(Qt::PointingHandCursor);
            boutonRestaurer->setFont(QFont("Comic Sans MS", 10));
        boutonsLayout->addWidget(boutonRestaurer);
        QObject::connect(boutonRestaurer,SIGNAL(clicked()),this,SLOT(restaurerNote()));
    }

    vlayout->addLayout(boutonsLayout);
    setLayout(vlayout);
    setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
}

void QNote::editer(){
    note.edit();
}

void QNote::supprimer(){
    Manager::donneInstance().supprimerNote(note);
    FenetrePrincipale::donneInstance().updateFenetre(note);
}

void QNote::restaurerVersion(){
    Manager::donneInstance().restaurerVersion(note);
    FenetrePrincipale::donneInstance().updateFenetre(note);
}

void QNote::restaurerNote(){
    Manager::donneInstance().restaurerNote(note);
    FenetrePrincipale::donneInstance().updateFenetre(note);
}

void QNote::tacheEnAttente(){
    Tache& t = dynamic_cast<Tache&>(note);
    t.setStatut(attente);
    FenetrePrincipale::donneInstance().updateFenetre(t);
}

void QNote::tacheTerminee(){
    Tache& t = dynamic_cast<Tache&>(note);
    t.setStatut(terminee);
    FenetrePrincipale::donneInstance().updateFenetre(t);
}

void QNote::tacheReprise(){
    Tache& t = dynamic_cast<Tache&>(note);
    t.setStatut(encours);
    FenetrePrincipale::donneInstance().updateFenetre(t);
}
