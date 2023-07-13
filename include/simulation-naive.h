

/**
 * @file simulation-naive.h
 * @brief Starting simulation when we have all necaissaire informations(time limit, period, number of particle and their cacracters)
 * 
 * 
 *
 * @author Phan Tien Dat
 * @date 11 mars 2022
 */ 
#ifndef SIMULATION_NAIVE
#define SIMULATION_NAIVE

#include"disc.h"
#include"particle.h"
#include"event.h"
#include"loader.h"



//draw particle 
void draw_particle(int nb, p_particle p[nb]);



// function simulate the collisions
void simulate(double time_limit, double period,int nb, p_particle p[nb]);

#endif
