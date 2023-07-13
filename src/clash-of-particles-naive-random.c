/**
 * @file clash-of-particles-naive-random.c
 *
 * @brief Sample program simulating naive collision between random particles 
 * 
 * Command line: ./clash-of-particles-naive-random
 *
 * @author Phan Tien Dat
 * @date 15/03/2022
 *
 */
#include "simulation-naive.h"
#include "disc.h"
#include<math.h>



//initial the particles 
void generate_particle(int nb, p_particle p[nb], unsigned int seed)
{
     srand(seed);
    
    for (int i=0; i<nb; i++) {
        p[i] = malloc(sizeof(struct particle));
        p[i]->x = (rand()%1000000)/1000000.0;
        p[i]->y = (rand()%1000000)/1000000.0;
        p[i]->r = (4 + rand() % 7)/1000.0;
        double v = (-5 + rand() % 11) / 10000.0;    // v in [0.5 .. 1.0]
        double ang = (rand() % 360) / 360.0 * 2 * 3.141592654;
        p[i]->vx = v * cos(ang);
        p[i]->vy = v * sin(ang);
        p[i]->color = 1 + rand()%7;
        p[i]->m = (4 + rand()%5)/10.0;
    }
}

int main(){

	int nb;
	printf("How many particles: \n");
	scanf("%d",&nb);
	
	CreateWindow("Thai Ngoc Anh", SIZE, SIZE);
	
	p_particle p[nb];
	// generating nb particles
	
	generate_particle(nb, p, 6502);
	printf("x %lf\n", p[0]->x);
	printf("y %lf\n", p[0]->y);
	printf("vx %lf\n", p[0]->vx);
	printf("vy %lf\n", p[0]->vy);
	printf("r %lf\n", p[0]->r);
	printf("m %lf\n", p[0]->m);
	printf("color %d\n", p[0]->color);
	//-------------------------------------------------------
	double time_limit = 50000.0;
	double period = 2.0;
	simulate(time_limit, period, nb, p);
	//-------------------------------------------------------
	
	CloseWindow();
	
	for(int i = 0; i<nb;i++){
		free(p[i]);
	}

}

