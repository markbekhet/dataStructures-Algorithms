#include "recursive.h"
#include <string>
#include <iostream>
#include <cassert>

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Please enter a number as an argument \n");
        exit(-1);
    }
    int number = std::stoi(argv[1]) - std::stoi("0");
    printf("%d \n", fibRec(number));
    towerOfHanoi(16, 'a', 'b', 'c');


    return 0;
}