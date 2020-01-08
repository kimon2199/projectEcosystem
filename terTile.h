#include"animals.h"
#include"plants.h"
#include<vector>

#ifndef TERTILE_H
#define TERTILE_H

class Tile{
    char landType;
    Plant* myPlant;
    vector<Herbivores*> herbList;
    vector<Carnivores*> carnList;
public:
    Tile();
    char getLandType() const;
    void setLandType(char& c);
    char getPlantType() const;
    void plantPlant(Plant* pl);
    void printAnimals(int i,int j);
    void plantHerb(Herbivores* anml);
    void plantCarn(Carnivores* anml);
    void remAnimal(Animal* pl);
    Plant* getPlant();
    vector<Herbivores*> getHerbs();
    vector<Carnivores*> getCarns();
    bool deadPlant() const;
    Plant* removePlant();
};

class Terrain{
    int side;
    Tile** map;
public:
    Terrain(int si);
    void print() const;
    void alter(int x, int y, char c);
    bool isEmpty(int& i,int& j);
    bool isPlantless(int i,int j) const;
    char landType(int x,int y) const;
    void plantPlant(int& x,int& y,Plant* pl);
    void plantAnim(int& x,int& y,Herbivores* pl);
    void plantAnim(int& x,int& y,Carnivores* pl);
    void remAnimal(int x,int y,Animal* pl);
    Plant* getPlant(int x,int y);
    vector<Herbivores*> getHerbs(int x,int y);
    vector<Carnivores*> getCarns(int x,int y);
    bool deadPlant(int& x,int& y) const;
    Plant* removePlant(int& x,int& y);
};

#endif
