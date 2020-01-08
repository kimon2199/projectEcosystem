#include<string>
#include"animals.h"

using namespace std;


Animal::Animal(string n,int& sz, int& sp,int eatCnt,bool& ch) : name(n),size(sz), speed(sp), eatCount(eatCnt), hibernates(ch), isHungry(0), isAlive(1), inHibernation(0){};
void Animal::move(int& x,int& y,int side,char c){
    int steps = 1 + (rand() % (speed-1+1));
    for(int i=0;i<steps;i++){
        int xx, yy;
        int lim = 0;
        
        do{
            xx = x + ((rand()%10 > 4) ? -1 : 1);
            yy = y + ((rand()%10 > 4) ? -1 : 1);
            lim++;
        } while (!(inGrid(xx,yy,side)&&(canLiveAt(c))) && lim!=12);
        if (lim!=12){
            x = xx;
            y = yy;
        }
    }
}
void Animal::grow(int sz,int spd, int limSz,int limSpd) {
    size = min(limSz,size+sz);
    speed = min(limSpd,speed+spd);
    
}
void Animal::setGP(int n){
    growthPeriod = n;
}
int Animal::getGP(){
    return growthPeriod;
}
int Animal::getSize() const{
    return size;
}
int Animal::getSpeed() const{
    return speed;
}
void Animal::setCoords(int& d,int& l){
    x = d;
    y = l;
};
int Animal::getX() const{
    return x;
}
int Animal::getY() const{
    return y;
}
bool Animal::inGrid(int& x,int& y,int& side) const{
    return x>=0 && y>=0 && x<side && y<side;
}
void Animal::makeHngr(){
    isHungry = 1;
}
int Animal::getDsf() const{
    return daysSinceFood;
}
void Animal::incrDsf(){
    daysSinceFood++;
}
int Animal::getEatCount() const{
    return eatCount;
}
int Animal::getEatenFood() const{
    return eatenFood;
}
void Animal::incrEatFoo(int n){
    eatenFood += n;
}
void Animal::makeNotHngr(){
    isHungry = 0;
    daysSinceFood = 0;
}
string Animal::getName() const{
    return name;
}
void Animal::die(){
    isAlive = 0;
}
bool Animal::isDead() const{
    return !isAlive;
}
bool Animal::canHibernate() const{
    return hibernates;
}
void Animal::sleep(){
    inHibernation = 1;
}
void Animal::wake(){
    inHibernation = 0;
}
bool Animal::isAwake() const{
    return !inHibernation;
}
int Animal::growthPeriod = 0;
Animal::~Animal() {};


Herbivores::Herbivores(string n,int size,int speed,int neeFoo,bool canClb,bool canHb,int eatCnt) : Animal(n,size,speed,eatCnt,canHb), neededFood(neeFoo), canClimb(canClb) {};
void Herbivores::setBRP(int n){
    breedingRepPeriod = n;
}
int Herbivores::getBRP(){
    return breedingRepPeriod;
}
void Herbivores::growUp(int sz,int spd,int fpd,int limSz,int limSpd,int limFpd){
    grow(sz,spd,limSz,limSpd);
    neededFood = min(limFpd,neededFood+fpd);
}
bool Herbivores::getClimb() const{
    return canClimb;
}
void Herbivores::setClimb(){
    canClimb = 1;
}
int Herbivores::getNeededFood() const{
    return neededFood;
}
bool Herbivores::needsFood() const{
    return getDsf() > 6;
}
int Herbivores::eat(){
    incrEatenFood();
    checkSatisfaction();
    return getEatCount();
}
void Herbivores::incrEatenFood(){
    incrEatFoo(getEatCount());
};
void Herbivores::checkSatisfaction(){
    if (getEatenFood()>=neededFood)
        makeNotHngr();
}
int Herbivores::breedingRepPeriod = 0;
Herbivores::~Herbivores() {};


Deer::Deer() : Herbivores("Deer",5,8,8,0,0,2) {};
Deer::Deer(int i) : Herbivores("Deer",2,4,4,0,0,2) {}; //young
bool Deer::canStartAt(char c){
    return c == '"';
}
bool Deer::canLiveAt(char c){
    return  1;
}
bool Deer::canEat(char& c,int& sz){
    return sz<=getSize()+4;
}
void Deer::raise() {
    growUp(1,2,2,5,8,8);
}
bool Deer::isAdult(){
    return (getSize()==5)&&(getSpeed()==8)&&(getNeededFood()==8);
}
Herbivores* Deer::birth(){
    return new Deer(0);
}
Deer::~Deer() {};


Rabbit::Rabbit() : Herbivores("Rabbit",2,6,4,0,0,1) {};
Rabbit::Rabbit(int i) : Herbivores("Rabbit",1,2,2,0,0,1) {}; //young
bool Rabbit::canStartAt(char c){
    return c == '"';
}
bool Rabbit::canLiveAt(char c){
    return !(c == '^');
}
bool Rabbit::canEat(char& c,int& sz){
    return getSize()>=sz;
}
void Rabbit::raise() {
    growUp(1,2,1,2,6,4);
}
bool Rabbit::isAdult(){
    return (getSize()==2)&&(getSpeed()==6)&&(getNeededFood()==4);
}
Herbivores* Rabbit::birth(){
    return new Rabbit(0);
}
Rabbit::~Rabbit() {};


