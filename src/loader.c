/**
 * @file loader.c
 *
 * @brief  Program to express get information from text file 
 * 
 *
 * @author Phan Tien Dat
 *@date 15/03/2022
 */
#include "loader.h"

int num_particle(FILE *p_file){
	int n;
	char ch[81];
	fgets(ch, 80, p_file);
	
	//Get the number of particles
    fscanf(p_file,"%d",&n);
    return n;
}

void loader_file(FILE *p_file, p_particle p_arr[]){

	double x,y,vx,vy,m,r;
	
	int n, color, i = 0;
	double fscanf_result = 0;
	char ch[81];
	// Get the first line 
	fgets(ch, 80, p_file);
	printf("%s",  ch);
	//Get the number of particles
    fscanf(p_file,"%d",&n);
    //Create p_particle
    
    p_particle p[n];
    
    //Get the defined particles features 
    
	fscanf_result = fscanf(p_file,"%lf,%lf,%lf,%lf,%lf,%lf, %d",&x,&y,&vx,&vy,&m,&r,&color);
	 p[0] = malloc(sizeof(struct particle));
	
	while(fscanf_result != EOF){ 
		
		p[i]->x = x;
		p[i]->y = y;
		p[i]->vx = vx;
		p[i]->vy = vy;
		p[i]->m = m;
		p[i]->r = r;
		p[i]->color = color;
 		
 		i = i+1;
 		p[i] = malloc(sizeof(struct particle));
		fscanf_result = fscanf(p_file,"%lf,%lf,%lf,%lf,%lf,%lf,%d",&x,&y,&vx,&vy,&m,&r,&color);
	 
		}
		for(int j = 0;j<n;j++){
			p_arr[j] = p[j];
		}

}

