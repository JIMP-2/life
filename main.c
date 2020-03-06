#include<stdio.h>
#include<stdlib.h>
#include"rules.h"
#include<string.h>


int main ( int argc, char *argv[]){

    	FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;
        FILE *out = argc > 2 ? fopen( argv[2], "w" ) : stdout;
   
    int x;
    int y;

          fscanf(in,"%d %d",&x,&y); 


printf(" %d %d \n", x,y);

           int **t; 
    t = malloc( x* sizeof( int * ) ); 

     if ( t == NULL ) 
    { 

        printf("Brak pamieci!\n"); 
        return 1;
    } 
    else{

    for ( int i = 0; i < x; i++ ) 
    { 
        t[i] = malloc( y* sizeof( int ) ); 
        if ( t[i] == NULL ) 
        { 
            printf("brak pamieci!\n"); 
            return -1;
        } 
    } 
    for (int  i = 0; i < x; i++ ) {
        for ( int j = 0; j < y; j++ ) 
           fscanf(in,"%d", &t[i][j] ); 
    }

	int **copy = (int**)malloc((x+1)*sizeof(int*));
        for(int i=0; i<(x+1); i++) {
                copy[i]=(int*)malloc((y+1)*sizeof(int));
        }


zmien_stan(t,copy,x,y);
copy_tab(t,x,y);


// zapis do pliku

     fprintf(out, "%d %d\n", x,y); 

    for ( int i = 0; i < x; i++ ) 
    { 
        for ( int j = 0; j < y; j++ ) 
            fprintf( out, "%d ", t[i][j]);
        fprintf(out, "\n"); 
    } 

	fclose( out );

    }


	//zwalnianie pamieci
	for(int i=0; i<x; i++) {
		free(t[i]);
	}
	free(t);

	for(int i=0; i<y; i++) {
                free(copy[i]);
        }
        free(copy);


	return 0;

    return 0 ; 
} 
