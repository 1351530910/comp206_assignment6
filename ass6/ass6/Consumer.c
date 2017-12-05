#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Consumer.h"
void consumer(){
    // initialization
    char temp;
    char buffer;
    FILE *turn=NULL;
    while (1) {
        //wait producer to create the turnfile
        do{
            FILE * data;
            if ((data=fopen(DATAFILE, "r"))==NULL) return;  //the condition to end this process
            turn = fopen(TURNFILE,"rt");
            buffer = fgetc(turn);
            fclose(data);
            fclose(turn);
            usleep(5000);   //give producer a little bit of time
        }while(buffer == '0');
        
        //read data from data file then print to stdout
        FILE * data = fopen(DATAFILE, "rt");
        temp = fgetc(data);
        printf("%c",temp);
        fclose(data);
        
        //update status
        turn = fopen(TURNFILE, "w");
        fputc('0',turn);
        fclose(turn);
    }
}
