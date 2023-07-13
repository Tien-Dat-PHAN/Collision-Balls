/**
 * @file event.c
 *
 * @brief Program to create event and verify it
 * 
 *
 * @author Phan Tien Dat
 *@date 15/03/2022
 */
#include "event.h"


// Create a new event 

p_event create_event(double t, p_particle a, p_particle b){
	p_event e;
	e = malloc(sizeof(struct Event));
	e->time = t;
	e->a = a;
	e->b = b;
	if(a!= NULL){
		e->count_a = count(a);
	}
	else(e->count_a = -1);
	if(b!= NULL){
		e->count_b = count(b);
	}
	else(e->count_b = -1);
	return e;
	
}
// verify that event is valid or not;
bool verify_event(p_event e){
	if (e->a !=NULL && e->count_a != count(e->a)){
		return false;
	}
	if (e->b !=NULL && e->count_b != count(e->b)){
		return false;
	}
	
	
	return true;
	
}














