//
//  main.c
//  ass6
//
//  Created by Admin on 2017-11-28.
//	Author: Chen He 260743776, YuTong Yan 260716973
//

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include "Producer.h"
#include "Consumer.h"

int main(int argc, const char * argv[]) {
    
    //create a data file so consumer wont end before starting
    fclose(fopen(DATAFILE, "w"));
    
    //create process
    int pid = fork();
    
    //just to make sure in case fork failed for some reason
    if (pid<0) {
        printf("fork failed");
        exit(0);
    }
    
    //main function
    if (pid) {
        producer();
    }else{
        consumer();
    }
    
    
    printf("\n");
    return EXIT_SUCCESS;
}
