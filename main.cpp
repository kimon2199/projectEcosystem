#include"eco.h"
#include<cstdlib>

int main(){
    std::srand(time(NULL));
    Ecosystem eco(15);         //user input     terrain dimentions
    eco.mapGenerator(3);       //user input     number of mountains
    eco.runEcosystem(20,'p');  //user input     days,season
    eco.printSystem();
}
