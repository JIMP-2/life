#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h" 


void zmien_stan(int** tab, int** copy, int rows, int columns) {
//przejscia tab->copy
	//liczy sasiadow

	for(int x=0; x<rows; x++) {
		for(int y=0; y<columns; y++) {
		        int count=0;
		        for(int i=-1; i<2; i++) {
                		for(int j=-1; j<2; j++) {
                        		int c=y+j;
                        		int r=x+i;
                        		if(r>=0 && r<rows && c>=0 && c<columns) {
                                		count+=tab[r][c];
                        		}
                		}
        		}
        		count-=tab[x][y];

      	//zmienia stan komorki zalenie od liczby sasiadow
			if(count < 2 || count >3) {
				copy[x][y] = 0;
			}
			else if(count == 2) {
				copy[x][y] = tab[x][y];
			}
			else {
				copy[x][y] = 1;
			}
			// printf("sasiedzi [%d][%d] = %d\n", x+1, y+1, count);
			count=0;
		}
	}

}

void copy_tab(int** tab, int** copy, int rows, int columns) {

	//kopiuje zmieniona tablice copy->tab
	
	   for(int x=0; x<rows; x++) {
		for(int y=0; y<columns; y++) {
			tab[x][y]=copy[x][y];
		}
	   }
}

void show(int **tab, int rows, int columns) {
	for(int i=0; i<rows; i++) {
                for(int j=0; j<columns; j++) {
                        printf("%d ", tab[i][j]);
                }
                printf("\n");

        }
                printf("\n");
}


