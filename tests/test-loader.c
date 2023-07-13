/**
 * @file test-loader.c
 *
 * @brief Test the functions including in loader.h work or not
 * 
 * Command line:   ./test-event data/ file example.txt
 *
 * @author Phan Tien Dat
 *@date 15/03/2022
 */
#include<assert.h>
#include"loader.h"

int main(int argc, char ** argv){
	FILE *p = NULL;
	int num,i;
	p = fopen(argv[1], "r");
	if(p == NULL){
		fprintf(stderr, "Can not read this file %s\n",argv[1] );
		exit(EXIT_FAILURE);
	}
	num = num_particle(p);
	fclose(p);
	
	
	FILE *pnew = NULL;
	printf("Number of particles: %d\n", num);
	
	pnew = fopen(argv[1], "r");
	if(pnew == NULL){
		fprintf(stderr, "Can not read this file %s\n",argv[1] );
		exit(EXIT_FAILURE);
	}
	//Create a pointer to get information from file.txt//--IMPORTANT--
	p_particle p_loader[num]; 
	
	loader_file(pnew,p_loader);
	
	printf("\n");
	printf("\n");

	printf("x\t\ty\t\tvx\t\tvy\t\tm\t\tr\t\tcolor\n");

	for(i = 0;i<num;i++){
		printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%d\n",p_loader[i]->x,\
		p_loader[i]->y,p_loader[i]->vx,p_loader[i]->vy,\
		p_loader[i]->m,p_loader[i]->r,p_loader[i]->color);
	}
	
	
	printf("------> Succesful read file %s!\n", argv[1]);
	
	for( i = 0;i<num;i++){
		free(p_loader[i]);
	}
	fclose(pnew);
	
	return 0;
}
