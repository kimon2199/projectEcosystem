#include<iostream>
#include<string>
#include<cstdlib>
//#include"terTile.h"

#ifndef ANIMALS_H
#define ANIMALS_H

using namespace std;

class Animal{
    string name;
    int size;
    int hungerCount;
    int eatenFood;
    int eatCount;
    int x;
    int y;
    bool isAlive;
    bool isHungry;
    bool inHeat;
    int speed;
    bool hibernates;
    bool inHibernation;
    int daysSinceFood;
    static int growthPeriod;
public:
    Animal(string n,int& sz, int& sp,int eatCnt,bool& ch);
    void move(int& x,int& y,int side,char c);
    virtual int eat() = 0;
    virtual void raise() = 0;
    void grow(int sz,int spd, int limSz,int limSpd);
    static void setGP(int n);
    static int getGP();
    int getSize() const;
    int getSpeed() const;
    virtual bool canStartAt(char c) = 0;
    virtual bool canLiveAt(char c) = 0;
    void setCoords(int& d,int& l);
    int getX() const;
    int getY() const;
    bool inGrid(int& x,int& y,int& side) const;
    void makeHngr();
    int getDsf() const;
    void incrDsf();
    int getEatCount() const;
    int getEatenFood() const;
    void incrEatFoo(int n);
    void makeNotHngr();
    string getName() const;
    void die();
    bool isDead() const;
    bool canHibernate() const;
    void sleep();
    void wake();
    bool isAwake() const;
    virtual ~Animal();
};

class Herbivores : public Animal{
    bool canClimb;
    int neededFood;
    static int breedingRepPeriod;
    void checkSatisfaction();
public:
    Herbivores(string n,int size,int speed,int neeFoo,bool canClb,bool canHb,int eatCnt);
    static void setBRP(int n);
    static int getBRP();
    void growUp(int sz,int spd,int fpd,int limSz,int limSpd,int limFpd);
    virtual bool canEat(char& c,int& sz) = 0;
    bool getClimb() const;
    void setClimb();
    int getNeededFood() const;
    bool needsFood() const;
    int eat();
    void incrEatenFood();
    virtual bool isAdult() = 0;
    virtual Herbivores* birth() = 0;
    virtual ~Herbivores();
};

class Deer : public Herbivores{
public:
    Deer();
    Deer(int i);
    bool canStartAt(char c);
    bool canLiveAt(char c);
    bool canEat(char& c,int& sz);
    void raise();
    bool isAdult();
    Herbivores* birth();
    virtual ~Deer();
};

class Rabbit : public Herbivores{
public:
    Rabbit();
    Rabbit(int i);
    bool canStartAt(char c);
    bool canLiveAt(char c);
    bool canEat(char& c,int& sz);
    void raise();
    bool isAdult();
    Herbivores* birth();
    virtual ~Rabbit();
};

class Groundhog: public Herbivores{
public:
    Groundhog();
    Groundhog(int i);
    bool canStartAt(char c);
    bool canLiveAt(char c);
    bool canEat(char& c,int& sz);
    void raise();
    bool isClimbable(int& sz);
    bool isAdult();
    Herbivores* birth();
    virtual ~Groundhog();
};

class Salmon : public Herbivores{
public:
    Salmon();
    bool canStartAt(char c);
    bool canLiveAt(char c);
    bool canEat(char& c,int& sz);
    void raise();
    bool isAdult();
    Herbivores* birth();
    virtual ~Salmon();
};

class Carnivores : public Animal{
    int attack;
    int defence;
    static int breedingRepPeriod;
public:
    Carnivores(string n,int size,int att,int def,int speed,int mysteryfood,bool canHb);
    static void setBRP(int n);
    static int getBRP();
    void growUp(int sz,int att,int def,int spd,int mysteryfood,int limSz,int limAtt,int limDef,int limSpd,int limmysteryfood);
    
    virtual bool canEat(string str,int& sz,int& spd) = 0;
    virtual bool canKill(string str,int& sz,int& spd,int& def) = 0;
    int eat();
    bool isVeryHungry() const;
    int getAttack() const;
    int getDefence() const;
    virtual bool isAdult() = 0;
    virtual Carnivores* birth() = 0;
    virtual ~Carnivores();
};

class Fox : public Carnivores{
public:
    Fox();
    Fox(int i);
    bool canStartAt(char c);
    bool canLiveAt(char c);
    bool canEat(string str,int& sz,int& spd);
    bool canKill(string str,int& sz,int& spd,int& def);
    void raise();
    bool isAdult();
    Carnivores* birth();
    virtual ~Fox();
};

class Wolf : public Carnivores{
public:
    Wolf();
    Wolf(int i);
    bool canStartAt(char c);
    bool canLiveAt(char c);
    bool canEat(string str,int& sz,int& spd);
    bool canKill(string str,int& sz,int& spd,int& def);
    void raise();
    bool isAdult();
    Carnivores* birth();
    virtual ~Wolf();
};

class Bear : public Carnivores{
public:
    Bear();
    Bear(int i);
    bool canStartAt(char c);
    bool canLiveAt(char c);
    bool canEat(string str,int& sz,int& spd);
    bool canKill(string str,int& sz,int& spd,int& def);
    void raise();
    bool isAdult();
    Carnivores* birth();
    virtual ~Bear();
};

#endif
