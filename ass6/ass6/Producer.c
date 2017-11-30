//
//  Producer.c
//  ass6
//
//  Created by Admin on 2017-11-28.
//  Author : Chen He 260743776
//

#include "Producer.h"

void producer(void){
    
    //initialization
    FILE * src = fopen(FILEPATH, "rt");
    FILE * turn = NULL;
    int c = 0;
    
    while (1) {
        //wait consumer to delete the file
        do{
            
            fclose(turn);
            turn = NULL;
            turn = fopen(TURNFILE, "r");
            usleep(1000);
        }while(turn);
        
        //read the next char
        c = fgetc(src);
        
        //end of file, exit program
        if (c==EOF) {
            remove(DATAFILE);
            return;
        }
        
        //write a data file
        FILE* data = fopen(DATAFILE, "wt");
        fprintf(data, "%c",(char)c);
        fclose(data);
        
        //update status
        FILE * t = fopen(TURNFILE, "wt");
        fclose(t);
    }
}
