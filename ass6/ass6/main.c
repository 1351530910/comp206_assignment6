#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Producer.h"
#include "Consumer.h"

int main(int argc, const char * argv[]) {
    //create files
    fclose(fopen(DATAFILE, "w"));
    FILE * temp = fopen(TURNFILE, "w");
    fputc('0', temp);
    fclose(temp);
    //create process
     int pid = fork();
    
    //just to make sure in case fork failed for some reason
    if (pid<0) {
        printf("fork failed");
        exit(0);
    }
    
    //main function
    if (pid>0) {
        producer();
        usleep(2000);
	 }
	if(pid==0) {
        consumer();
    }
    
    return 0;
}