Groundhog::Groundhog() : Herbivores("Groundhog",3,5,5,1,1,1) {};
Groundhog::Groundhog(int i) : Herbivores("Groundhog",2,3,3,0,1,1) {}; //young
bool Groundhog::canStartAt(char c){
    return c == '"';
}
bool Groundhog::canLiveAt(char c){
    return !(c == '#');
}
bool Groundhog::canEat(char& c,int& sz){
    return c!='A'&&(getSize()>=sz||isClimbable(sz));
}
void Groundhog::raise() {
    growUp(1,1,1,3,5,5);
    if (isAdult())
        setClimb();
}
bool Groundhog::isClimbable(int& sz){
    return getClimb()&&(3*getSize()>=sz);
}
bool Groundhog::isAdult(){
    return (getSize()==3)&&(getSpeed()==5)&&(getNeededFood()==5);
}
Herbivores* Groundhog::birth(){
    return new Groundhog(0);
}
Groundhog::~Groundhog() {};


Salmon::Salmon() : Herbivores("Salmon",1,5,1,0,0,1) {};
bool Salmon::canStartAt(char c){
    return c == '#';
}
bool Salmon::canLiveAt(char c){
    return c == '#';
}
bool Salmon::canEat(char& c,int& sz){
    return c == 'A';
}
void Salmon::raise() {};
bool Salmon::isAdult(){
    return 1;
}
Herbivores* Salmon::birth(){
    return new Salmon();
}
Salmon::~Salmon() {};


Carnivores::Carnivores(string n,int size,int att,int def,int speed,int mysteryfood,bool canHb) : Animal(n,size,speed,0,canHb), attack(att), defence(def) {};
void Carnivores::setBRP(int n){ //the 0 above is an arbitrary value because
    breedingRepPeriod = n;      //they are automaticaly satisfied after a meal
}
int Carnivores::getBRP(){
    return breedingRepPeriod;
}
void Carnivores::growUp(int sz,int att,int def,int spd,int mysteryfood,int limSz,int limAtt,int limDef,int limSpd,int limmysteryfood){
    grow(sz,spd,limSz,limSpd);
    attack = min(limAtt,attack+att);
    defence = min(limSpd,defence+def);
}
int Carnivores::eat(){
    makeNotHngr();
    return 0;
}
bool Carnivores::isVeryHungry() const{
    return getDsf()>7;
}
int Carnivores::getAttack() const{
    return attack;
}
int Carnivores::getDefence() const{
    return defence;
}
int Carnivores::breedingRepPeriod = 0;
Carnivores::~Carnivores() {};


Fox::Fox() : Carnivores("Fox",4,5,5,6,6,0) {};
Fox::Fox(int i) : Carnivores("Fox",1,1,1,1,2,0) {}; //young
bool Fox::canStartAt(char c){
    return c == '"';
}
bool Fox::canLiveAt(char c){
    return  1;
}
bool Fox::canEat(string str,int& sz,int& spd){
    return !(str.compare("Salmon")==0) && sz<=getSize() && spd<getSpeed();
}
bool Fox::canKill(string str,int& sz,int& spd,int&def){
    return getSize()>sz || (getSize()==sz && getAttack()>def );
}
void Fox::raise() {
    growUp(1,1,1,1,1,4,5,5,6,6);
}
bool Fox::isAdult(){
    return (getSize()==4)&&(getAttack()==5)&&(getDefence()==5)&&(getSpeed()==6);
}
Carnivores* Fox::birth(){
    return new Fox(0);
}
Fox::~Fox() {};


Wolf::Wolf() : Carnivores("Wolf",7,8,6,8,8,0) {};
Wolf::Wolf(int i) : Carnivores("Wolf",1,2,2,2,2,0) {}; //young
bool Wolf::canStartAt(char c){
    return c != '#';
}
bool Wolf::canLiveAt(char c){
    return  1;
}
bool Wolf::canEat(string str,int& sz,int& spd){
    return !(str.compare("Salmon")==0) && sz<=getSize() && spd<getSpeed();
}
bool Wolf::canKill(string str,int& sz,int& spd,int&def){
    return getSize()>sz || (getSize()==sz && getAttack()>def );
}
void Wolf::raise() {
    growUp(1,2,2,2,2,7,8,6,8,8);
}
bool Wolf::isAdult(){
    return (getSize()==7)&&(getAttack()==8)&&(getDefence()==6)&&(getSpeed()==8);
}
Carnivores* Wolf::birth(){
    return new Wolf(0);
}
Wolf::~Wolf() {};


Bear::Bear() : Carnivores("Bear",10,10,10,4,10,1) {};
Bear::Bear(int i) : Carnivores("Bear",3,6,6,4,5,1) {}; //young
bool Bear::canStartAt(char c){
    return c == '^';
}
bool Bear::canLiveAt(char c){
    return 1;
}
bool Bear::canEat(string str,int& sz,int& spd){
    return 1;
}
bool Bear::canKill(string str,int& sz,int& spd,int& def){
    return str.compare("Bear")!=0;
}
void Bear::raise() {
    growUp(2,2,2,0,2,10,10,10,4,10);
}
bool Bear::isAdult(){
    return (getSize()==10)&&(getAttack()==10)&&(getDefence()==10)&&(getSpeed()==4);
}
Carnivores* Bear::birth(){
    return new Bear(0);
}
Bear::~Bear() {};




