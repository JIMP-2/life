#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"rules.h"
#include"tab2d.h"


int main ( int argc, char *argv[]){

	int n;
    printf ("Prosze podac ile pokolen ma zostac wygenerowanych:\n");
 
    scanf ("%d", &n);
	printf( "\n");

    	FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;
        FILE *out = argc > 2 ? fopen( argv[2], "w" ) : stdout;

		
   
		int x;
    	int y;

       	fscanf(in,"%d %d",&x,&y); 

	printf("%d %d \n", x,y);
	printf("\n");
		
	int **t = alokuj2d(x,y);

	for (int  i = 0; i < x; i++ ) {
        	for ( int j = 0; j < y; j++ ) 
           	fscanf(in,"%d", &t[i][j] ); 
  	}
	
	fclose(in);	

    	int **copy = alokuj2d(x,y);


		
while( n>0){
	zmien_stan(t,copy,x,y);
	
	copy_tab(t,copy,x,y);
	
n--;
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


	//zwalnianie pamieci
	zwolnij2d(t, x);
	zwolnij2d(copy,x);

	return 0;

     
} 
