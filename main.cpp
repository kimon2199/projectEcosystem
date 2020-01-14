#include"eco.h"
#include<cstdlib>

int main(int argc, char *argv[]){
    std::srand(time(NULL));
    if (argc != 5){
        printf("Wrong number of arguments. Try:\n<terrain dimentions> <number of mountains> <days> <season(w, p, u or f)>\n");
        return -1;
    }
    
    Ecosystem eco(std::atoi(argv[1]));         //user input     terrain dimentions
    eco.mapGenerator(std::atoi(argv[2]));       //user input     number of mountains
    eco.runEcosystem(std::atoi(argv[3]),argv[4][0]);  //user input     days,season
    eco.printSystem();
}
