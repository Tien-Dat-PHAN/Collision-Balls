
/**
  * @file particle.h
 * @brief Including the 9 defined caracters of one particle (x,y,vx,vy,m,r,color,count)\
 * and all functions calculating collsion's time and update the velocities of the particle
 *
 * 
 * 
 *
 * @author Phan Tien Dat
 * @date 11 mars 2022
 */
#ifndef PARTICLE_H
#define PARTICLE_H

#include<stdlib.h>
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>


/* Window size */
#define SIZE 900

typedef struct particle *p_particle;

struct particle{
	double x,y,vx,vy,m,r;
	int color;
	int count;
};

// Update postion of the particle after a time 
void UpdatePosition(p_particle p, double time);

//Caculating collision time between vertical wall and particle
double time_vertical(p_particle p);

//Calculating collision time between horizotal wall and particle
double time_horizontal(p_particle p);

//Update velocity of the particle after collising with vertical wall
void UpVeloc_ver(p_particle p);

//Return the number of collision  
int count(p_particle a);

//Update velocity of the particle after collising with horizontal wall
void UpVeloc_hor(p_particle p);

//Calculating collision time between two particles
double time_2particles(p_particle p1, p_particle p2);

//Update velocities of two particles after collsion
void UpVeloc_2particles(p_particle p1, p_particle p2);

#endif
