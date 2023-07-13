
/**
 * @file test-correctness-heap.c
 * @brief Test


 * @author Phan Tien Dat
 * @date 14 mars 2022
 */ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include"heap.h"
#include"event.h"
#include<assert.h>

int main(){

	printf("Starting test-correstness-heap ...\n");
	printf("Test insert function...\n");
	double t = 1.0;
	p_event e[50];
	for(int i = 1; i<=50;i++){
	e[i] = malloc(sizeof(struct Event));
	e[i]->time = i*t;
	}
 	
 	p_heap h = malloc(sizeof(struct MinHeap));
 	
 	insert(e[40],h);
 	insert(e[10],h);
 	insert(e[20],h);
 	insert(e[30],h);
 	insert(e[9],h);
 	insert(e[1],h);// Min value was insterted;
 	insert(e[8],h);
 	insert(e[17],h);
 	
 	print_bst(h->p);
 	
 	p_tree p1 = find_father_node_n(h->n+1 ,h);
 	printf("%lf\n", p1->event->time);
 	
 	assert(getMin(h)== 1.0);
 	printf("Test insert function have done ....--> OK\n");
 	
 	p_event e1 = extract_min(h);
 	printf("%lf\n",e1->time);
 	p_event e2 = extract_min(h);
 	printf("%lf\n",e2->time);
 	//p_event e3 = extract_min(h);
 	//printf("%lf\n",e3->time);
 	//printf("%lf %lf %lf\n", e1->time, e2->time, e3->time);
 	
 	/*
 	printf("Test for extrect_min function ...\n");
 	for(int i = 1;i<=50;i++){
 	insert(e[i],h);
 	}
 	p_event e_test;
 	printf("number	time\n");
 	for(int i = 1; i<=50; i++){
 		e_test = extract_min(h);
 		printf("%d\t %lf\n",i,e_test->time);
 	
 	}
 	*/
 	//--------free memories --------------------------//
 	
 	free(p1);
 	free(h);
 	for(int i = 1; i<=50;i++){
 	free(e[i]);
 	}

}
