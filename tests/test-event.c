
/**
 * @file test-event.c
 *
 * @brief Test is that functions in event.h ot not
 * 
 * Command line:   ./test-event
 *
 * @author Phan Tien Dat
 *@date 15/03/2022
 */
#include"event.h"


int main(){

	
	p_particle p1,p2;
	double t = 2.0;
	//two defined particles previosly
	printf("Starting test event:\n\n");
	p1 = malloc(sizeof(struct particle));
	p1->x = 0.25;p1->y = 0.25;p1->vx = 0.5;p1->vy = 0;p1->m = 0.5;
	p1->r = 1E-2;

	p2 = malloc(sizeof(struct particle));
	p2->x = 0.6;p2->y = 0.8;p2->vx = 0.25;p2->vy = -0.4;p2->m = 0.8;
	p2->r = 5E-3;
	
	p_event e1 = create_event(t, NULL, p1);//event collision with horizontal wall
	
	assert(verify_event(e1));
	p1->count += 1;
	
	assert(verify_event(e1) == false);
	printf("Test for event wall-particle have done...\n");

	// starting test particle-particle
	p_event e2 = create_event(t, p1, p2);
	assert(verify_event(e2)); 
	p2->count +=1;
	assert(verify_event(e2) == false);
	printf("Test for event particle-particle have done...\n\n");
	printf("-------> Test successful\n");
	
	
	free(p1);
	free(p2);
	free(e1);	
	free(e2);	


}
