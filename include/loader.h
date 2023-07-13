
/**
 * @file loader.h
 * @brief Loading the defined caracters of the particle in the file data
 *
 * 
 * 
 *
 * @author Phan Tien Dat
 * @date 11 mars 2022
 */ 
#ifndef LOADER_H
#define LOADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"particle.h"


// Calculating the number of particle
int num_particle(FILE *p_file);

//Loading the defined features of each parcile
/*
@para: FILE,  p_arr: array of p_particle pointer NULL

return: the defined particle fetures in the file will be saved in p_arr[] 
*/
void loader_file(FILE *p_file, p_particle p_arr[]);

#endif