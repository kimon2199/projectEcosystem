#include<iostream>
#include<vector>
#include"terTile.h"

Tile::Tile() : landType('-'), myPlant(NULL) {};
char Tile::getLandType() const {
    return landType;
}
void Tile::setLandType(char& c) {
    landType = c;
}
char Tile::getPlantType() const {
    if (myPlant)
        return myPlant->getToken();
    else
        return '-';
}
void Tile::plantPlant(Plant* pl){
    myPlant = pl;
}

void Tile::plantHerb(Herbivores* anml){
    herbList.push_back(anml);
}
void Tile::plantCarn(Carnivores* anml){
    carnList.push_back(anml);
}
void Tile::remAnimal(Animal* pl){
    for (int i=0;i<herbList.size();i++)
        if (herbList[i]==pl)
            herbList.erase(herbList.begin()+i);
    for (int i=0;i<carnList.size();i++)
        if (carnList[i]==pl)
            carnList.erase(carnList.begin()+i);
}
Plant* Tile::getPlant(){
    return myPlant;
}
vector<Herbivores*> Tile::getHerbs(){
    return herbList;
}
vector<Carnivores*> Tile::getCarns(){
    return carnList;
}
bool Tile::deadPlant() const{
    return myPlant->getLife()<=0;
}
Plant* Tile::removePlant(){
    Plant* tmp = myPlant;
    myPlant = NULL;
    return tmp;
}






Terrain::Terrain(int si) : side(si) {
    map = new Tile*[side];
    for (int i=0; i<side; i++)
        map[i] = new Tile[side];
}
void Terrain::print() const{
    for(int i=0; i<side; i++){
        for(int j=0; j<side; j++)
            cout<< map[i][j].getLandType() << " ";
        cout<<"       ";
        for(int j=0; j<side; j++)
            cout<< map[i][j].getPlantType() << " ";
        cout << endl;
    }
}
void Terrain::alter(int x, int y, char c){
    map[x][y].setLandType(c);
}
bool Terrain::isEmpty(int& i,int& j){
    if (map[i][j].getLandType()=='-')
        return 1;
    return 0;
}
bool Terrain::isPlantless(int i,int j) const{
    if (map[i][j].getPlantType()=='-')
        return 1;
    return 0;
}
char Terrain::landType(int x,int y) const{
        return map[x][y].getLandType();
}
void Terrain::plantPlant(int& x,int& y,Plant* pl){
    map[x][y].plantPlant(pl);
}
void Terrain::plantAnim(int& x,int& y,Herbivores* pl){
    map[x][y].plantHerb(pl);
}
void Terrain::plantAnim(int& x,int& y,Carnivores* pl){
    map[x][y].plantCarn(pl);
}
void Terrain::remAnimal(int x,int y,Animal* pl){
    map[x][y].remAnimal(pl);
}

Plant* Terrain::getPlant(int x,int y){
    return map[x][y].getPlant();
}
vector<Herbivores*> Terrain::getHerbs(int x,int y){
    return map[x][y].getHerbs();
}
vector<Carnivores*> Terrain::getCarns(int x,int y){
    return map[x][y].getCarns();
}
bool Terrain::deadPlant(int& x,int& y) const{
    if (isPlantless(x,y))
        return 0;
    else
        return map[x][y].deadPlant();
}
Plant* Terrain::removePlant(int& x,int& y){
    return map[x][y].removePlant();
}
