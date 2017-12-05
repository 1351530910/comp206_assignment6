#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Producer.h"

void producer(void){
    
    //initialization
    FILE * src = fopen(FILEPATH, "rt");
    FILE * turn=NULL;
    char buffer;
    int c = 0;
    
    while (1) {
        //wait consumer 
        do{
            turn = fopen(TURNFILE, "rt");
           
            usleep(1000);
            buffer = fgetc(turn);
        }while(buffer=='1');
        fclose(turn);
        
        //read the next char
        c = fgetc(src);
        
        //end of file, exit program
        if (c==EOF) {
            fclose(src);
            remove(DATAFILE);
            remove(TURNFILE);
            return;
        }

        //write a data file
        FILE* data = fopen(DATAFILE, "wt");
        fprintf(data, "%c",(char)c);
        fclose(data);
        
        //update status
        FILE * turn = fopen(TURNFILE, "w");
        fputc('1',turn);
        fclose(turn);
    }
}
