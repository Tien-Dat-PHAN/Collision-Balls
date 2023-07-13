/**
 * @file clash-of-particles-naive-file.c
 *
 * @brief Sample program simulating naive collision between given particles in data files
 * 
 * Command line: ./clash-of-particles-naive-file data/ random-50.txt
 *
 * @author Phan Tien Dat
 * @date 15/03/2022
 *
 */
#include "simulation-naive.h"
#include "disc.h"

int main(int argc, char ** argv){
	FILE *p = NULL;
	int num;
	if (argc >= 2) {
		p = fopen(argv[1], "r");
	} else {
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	
	if(p == NULL){
		fprintf(stderr, "Can not read this file %s\n",argv[1] );
		exit(EXIT_FAILURE);
	}
	num = num_particle(p);
	fclose(p);
	
	
	FILE *pnew = NULL;
	if (argc >= 2) {
		p = fopen(argv[1], "r");
	} else {
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
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
	CreateWindow("Particles",SIZE,SIZE);
	//-------------------------------------------------------
	double time_limit = 50000.0;
	double period = 2.0;
	simulate(time_limit, period, num, p_loader);
	//-------------------------------------------------------
	
	CloseWindow();


	fclose(pnew);
	for (int i = 0; i < num; i++) {
        free(p_loader[i]);
    }
	
}
