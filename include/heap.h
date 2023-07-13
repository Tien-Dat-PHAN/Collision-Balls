
/**
 * @file heap.h
 * @brief Priority queue are classcally implemented using with a binary heap


 * @author Phan Tien Dat
 * @date 14 mars 2022
 */ 

#ifndef HEAP_H
#define HEAP_H

#include"event.h"
#include<stdbool.h>

  
typedef struct MinHeap* p_heap;
typedef struct tree* p_tree;

struct MinHeap{
	int n;
	p_tree p;
	
};

struct tree{
	p_event event;
	p_tree left;
	p_tree right;
	p_tree parent;
	
};

bool isEmpty(p_heap h);

p_tree find_father_node_n(int n, p_heap h);
//Insert new value/node

void insert(p_event e, p_heap h);
//Get and remove minimum value
p_event extract_min(p_heap h);

double getMin(p_heap);

void print_level(p_tree tree, int level);
void print_bst(p_tree tree);
void swap(p_tree p1, p_tree p2);

 
 #endif
