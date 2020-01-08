#include"eco.h"
#include"animals.h"
#include"plants.h"
#include"terTile.h"
#include<cstdlib>
#include<limits>
#include<vector>


    void Ecosystem::generateRiver() {
        int spot = 5 + (rand() % (terrainSize-5-5+1));
        for (int i=0; i<terrainSize; i++){
            terrain.alter(i,spot,'#');
            spot += newSpot(i,spot);
        }
    }
    int Ecosystem::newSpot(int& i, int& j) {
        if ((rand()%100)<30){
            int x = rand()%4;
            if (x==0){
                terrain.alter(i,j+1,'#');
                return 1;
            }
            else if (x==1){
                terrain.alter(i,j+1,'#');
                terrain.alter(i,j+2,'#');
                return 2;
            }
            else if (x==2){
                terrain.alter(i,j-1,'#');
                return -1;
            }
            else if (x==3){
                terrain.alter(i,j-1,'#');
                terrain.alter(i,j-2,'#');
                return -2;
            }
        }
        return 0;
    }
    void Ecosystem::generateLake() {
        int lakeSize = 3 + (rand() % (terrainSize/2-3+1));
        int x = 3 + (rand() % (terrainSize-lakeSize-3+1));
        int y = 3 + (rand() % (terrainSize-lakeSize-3+1));
        for (int i=x; i<x+lakeSize;i++)
            for (int j=y; j<y+lakeSize; j++)
                terrain.alter(i,j+1,'#');
    }
    void Ecosystem::generateHills(int n){
        for (int i=0; i<n; i++){
            int size = 2 + (rand() % (4-2+1));
            int hillStartingX;
            int hillStartingY;
            do{
                hillStartingX = rand() % (terrainSize-size+1);
                hillStartingY = rand() % (terrainSize-size+1);
            } while (!terrain.isEmpty(hillStartingX,hillStartingY));
            for (int i=hillStartingX; i<size+hillStartingX; i++)
                for (int j=hillStartingY; j<size+hillStartingY; j++)
                    if (isNullSpot(i,j))
                        terrain.alter(i,j,'^');
        }
    }
    void Ecosystem::generateMeadow(){
        for (int i=0; i<terrainSize; i++)
            for (int j=0; j<terrainSize; j++)
                if (isNullSpot(i,j))
                    terrain.alter(i,j,'"');
    }
    void Ecosystem::placePlants(int g,int a,int o,int p,int m){ //G,A,O,P,M
        for(int i=0; i<g; i++){
            Grass* pln = new Grass();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!terrain.isPlantless(x,y) || !pln->canGrow(terrain.landType(x,y)));
            plantPlant(x,y,pln);
        }
        for(int i=0; i<a; i++){
            Algae* pln = new Algae();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!terrain.isPlantless(x,y) || !pln->canGrow(terrain.landType(x,y)));
            plantPlant(x,y,pln);
        }
        for(int i=0; i<o; i++){
            Oak* pln = new Oak();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!terrain.isPlantless(x,y) || !pln->canGrow(terrain.landType(x,y)));
            plantPlant(x,y,pln);
        }
        for(int i=0; i<p; i++){
            Pine* pln = new Pine();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!terrain.isPlantless(x,y) || !pln->canGrow(terrain.landType(x,y)));
            plantPlant(x,y,pln);
        }
        for(int i=0; i<m; i++){
            Maple* pln = new Maple();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!terrain.isPlantless(x,y) || !pln->canGrow(terrain.landType(x,y)));
            plantPlant(x,y,pln);
        }
    }
    void Ecosystem::placeAnimals(int d,int r,int g,int s,int f,int w, int b){  //Deer,Rabb,Grou,Sal,Fox,Wolf,Bear
        for(int i=0; i<d; i++){
            Deer* anml = new Deer();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!anml->canStartAt(terrain.landType(x,y)));
            plantAnim(x,y,anml);
        }
        for(int i=0; i<r; i++){
            Rabbit* anml = new Rabbit();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!anml->canStartAt(terrain.landType(x,y)));
            plantAnim(x,y,anml);
        }
        for(int i=0; i<g; i++){
            Groundhog* anml = new Groundhog();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!anml->canStartAt(terrain.landType(x,y)));
            plantAnim(x,y,anml);
        }
        for(int i=0; i<s; i++){
            Salmon* anml = new Salmon();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!anml->canStartAt(terrain.landType(x,y)));
            plantAnim(x,y,anml);
        }
        for(int i=0; i<f; i++){
            Fox* anml = new Fox();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!anml->canStartAt(terrain.landType(x,y)));
            plantAnim(x,y,anml);
        }
        for(int i=0; i<w; i++){
            Wolf* anml = new Wolf();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!anml->canStartAt(terrain.landType(x,y)));
            plantAnim(x,y,anml);
        }
        for(int i=0; i<b; i++){
            Bear* anml = new Bear();
            int x,y;
            do{
                x = rand() % terrainSize;
                y = rand() % terrainSize;
            } while(!anml->canStartAt(terrain.landType(x,y)));
            plantAnim(x,y,anml);
        }
    }
    void Ecosystem::plantPlant(int x,int y,Plant* pl){
        terrain.plantPlant(x,y,pl);
        pl->setCoords(x,y);
        plantList.push_back(pl);
    }
    void Ecosystem::plantAnim(int x,int y,Herbivores* pl){
        terrain.plantAnim(x,y,pl);
        pl->setCoords(x,y);
        herbList.push_back(pl);
    }
    void Ecosystem::plantAnim(int x,int y,Carnivores* pl){
        terrain.plantAnim(x,y,pl);
        pl->setCoords(x,y);
        carnList.push_back(pl);
    }
    bool Ecosystem::isNullSpot(int i,int j){
        return terrain.isEmpty(i,j);
    }
    char Ecosystem::nextSeason(char seas){
        switch (seas) {
            case 'p': return 'u';
            case 'u': return 'f';
            case 'f': return 'w';
            case 'w': return 'p';
        }
        return 0;
    }
    void Ecosystem::applySeason(char seas){
        printSystem();
        switch (seas) {
            case 'p': Plant::setGP(5);
                Animal::setGP(20);
                Plant::setBRP(10);
                Herbivores::setBRP(12);
                Carnivores::setBRP(11);
                animalWake();
                break;
            case 'u': Plant::setGP(10);
                Animal::setGP(30);
                Plant::setBRP(10);
                Herbivores::setBRP(8);
                Carnivores::setBRP(9);
                break;
            case 'f': Plant::setGP(numeric_limits<int>::max());
                Animal::setGP(15);
                Plant::setBRP(20);
                Herbivores::setBRP(5);
                Carnivores::setBRP(9);
                break;
            case 'w': Plant::setGP(10);
                Animal::setGP(30);
                Plant::setBRP(numeric_limits<int>::max());
                Herbivores::setBRP(18);
                Carnivores::setBRP(10);
                animalSleep();
                break;
        }
    }
    void Ecosystem::animalSleep(){
        for (int i=0; i<herbList.size();i++)
            if (herbList[i]->canHibernate())
                herbList[i]->sleep();
        for (int i=0; i<carnList.size();i++)
            if (carnList[i]->canHibernate())
                carnList[i]->sleep();
    }
    void Ecosystem::animalWake(){
        for (int i=0; i<herbList.size();i++)
            if (herbList[i]->canHibernate())
                herbList[i]->wake();
        for (int i=0; i<carnList.size();i++)
            if (carnList[i]->canHibernate())
                carnList[i]->wake();
    }
    void Ecosystem::dailyReset(){
        dayOfYear++;
        makeHungry();
        if(isAnimalGrowthPeriod())
            growAnimals();
        if(isPlantGrowthPeriod())
            growPlants();
        if(dayOfYear % 30 == 0)
            applySeason(nextSeason(season));
    }
    void Ecosystem::animalMovement(){
        for (int i=0; i<herbList.size();i++){
            int x = herbList[i]->getX();
            int y = herbList[i]->getY();
            char ground = terrain.landType(x,y);
            terrain.remAnimal(x,y,herbList[i]);
            herbList[i]->move(x,y,terrainSize,ground);
            terrain.plantAnim(x,y,herbList[i]);
            herbList[i]->setCoords(x,y);
        }
        for (int i=0; i<carnList.size();i++){
            int x = carnList[i]->getX();
            int y = carnList[i]->getY();
            char ground = terrain.landType(x,y);
            terrain.remAnimal(x,y,carnList[i]);
            carnList[i]->move(x,y,terrainSize,ground);
            terrain.plantAnim(x,y,carnList[i]);
            carnList[i]->setCoords(x,y);
        }
    }
    void Ecosystem::animalEating(){
        for (int i=0; i<herbList.size();i++){
            if (herbList[i]->needsFood()&&!(herbList[i]->isDead())&&!terrain.isPlantless(herbList[i]->getX(),herbList[i]->getY())){
                Plant* pl = terrain.getPlant(herbList[i]->getX(),herbList[i]->getY());
                int sz = pl->getSize();
                char c = pl->getToken();
                if (herbList[i]->canEat(c,sz)){
                    if (c=='A'||c=='G'){
                        pl->decLife(herbList[i]->eat());
                    }
                    else{
                        if (pl->hasSeedsLeft())
                            pl->decSeeds(herbList[i]->eat());
                        else
                            pl->decFol(herbList[i]->eat());
                    }
                }
            }
        }
        for (int i=0; i<carnList.size();i++){
            if (!(carnList[i]->isDead())){
                vector<Herbivores*> tmpHerbList = terrain.getHerbs(carnList[i]->getX(),carnList[i]->getY());
                for (int j=0; j<tmpHerbList.size();j++){
                    string nom = tmpHerbList[j]->getName();
                    int sz = tmpHerbList[j]->getSize();
                    int spd = tmpHerbList[j]->getSpeed();
                    if (carnList[i]->canEat(nom,sz,spd)){
                        carnList[i]->eat();
                        tmpHerbList[j]->die();
                    }
                }
                if (carnList[i]->isVeryHungry()){
                    vector<Carnivores*> tmpCarnList = terrain.getCarns(carnList[i]->getX(),carnList[i]->getY());
                    for (int j=0; j<tmpCarnList.size();j++){
                        if (tmpCarnList[j]!=carnList[i] && !tmpCarnList[j]->isDead()){
                            string nom = tmpCarnList[j]->getName();
                            int sz = tmpCarnList[j]->getSize();
                            int spd = tmpCarnList[j]->getSpeed();
                            int def = tmpCarnList[j]->getDefence();
                            if (carnList[i]->canKill(nom,sz,spd,def)){
                                carnList[i]->eat();
                                tmpCarnList[j]->die();
                            }
                        }
                    }
                }
            }
        }
    }
    void Ecosystem::makeHungry(){
        for (int i=0; i<herbList.size();i++){
            if (herbList[i]->needsFood())
                herbList[i]->makeHngr();
            herbList[i]->incrDsf();
        }
        for (int i=0; i<carnList.size();i++){
            carnList[i]->makeHngr();
            carnList[i]->incrDsf();
        }
    }
    bool Ecosystem::isAnimalGrowthPeriod(){
        return (dayOfYear % Animal::getGP()) == 0;
    }
    bool Ecosystem::isPlantGrowthPeriod(){
        return (dayOfYear % Plant::getGP()) == 0;
    }
    bool Ecosystem::isPlantBreedRepPeriod(){
        return (dayOfYear % Plant::getBRP()) == 0;
    }
    bool Ecosystem::isHerbBreedRepPeriod(){
        return (dayOfYear % Herbivores::getBRP()) == 0;
    }
    bool Ecosystem::isCarnBreedRepPeriod(){
        return (dayOfYear % Carnivores::getBRP()) == 0;
    }
    void Ecosystem::growAnimals(){
        for (int i=0; i<herbList.size();i++)
            herbList[i]->raise();
        for (int i=0; i<carnList.size();i++)
            carnList[i]->raise();
    }
    void Ecosystem::growPlants(){
        for (int i=0; i<plantList.size();i++)
            plantList[i]->raise();
    }
    void Ecosystem::checkDeadEntities(){
        for(int i=0; i<terrainSize; i++)
            for(int j=0; j<terrainSize; j++){
                if (terrain.deadPlant(i,j)){
                    Plant* tmp = terrain.removePlant(i,j);
                    for (int i=0;i<plantList.size();i++)
                        if (plantList[i]==tmp)
                            plantList.erase(plantList.begin()+i);
                    delete tmp;
                }
            }
        vector<Herbivores*> tempHerb;
        for(int i=0;i<herbList.size();i++){
            if (herbList[i]->getDsf()>9)
                herbList[i]->die();
            if (herbList[i]->isDead()){
                Herbivores* tmp = herbList[i];
                terrain.remAnimal(tmp->getX(),tmp->getY(),tmp);
                tempHerb.push_back(tmp);
                delete tmp;
            }
        }
        for(int i=0;i<tempHerb.size();i++)
            for(int j=0;j<herbList.size();j++)
                if(tempHerb[i]==herbList[j])
                    herbList.erase(herbList.begin()+j);
        vector<Carnivores*> tempCarn;
        for(int i=0;i<carnList.size();i++){
            if (carnList[i]->getDsf()>9)
                carnList[i]->die();
            if (carnList[i]->isDead()){
                Carnivores* tmp = carnList[i];
                terrain.remAnimal(tmp->getX(),tmp->getY(),tmp);
                tempCarn.push_back(tmp);
                delete tmp;
            }
        }
        for(int i=0;i<tempCarn.size();i++)
            for(int j=0;j<carnList.size();j++)
                if(tempCarn[i]==carnList[j])
                    carnList.erase(carnList.begin()+j);
    }
    void Ecosystem::animalBreeding(){
        if (isHerbBreedRepPeriod())
            breedHerbs();
        if (isCarnBreedRepPeriod())
            breedCarns();
    }
    void Ecosystem::plantBreeding(){
        if (isPlantBreedRepPeriod())
            breedPlants();
    }
    void Ecosystem::breedHerbs(){
        for (int i=0; i<herbList.size();i++){
            if (herbList[i]->isAdult() && herbList[i]->isAwake()){
                plantAnim(herbList[i]->getX(),herbList[i]->getY(),herbList[i]->birth());
            }
        }
    }
    void Ecosystem::breedCarns(){
        for (int i=0; i<carnList.size();i++)
            if (carnList[i]->isAdult() && carnList[i]->isAwake()){
                plantAnim(carnList[i]->getX(),carnList[i]->getY(),carnList[i]->birth());
            }
    }
    void Ecosystem::breedPlants(){
        vector<int> Xs;
        vector<int> Ys;
        vector<Plant*> plantsToBeAdded;
        for (int i=0; i<plantList.size();i++){
            if (rand()%100<=plantList[i]->getBreedProb() && hasFreeSquare(plantList[i])){
                int x = getXofFreeSquare(plantList[i]);
                int y = getYofFreeSquare(plantList[i]);
                Xs.push_back(x);
                Ys.push_back(y);
                plantsToBeAdded.push_back(plantList[i]->birth());
            }
        }
        for (int i=0;i<Xs.size();i++)
            if (inGrid(Xs[i],Ys[i],terrainSize))
                plantPlant(Xs[i],Ys[i],plantsToBeAdded[i]);
    }
    bool Ecosystem::hasFreeSquare(Plant* pl){
        int x = pl->getX();
        int y = pl->getY();
        if (inGrid(x,y-1,terrainSize))
            if(terrain.isPlantless(x,y-1)&&pl->canLive(terrain.landType(x,y-1)))
                return 1;
        if (inGrid(x,y+1,terrainSize))
            if(terrain.isPlantless(x,y+1)&&pl->canLive(terrain.landType(x,y+1)))
                return 1;
        if (inGrid(x+1,y,terrainSize))
            if(terrain.isPlantless(x+1,y)&&pl->canLive(terrain.landType(x+1,y)))
                return 1;
        if (inGrid(x-1,y,terrainSize))
            if(terrain.isPlantless(x-1,y)&&pl->canLive(terrain.landType(x-1,y)))
                return 1;
        return 0;
    }
    bool Ecosystem::inGrid(int x,int y,int& side) const{
        return x>=0 && y>=0 && x<side && y<side;
    }
    int Ecosystem::getXofFreeSquare(Plant* pl){
        int x = pl->getX();
        int y = pl->getY();
        if (inGrid(x,y-1,terrainSize))
            if(terrain.isPlantless(x,y-1)&&pl->canLive(terrain.landType(x,y-1)))
                return x;
        if (inGrid(x,y+1,terrainSize))
            if(terrain.isPlantless(x,y+1)&&pl->canLive(terrain.landType(x,y+1)))
                return x;
        if (inGrid(x+1,y,terrainSize))
            if(terrain.isPlantless(x+1,y)&&pl->canLive(terrain.landType(x+1,y)))
                return x+1;
        if (inGrid(x-1,y,terrainSize))
            if(terrain.isPlantless(x-1,y)&&pl->canLive(terrain.landType(x-1,y)))
                return x-1;
        return 0;
    }
    int Ecosystem::getYofFreeSquare(Plant* pl){
        int x = pl->getX();
        int y = pl->getY();
        if (inGrid(x,y-1,terrainSize))
            if(terrain.isPlantless(x,y-1)&&pl->canLive(terrain.landType(x,y-1)))
                return y-1;
        if (inGrid(x,y+1,terrainSize))
            if(terrain.isPlantless(x,y+1)&&pl->canLive(terrain.landType(x,y+1)))
                return y-1;
        if (inGrid(x+1,y,terrainSize))
            if(terrain.isPlantless(x+1,y)&&pl->canLive(terrain.landType(x+1,y)))
                return y;
        if (inGrid(x-1,y,terrainSize))
            if(terrain.isPlantless(x-1,y)&&pl->canLive(terrain.landType(x-1,y)))
                return y;
        return 0;
    }
    Ecosystem::Ecosystem(int n): terrainSize(n), dayOfYear(1), terrain(n) {};
    void Ecosystem::mapGenerator(int hills){
        generateRiver();
        generateLake();
        generateHills(hills);
        generateMeadow();
        placePlants(50,25,10,10,10); //user input   G,A,O,P,M
        placeAnimals(13,10,10,50,0,0,4); //Deer,Rabb,Grou,Sal,Fox,Wolf,Bear
    }
    void Ecosystem::runEcosystem(int totalDays, char initSeason) {
        season = initSeason;
        applySeason(season);
        for(int i=0;i<totalDays;i++){
            dailyReset();
            for(int j=0; j<12; j++){
                animalMovement();
                animalEating();
            }
            checkDeadEntities();
            animalBreeding();
            plantBreeding();
            
        }
    }
    void Ecosystem::printSystem() const {
        cout<<endl<<"******************"<<endl;
        cout<<"     Day   "<<dayOfYear<<endl;
        cout<<"******************"<<endl;
        terrain.print();
        cout<< "Total num of Plants:     "<< plantList.size()<<endl;
        cout<< "Total num of Animals:    "<< carnList.size()+herbList.size()<<endl;
        cout<< "Total num of Herbivores: "<< herbList.size()<<endl;
        cout<< "Total num of Carnivores: "<< carnList.size()<<endl<<endl;
        printPlantStatistics();
        printAnimalStatistics();
    }
    void Ecosystem::printPlantStatistics() const{
        int a[5];
        for(int i=0; i<5;i++)
            a[i]=0;
        for (int i=0; i<plantList.size();i++){
            switch (plantList[i]->getToken()) {
                case 'G': a[0]++;
                    break;
                case 'A': a[1]++;
                    break;
                case 'O': a[2]++;
                    break;
                case 'P': a[3]++;
                    break;
                case 'M': a[4]++;
                    break;
            }
        }
        cout<<"Grass:  "<<a[0]<<endl;
        cout<<"Algae:  "<<a[1]<<endl;
        cout<<"Oak:    "<<a[2]<<endl;
        cout<<"Pine:   "<<a[3]<<endl;
        cout<<"Maple:  "<<a[4]<<endl;
    }
    void Ecosystem::printAnimalStatistics() const{
        int a[7];
        for(int i=0; i<7;i++)
            a[i]=0;
        for (int i=0; i<herbList.size();i++){
            if (herbList[i]->getName().compare("Deer")==0)
                a[0]++;
            else if (herbList[i]->getName().compare("Rabbit")==0)
                a[1]++;
            else if (herbList[i]->getName().compare("Groundhog")==0)
                a[2]++;
            else if (herbList[i]->getName().compare("Salmon")==0)
                a[3]++;
        }
        for (int i=0; i<carnList.size();i++){
            if (carnList[i]->getName().compare("Fox")==0)
                a[4]++;
            else if (carnList[i]->getName().compare("Wolf")==0)
                a[5]++;
            else if (carnList[i]->getName().compare("Bear")==0)
                a[6]++;
        }
        cout<<endl<<"Deer:         "<<a[0]<<endl;
        cout<<"Rabbit:       "<<a[1]<<endl;
        cout<<"Groundhog:    "<<a[2]<<endl;
        cout<<"Salmon:       "<<a[3]<<endl;
        cout<<"Fox:          "<<a[4]<<endl;
        cout<<"Wolf:         "<<a[5]<<endl;
        cout<<"Bear:         "<<a[6]<<endl;
    }



