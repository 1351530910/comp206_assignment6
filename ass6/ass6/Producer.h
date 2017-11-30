//
//  Producer.h
//  ass6
//
//  Created by Admin on 2017-11-28.
//  Author: Chen He 260743776
//

#ifndef Producer_h
#define Producer_h

#define FILEPATH "/Users/admin/Desktop/Mydata.txt"
#define DATAFILE "/Users/admin/Desktop/data"
#define TURNFILE "/Users/admin/Desktop/turn"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 Producer function that read data from FILEPATH then write to DATAFILE.
 */
void producer(void);


#endif /* Producer_h */
