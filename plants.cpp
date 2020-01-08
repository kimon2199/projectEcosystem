#include<string>
#include"plants.h"


Plant::Plant(string n,char tok,int lif,int brePro,int ilPro,int liFa,int sz) : name(n), token(tok), life(lif), breedingProb(brePro), illnessProb(ilPro), lifeFactor(liFa), size(sz) {};
void Plant::setGP(int n){
    growthPeriod = n;
}
int Plant::getGP(){
    return growthPeriod;
}
void Plant::setBRP(int n){
    breedingRepPeriod = n;
}
int Plant::getBRP(){
    return breedingRepPeriod;
}
char Plant::getToken() const{
    return token;
}
int Plant::getX() const{
    return x;
}
int Plant::getY() const{
    return y;
}
void Plant::setCoords(int& d,int& l){
    x = d;
    y = l;
}
void Plant::raise() {
    size+=0;
}
int Plant::getSize() const{
    return size;
}
int Plant::getLife() const{
    return life;
}
int Plant::getBreedProb() const{
    return breedingProb;
}
void Plant::decLife(int n){
    life -= n;
}
int Plant::growthPeriod = 0;
int Plant::breedingRepPeriod = 0;
Plant::~Plant() {};


Seedless::Seedless(string n,char tok,int lif,int brePro,int ilPro,int liFa) : Plant(n,tok,lif,brePro,ilPro,liFa,0) {};
void Seedless::decSeeds(int i){}
void Seedless::decFol(int i){}
bool Seedless::hasSeedsLeft(){
    return 0;
}
Seedless::~Seedless() {};


Grass::Grass() : Seedless("Grass",'G',5,15,15,4) {};
bool Grass::canGrow(char c){
    return c == '"';
}
bool Grass::canLive(char c){
    return c == '"';
}
Plant* Grass::birth(){
    return new Grass();
};
Grass::~Grass() {};


Algae::Algae() : Seedless("Algae",'A',5,25,25,2) {};
bool Algae::canGrow(char c){
    return c == '#';
}
bool Algae::canLive(char c){
    return c == '#';
}
Plant* Algae::birth(){
    return new Algae();
};
Algae::~Algae() {};


Seeded::Seeded(string n,char tok,int sz,int brePro,int ilPro,int liFa,int fol,int se) : Plant(n,tok,fol,brePro,ilPro,liFa,sz), foliage(fol), seeds(se)  {};
void Seeded::decSeeds(int i){
    seeds -= i;
}
void Seeded::decFol(int i){
    foliage -= i;
    decLife(i);
}
bool Seeded::hasSeedsLeft(){
    return seeds>0;
}
Seeded::~Seeded() {};


Oak::Oak() : Seeded("Oak",'O',5,20,20,15,30,15) {};
bool Oak::canGrow(char c){
    return c == '"';
}
bool Oak::canLive(char c){
    return c == '"';
}
Plant* Oak::birth(){
    return new Oak();
};
Oak::~Oak() {};


Pine::Pine() : Seeded("Pine",'P',5,15,15,20,40,20) {};
bool Pine::canGrow(char c){
    return c == '^';
}
bool Pine::canLive(char c){
    return (c == '"')||(c == '^');
}
Plant* Pine::birth(){
    return new Pine();
};
Pine::~Pine() {};


Maple::Maple() : Seeded("Maple",'M',2,5,5,10,20,10) {};
bool Maple::canGrow(char c){
    return (c == '"')||(c == '^');
}
bool Maple::canLive(char c){
    return (c == '"')||(c == '^');
}
Plant* Maple::birth(){
    return new Maple();
};
Maple::~Maple() {};
