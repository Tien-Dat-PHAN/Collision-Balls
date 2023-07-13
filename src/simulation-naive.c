

/**
 * @file simulation-naive.c
 *
 * @brief Program to simulate naivement the collision between the particles
 * 
 *
 * @author Phan Tien Dat
 *@date 15/03/2022
 */

#include "simulation-naive.h"
#include "disc.h"

void draw_particle(int nb, p_particle p[nb]){
	
    EmptySpace();
    for (int i=0; i<nb; i++)
        DrawDISC(p[i]->x*SIZE, p[i]->y*SIZE, p[i]->r*SIZE, p[i]->color );
    UpdateScreen();

}

// function simulate the collisions
void simulate(double time_limit, double period,int nb, p_particle p[nb]){

	double t = 0;
	double t_next_redraw = period;
	 p_event e;
	while(t<time_limit){
		draw_particle(nb,p);
		
		while(t<t_next_redraw){
		 //next event = redrawing event at time_next_event
		  e = create_event(t_next_redraw, NULL, NULL);
		 //for each particle do
		 for(int i = 0;i<nb;i++){
		 	//particle-particle
		 	for(int j = i+1;j<nb;j++){
		 	double delta_t = time_2particles(p[j],p[i]);
		 		if(t + delta_t < e->time){
		 		e = create_event(t + delta_t,p[i],p[j]);
		 		}
		 	}
		 	//partical - vertical
		 	double t_ver = time_vertical(p[i]);
		 	if(t + t_ver < e->time){
		 		e = create_event(t + t_ver,p[i],NULL);
		 	}
		 	//partical - horizontal
		 	double t_hor = time_horizontal(p[i]);
		 	if(t + t_hor < e->time){
		 		e = create_event(t + t_hor,NULL,p[i]);
		 	} 	
		 
		 }
		 
		 //update new position 
		 for(int i = 0;i<nb;i++){
		 	UpdatePosition(p[i],e->time - t);
		 }
		 //update velocities 
		 if(e->a != NULL &&	e->b != NULL){
		 	UpVeloc_2particles(e->a,e->b);// particle-particle
		 }
		 else if(e->a!= NULL && e->b == NULL){
		 	UpVeloc_ver(e->a);//  vertical
		 }
		 else if(e->a== NULL && e->b != NULL){
		 	UpVeloc_hor(e->b);//   horizontal
		 }
		 
		 t = e->time;
		 free(e);
		}
		t_next_redraw = t + period;
		
	}
}







