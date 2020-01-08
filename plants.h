#include<iostream>
#include<cstdlib>

#ifndef PLANTS_H
#define PLANTS_H

using namespace std;

class Plant{
    string name;
    int size;
    int x;
    int y;
    char token;
    int breedingProb;
    int illnessProb;
    int life;
    int lifeFactor;
    static int growthPeriod;
    static int breedingRepPeriod;
public:
    Plant(string n,char tok,int lif,int brePro,int ilPro,int liFa,int sz);
    static void setGP(int n);
    static int getGP();
    static void setBRP(int n);
    static int getBRP();
    char getToken() const;
    int getX() const;
    int getY() const;
    void setCoords(int&,int&);    void raise();
    int getSize() const;
    int getLife() const;
    int getBreedProb() const;
    void decLife(int n);
    virtual void decSeeds(int i) = 0;
    virtual void decFol(int i) = 0;
    virtual bool hasSeedsLeft() = 0;
    virtual bool canLive(char c) = 0;
    virtual Plant* birth() = 0;
    virtual ~Plant();
};

class Seedless : public Plant{
public:
    Seedless(string n,char tok,int lif,int brePro,int ilPro,int liFa);
    void decSeeds(int i);
    void decFol(int i);
    bool hasSeedsLeft();
    virtual bool canLive(char c) = 0;
    virtual ~Seedless();
    virtual Plant* birth() = 0;
};

class Grass : public Seedless{
public:
    Grass();
    bool canGrow(char c);
    bool canLive(char c);
    Plant* birth();
    virtual ~Grass();
};

class Algae : public Seedless{
public:
    Algae();
    bool canGrow(char c);
    bool canLive(char c);
    Plant* birth();
    virtual ~Algae();
};

class Seeded : public Plant{
    int foliage;
    int seeds;
public:
    Seeded(string n,char tok,int lif,int brePro,int ilPro,int liFa,int fol,int se);
    void decSeeds(int i);
    void decFol(int i);
    bool hasSeedsLeft();
    virtual Plant* birth() = 0;
    virtual bool canLive(char c) = 0;
    virtual ~Seeded();
};

class Oak : public Seeded{
public:
    Oak();
    bool canGrow(char c);
    bool canLive(char c);
    Plant* birth();
    virtual ~Oak();
};

class Pine : public Seeded{
public:
    Pine();
    bool canGrow(char c);
    bool canLive(char c);
    Plant* birth();
    virtual ~Pine();
};

class Maple : public Seeded{
public:
    Maple();
    bool canGrow(char c);
    bool canLive(char c);
    Plant* birth();
    virtual ~Maple();
};

#endif
