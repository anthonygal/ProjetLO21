#ifndef Relations_hpp
#define Relations_hpp

#include "timing.h"
#include "PluriNotes.h"
#include <sstream>

using namespace TIME;

 // RELATIONS ENTRE NOTES

//class Note;
//class Manager;
//class NoteException;
//Je ne pense pas qu'il y ait besoin des 3 lignes precedentes

class Couple {
 private:
 std::string label;
 Note* Note1;
 Note* Note2;

 public:
 std::string getLabel() const {return label;}
 Note* getNote1() const {return Note1;}
 Note* getNote2() const {return Note2;}
 void setLabel(const std::string& s){label=s;}
 void setNotes1(Note* N){Note1=N;}
 void setNotes2(Note* N){Note2=N;}
 Couple(Note* A, Note* B, std::string l):Note1(A),Note2(B),label(l){};
 };


class Relation{
 private:
 std::string titre;
 std::string description;
 bool orientation;
 Couple** couples;
 int nbCouples;
 int nbMaxCouples;

 public:
 int getnbCouples() const {return nbCouples;}
 Couple** getCouples() const {return couples;};
 std::string getTitre() const {return titre;}
 std::string getDescription() const {return description;}
 bool getOrientation() const {return orientation;}
 void setOrientation(bool b){orientation=b;}
 void addCouple(Couple& c);
 Relation(const std::string& t, const std::string& d, bool o =true);
 ~Relation();
 };

class Reference: public Relation {
private:
    static Reference* instanceUnique;
    Reference():Relation("Reference","Note1 fait reference à Note2", true){};
    Reference(const Reference& R);
    void operator=(const Reference& R);
    virtual ~Reference();
 public:
    static Reference& donneInstance();
    static void libereInstance();

 };


unsigned long findRefID(const std::string& s, int p=0);
int getPosition(const std::string s, int p);

#endif /* Relations_h */
