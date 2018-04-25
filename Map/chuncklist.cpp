#include "chuncklist.h"
//#include <stdio.h>
#include <stdlib.h>
chunck::chunck(){

}

chunck::chunck(int planetSize, int yLowerBound, int yUpperBound){
    chunck* source = this;
    chunck* start = this;
    for(int i = 0; i < planetSize; i++){
        int value = rand()%yUpperBound;
        start->endingY = value;
        start->endingY += yLowerBound;


        start->next = new chunck();
        start = start->next;
        start->startingY = value;

    }

    start->endingY = source->startingY;
    start->next = source;

}
