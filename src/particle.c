/**
 * @file particle.c
 *
 * @brief Program to calculating collsion time and update velocites 
 * 
 *
 * @author Phan Tien Dat
 * @date 15/03/2022
 *
 */
#include "particle.h"


void UpdatePosition(p_particle p, double time){
	p->x = p->x + time*p->vx;
	p->y = p->y + time*p->vy;
}

double time_vertical(p_particle p){
	if (p->vx < 0){return (p->r - p->x)/p->vx;}
	
	else if(p->vx > 0){return (1 - p->r - p->x)/p->vx;}
	
	else{return INFINITY; }
}

double time_horizontal(p_particle p){
	if (p->vy < 0){return (p->r - p->y)/p->vy;}
	
	else if(p->vy > 0){return (1 - p->r - p->y)/p->vy;}
	
	else{return INFINITY; }
}

void UpVeloc_ver(p_particle p){
	p->vx = -p->vx;
	p->count++;
}

void UpVeloc_hor(p_particle p){
	p->vy = -p->vy;
	p->count++;
}

double time_2particles(p_particle p1, p_particle p2){
	if(p1 == p2){return INFINITY;};
	double delpx = p2->x - p1->x;
	
	double delpy = p2->y - p1->y;
	
	double delvx = p2->vx - p1->vx;
	double delvy = p2->vy - p1->vy;
	double p_p = delpx*delpx + delpy*delpy;
	
	double v_v = delvx*delvx + delvy*delvy;
	if(v_v == 0 ){return INFINITY;}
	double p_v = delpx*delvx + delpy*delvy;
	if(p_v > 0){return INFINITY;}
	double r = p1->r + p2->r;
	
	if(p_v*p_v - v_v*(p_p - r*r) < 0){return INFINITY;}
	
	double a = sqrt(p_v*p_v - v_v*(p_p - r*r)) + p_v;
	double delta_t = -a/v_v;
	
	return delta_t;
	
	
}
// return the number of collision of the relevent particle

int count(p_particle a){
	return a->count;
}

void UpVeloc_2particles(p_particle p1, p_particle p2){
	
	
	double delpx = p2->x - p1->x;
	
	double delpy = p2->y - p1->y;
	
	double delvx = p2->vx - p1->vx;
	double delvy = p2->vy - p1->vy;
	double p_v = delpx*delvx + delpy*delvy;
	double p_p = delpx*delpx + delpy*delpy;
	
	double m = p1->m + p2->m;
	
	p1->vx = p1->vx + 2*p2->m*p_v*delpx/(m*p_p);
	p1->vy = p1->vy + 2*p2->m*p_v*delpy/(m*p_p);
	
	p2->vx = p2->vx - 2*p1->m*p_v*delpx/(m*p_p);
	p2->vy = p2->vy - 2*p1->m*p_v*delpy/(m*p_p);
	
	
	p1->count++;
	p2->count++;
	
}

