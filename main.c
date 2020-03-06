#include<stdio.h>
#include<stdlib.h>


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

        printf("Nie␣moge␣przydzielic␣pamieci!\n"); 
        return 1;
    } 
    else{

    for ( int i = 0; i < x; i++ ) 
    { 
        t[i] = malloc( y* sizeof( int ) ); 
        if ( t[i] == NULL ) 
        { 
            printf("Nie␣moge␣przydzielic␣pamieci!\n"); 
            return -1;
        } 
    } 
    for (int  i = 0; i < x; i++ ) {
        for ( int j = 0; j < y; j++ ) 
           fscanf(in,"%d", &t[i][j] ); 
    }


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
    return 0 ; 
} 
