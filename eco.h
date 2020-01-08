#include"animals.h"
#include"plants.h"
#include"terTile.h"
#include<vector>


class Ecosystem{
    Terrain terrain;
    int terrainSize;
    int dayOfYear;
    int growthPeriod;
    int breedingRepPeriod;
    char season;
    vector<Plant*> plantList;
    vector<Herbivores*> herbList;
    vector<Carnivores*> carnList;
    void generateRiver();
    int newSpot(int& i, int& j);
    void generateLake();
    void generateHills(int n);
    void generateMeadow();
    void placePlants(int g,int a,int o,int p,int m);
    void placeAnimals(int d,int r,int g,int s,int f,int w, int b);
    void plantPlant(int x,int y,Plant* pl);
    void plantAnim(int x,int y,Herbivores* pl);
    void plantAnim(int x,int y,Carnivores* pl);
    bool isNullSpot(int i,int j);
    char nextSeason(char seas);
    void applySeason(char seas);
    void animalSleep();
    void animalWake();
    void dailyReset();
    void animalMovement();
    void animalEating();
    void makeHungry();
    bool isAnimalGrowthPeriod();
    bool isPlantGrowthPeriod();
    bool isPlantBreedRepPeriod();
    bool isHerbBreedRepPeriod();
    bool isCarnBreedRepPeriod();
    void growAnimals();
    void growPlants();
    void checkDeadEntities();
    void animalBreeding();
    void plantBreeding();
    void breedHerbs();
    void breedCarns();
    void breedPlants();
    bool hasFreeSquare(Plant* pl);
    bool inGrid(int x,int y,int& side) const;
    int getXofFreeSquare(Plant* pl);
    int getYofFreeSquare(Plant* pl);
public:
    Ecosystem(int n);
    void mapGenerator(int hills);
    void runEcosystem(int totalDays, char initSeason);
    void printSystem() const;
    void printPlantStatistics() const;
    void printAnimalStatistics() const;
};




