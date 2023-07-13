/**
 * @file test-particle.c
 *
 * @brief Test the functions including in particle.h work or not
 * 
 * Command line:   ./test-particle
 *
 * @author Phan Tien Dat
 * @date 15/03/2022
 *
 */
#include<assert.h>

#include"particle.h"

void test_particle(){
	printf("|  Test for time ....\n");
	p_particle p[8];
	
	
	p[0] = malloc(sizeof(struct particle));
	p[0]->x = 0.25;p[0]->y = 0.25;p[0]->vx = 0.5;p[0]->vy = 0;p[0]->m = 0.5;
	p[0]->r = 1E-2;
	
	p[1] = malloc(sizeof(struct particle));
	p[1]->x = 0.25;p[1]->y = 0.25;p[1]->vx = -0.5;p[1]->vy = 0;p[1]->m = 0.5;
	p[1]->r = 1E-2;
	
	p[2] = malloc(sizeof(struct particle));
	p[2]->x = 0.25;p[2]->y = 0.25;p[2]->vx = 0;p[2]->vy = 0.5;p[2]->m = 0.5;
	p[2]->r = 1E-2;
	
	p[3] = malloc(sizeof(struct particle));
	p[3]->x = 0.25;p[3]->y = 0.25;p[3]->vx = 0;p[3]->vy = -0.5;p[3]->m = 0.5;
	p[3]->r = 1E-2;
	
	p[4] = malloc(sizeof(struct particle));
	p[4]->x = 0.25;p[4]->y = 0.25;p[4]->vx = 0.25;p[4]->vy = -0.4;p[4]->m = 0.5;
	p[4]->r = 1E-2;	
	
	p[5] = malloc(sizeof(struct particle));
	p[5]->x = 0.5;p[5]->y = 0.25;p[5]->vx = 0;p[5]->vy = 0;p[5]->m = 0.8;
	p[5]->r = 5E-3;
	
	p[6] = malloc(sizeof(struct particle));
	p[6]->x = 0.75;p[6]->y = 0.25;p[6]->vx = -0.25;p[6]->vy = 0;p[6]->m = 0.5;
	p[6]->r = 1E-2;
	
	p[7] = malloc(sizeof(struct particle));
	p[7]->x = 0.6;p[7]->y = 0.8;p[7]->vx = 0.25;p[7]->vy = -0.4;p[7]->m = 0.8;
	p[7]->r = 5E-3;
	
	
	assert(time_vertical(p[0]) == 1.48);
	assert(time_vertical(p[2]) == INFINITY);
	assert(time_vertical(p[3]) == INFINITY);
	assert(time_vertical(p[4]) == 2.96);
	printf("Tests for time vertical have done ....\n");
	
	assert(time_horizontal(p[0]) == INFINITY);
	assert(time_horizontal(p[1]) == INFINITY);
	assert(time_horizontal(p[2]) == 1.48);
	assert(time_horizontal(p[3]) == 0.48);
	assert(time_horizontal(p[4]) == 0.6);
	printf("Tests for time horizontal have done ....\n");
	
	//printf("t =  p[0]-p[5] = %lf\n",time_2particles(p[6],p[7]));
	assert(time_2particles(p[6],p[7]) == INFINITY);
	assert(fabs(time_2particles(p[0],p[7]) - 1.352274) < 1E-6);
	assert(fabs(time_2particles(p[0],p[6]) - 0.64 ) < 1E-6);
	assert(fabs(time_2particles(p[0],p[5]) - 0.47 ) < 1E-6);
	
	
	
	printf("Tests for time 2 particles have done ....\n");
	printf("|---------------------------------------------|\n");
	printf("|  Test for velocities ....\n");
	// Starting test veloc wall-particle
	UpVeloc_ver(p[1]);
	UpVeloc_hor(p[4]);
	assert(p[1]->vx == 0.5 );
	assert(p[4]->vy == 0.4 );
	printf("Tests for horizontal veloc have done...\n");
	printf("Tests for vertial veloc have done...\n");
	
	// Starting test particle-particle (p1 - p6)
	UpVeloc_2particles(p[0],p[5]);
	
	assert(fabs(p[0]->vx + 0.115385) <= 1E-6); // Verify v1->x  = 0.115385
	assert(fabs(p[0]->vy - 0) < 1E-6);			// Verify v1->y  = 0
	assert(fabs(p[5]->vx - 0.384615) <=1E-6);  // Verify v6->y  = 0.38465
	assert(fabs(p[5]->vy - 0) < 1E-6);         // Verify v6->y  = 0
	
	// Starting test particle-particle (p1 - p7)
	p[0]->x = 0.25;p[0]->y = 0.25;p[0]->vx = 0.5;p[0]->vy = 0;p[0]->m = 0.5;
	p[0]->r = 1E-2;

	p[6]->x = 0.75;p[6]->y = 0.25;p[6]->vx = -0.25;p[6]->vy = 0;p[6]->m = 0.5;
	p[6]->r = 1E-2;

	UpVeloc_2particles(p[0],p[6]);

	assert(fabs(p[0]->vx + 0.25) <= 1E-6); // Verify v1->x  = -0.25
	assert(fabs(p[0]->vy - 0) < 1E-6);     // Verify v1->y  = 0
	assert(fabs(p[6]->vx - 0.5) <=1E-6);   // Verify v7->x  = 0.5
	assert(fabs(p[6]->vy - 0) < 1E-6);     // Verify v7->y  = 0
	printf("Tests for veloc 2 particles have done...\n");
	
	for(int i =0; i<8;i++)
	{
		free(p[i]);
	}
}

int main(){
	printf("Starting test_particle....\n");
	
	test_particle();
	
	printf("------> OK\n");
	
	
	
}









