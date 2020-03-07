#include<stdio.h>
#include<stdlib.h>
#include"tab2d.h"

int** alokuj2d(int x, int y) {
	int** t;
	t = malloc( x* sizeof( int * ) );

	if ( t == NULL ){
        	printf("Brak pamieci!\n");
	        return NULL;
    	}
    
   	for ( int i = 0; i < x; i++ ){   
		t[i] = malloc( y* sizeof( int ) );
	
	
		if ( t[i] == NULL ){
			printf("brak pamieci!\n");
	        	return NULL;
       	 	}
	}

	return t;
}

void zwolnij2d(int** tab, int x) {
	for(int i=0; i<x; i++) {
                free(tab[i]);
        }
        free(tab);
}

    

	
