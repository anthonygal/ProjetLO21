#include "Relations.h"

// RELATIONS ENTRE NOTES

Relation::Relation(const QString& t, const QString& d, bool o){
    titre=t;
    description=d;
    orientee=o;
    couples=new Couple*[5];
    nbCouples=0;
    nbMaxCouples=5;
};

Relation::~Relation(){
    for(unsigned int i=0; i<nbCouples;i++){
        delete couples[i];}
    delete[] couples;
}

void Relation::addCouple(Couple& c){
    if (nbCouples==nbMaxCouples){
        Couple** newtab= new Couple* [nbMaxCouples+5];
        for(unsigned int i=0; i<nbCouples;i++){
            newtab[i]=couples[i];
        }

        //nbMaxCouples=nbMaxCouples+100; //Changement Antoine
        nbCouples=nbCouples+5; //Changement Antho

        Couple** oldtab= couples;
        couples=newtab;
        delete [] oldtab;
    }
    couples[nbCouples]=&c;
    nbCouples++;
}

void Relation::supprimerCouple(Couple* c){
    for (int i=0; i<nbCouples; i++){    
        if (couples[i]==c){     //On cherche si le couple existe bien dans la relation
            Couple* temp=couples[i];
            for(unsigned int j=i; j<nbCouples-1;j++){ //on sort le couple du tableau
                couples[j]=couples[j+1];
            }
            delete temp;    //On detruit le couple
            nbCouples--;    //On met a jour le nombre de couples dans la relation
        }
    }
}

Reference::~Reference(){
    this->Relation::~Relation();
}

//Singleton de la classe REFERENCE

Reference* Reference::instanceUnique=nullptr;
Reference& Reference::donneInstance(){
    if (instanceUnique==nullptr) instanceUnique= new Reference();
    return *instanceUnique;
}
void Reference::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique=nullptr;
}


void Relation::saveRelation(QXmlStreamWriter& stream)const{
    stream.writeStartElement("relations");
    stream.writeTextElement("titre", getTitre());
    stream.writeTextElement("description",getDescription());
    stream.writeTextElement("orientee",orienteetoQString());
    for(unsigned int j=0; j<nbCouples;j++){
        couples[j]->savecouple(stream);
    }
    stream.writeEndElement();
}


void Reference::saveReference(QXmlStreamWriter& stream){
    stream.writeStartElement("references");
    stream.writeTextElement("titre", getTitre());
    stream.writeTextElement("description",getDescription());
    stream.writeTextElement("orientee",orienteetoQString());
    for(unsigned int j=0; j<nbCouples;j++){
        couples[j]->savecouple(stream);
    }

}

void Couple::savecouple(QXmlStreamWriter& stream) const{
    stream.writerStartElement("couples");
    stream.writeTextElement("label", getLabel());
    stream.writeTextElement("ID1",getID1());
    stream.writeTextElement("ID2",getID2());
    stream.writeEndElement();
}



QString Relation::orienteetoQString()const{
    QString str="";
    if (orientee==true){str="Orientee";}
    else{str="Non Orientee";}
    return str;
}

bool Relation::QStringtoOrientee(const QString& str){
    if (str=="Orientee") {return true;}
    else {return false;}
}
