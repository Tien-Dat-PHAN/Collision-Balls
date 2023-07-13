/**
 * @file practice-readfile.c
 *
 * @brief Program to practice before doing test-loader
 * 
 *
 * @author Phan Tien Dat
 *
 */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv){
	FILE *p_file = NULL;
	
	p_file = fopen(argv[1], "r");
	
	if(p_file == NULL){
		fprintf(stderr, "Can not read this file %s\n",argv[1] );
		exit(EXIT_FAILURE);
	}
	
	double x,y,vx,vy,m,r;
	int color;
	
	
	for(int i = 0;i<50;i++){
		fscanf(p_file, "%lf,%lf,%lf,%lf,%lf,%lf,%d", &x,&y,&vx,&vy,&m,&r,&color);
		printf("%lf,%lf,%lf,%lf,%lf,%lf,%d", x,y,vx,vy,m,r,color);
		printf("\n");

	}
	
	fclose(p_file);
	p_file=NULL;
	return 0;
}
