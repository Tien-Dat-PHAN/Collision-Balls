
/**
 * @file event.h
 * @brief This file include the event at the time t. After that, there is a function will verify this event exist or not


 * @author Phan Tien Dat
 * @date 11 mars 2022
 */ 

#ifndef EVENT_H
#define EVENT_H

#include "particle.h"

typedef struct Event *p_event ;
struct Event{
	double time;
	p_particle a,b;
	int count_a, count_b;
};


// Create a new event 

p_event create_event(double t, p_particle a, p_particle b);



// verify that event is valid or not;
bool verify_event(p_event e);

#endif