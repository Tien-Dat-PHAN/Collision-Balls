/**
 * @file heap.c
 * @brief define heap functions


 * @author Phan Tien Dat
 * @date 14 mars 2022
 */ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"heap.h"


bool isEmpty(p_heap h){
	return h->p == NULL;
}

p_tree find_father_node_n(int n, p_heap h){
	int depth = (int) log2(n);
	p_tree p = h->p;
	for(int i = depth-1;i > 0;i--){
	if((n>>i & 1)==0){
		p = p->left;
	}
	else{
		p = p->right;
	}
	}
	return p;

}

void insert(p_event e, p_heap h){
	if(isEmpty(h)){
	h->p = malloc(sizeof(struct tree));
	h->p->event = e;
	h->p->left = NULL;
	h->p->right = NULL;
	h->p->parent = NULL;
	h->n = 1;
	}
	
	else{
		p_tree p1 = find_father_node_n(h->n+1 ,h);
		p_tree add = malloc(sizeof(struct tree));
	
		if(p1->left == NULL){
			
			add->event = e;
			add->left = NULL;
			add->right = NULL;
			add->parent = p1;
			p1->left = add;
		}
		else{
			
			add->event = e;
			add->left = NULL;
			add->right = NULL;
			add->parent = p1;
			p1->right = add;
		}
		
		h->n = h->n + 1;
		while (p1!= NULL && add->event->time < add->parent->event->time){
			swap(p1,add);
			add = p1;
			p1 = p1->parent;
		}
	
	}
}

p_event extract_min(p_heap h){

	if(isEmpty(h)){
	
	printf("Error\n");
	exit(EXIT_FAILURE);
	}
	
	p_tree p1 = find_father_node_n(h->n, h);
	
	p_event temp;
	if(h->n == 1){
	return h->p->event;
	}
	
	if(p1->right == NULL){
		temp = h->p->event;
		h->p->event = p1->left->event;
		free(p1->left);
		}
	else{
		temp = h->p->event;
		h->p->event = p1->right->event;
		free(p1->right);
	
	}
	p_tree curr = h->p;
	
	if(curr->left == NULL && curr->right == NULL){
		return temp;}
		
	if(curr->left != NULL){
		if(curr->event->time > curr->left->event->time){
		swap(curr,curr->left);
		curr = curr->left;
		}
	
	}
	if(curr->left!=NULL && curr->right!=NULL){
		
		if(curr->left->event->time < curr->right->event->time){
			swap(curr, curr->left);
			curr = curr->left;
		
			}
		else{
			swap(curr, curr->right);
			curr = curr->right;
			}
	}
	
	while(curr->event->time > curr->left->event->time || curr->event->time > curr->right->event->time){
	
	if(curr->left == NULL && curr->right == NULL){
		return temp;}
		
	if(curr->left != NULL){
		if(curr->event->time > curr->left->event->time){
		swap(curr,curr->left);
		curr = curr->left;
		}
	}
	
	if(curr->left!=NULL && curr->right!=NULL){
		
		if(curr->left->event->time < curr->right->event->time){
			swap(curr, curr->left);
			curr = curr->left;
		
			}
		else{
			swap(curr, curr->right);
			curr = curr->right;
			}
	}
	
	}
	h->n = h->n - 1;
	return temp;
}

double getMin(p_heap h){
	
	return h->p->event->time;

}

void print_level(p_tree tree, int level) {
    for (int i = 0; i < level - 1; i++) {
        printf("   ");
    }

    if (tree == NULL) {
        printf("%snil\n", level == 0 ? "" : " +-");
        return;
    }

    printf("%s(%lf)\n", level == 0 ? "" : " +-", tree->event->time);
    print_level(tree->left, level + 1);
    print_level(tree->right, level + 1);
}

void print_bst(p_tree tree) {
    print_level(tree, 0);
}

void swap(p_tree p1, p_tree p2){
	p_event temp;
	temp = p1->event;
	p1->event = p2->event;
	p2->event = temp;
	
}








