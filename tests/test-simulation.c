/**
 * @file test-simulation.c
 *
 * @brief Test the functions including in simulation-naive.h works with random 100 particles
 * 
 * Command line:   ./test-simulation
 *
 *
 * @author Phan Tien Dat
 * @date 15/03/2022
 *
 */
#include<math.h>
#include"disc.h"

#include"event.h"

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
	
	while(t<time_limit){
		draw_particle(nb,p);
		
		while(t<t_next_redraw){
		 //next event = redrawing event at time_next_event
		 p_event e = create_event(t_next_redraw, NULL, NULL);
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
		 
		}
		t_next_redraw = t + period;
	}
}


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

	int nb = 100;
	
	
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








