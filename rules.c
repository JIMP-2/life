#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h> 


int* zmien_stan(int* tab, int *copy, int row, int column) {
//przejscia tab->copy
	//liczy liczbe sasiadow
	for(int i=0; i<row; i++) {
		for(int j=0; j<column; j++) {
			if(i!=0) 
				count+=tab[i-1][j];
			if(i!=row-1)
				count+=tab[i+1][j];
			if(j!=0)
				count+=tab[i][j-1];
			if(j!=column-1)
				count+=tab[i][j+1];
			if(i!=0 && j!=0)
				count+=tab[i-1][j-1];
			if(i!=0 && j!=column-1)
				count+=tab[i-1][j+1];
			if(i!=row-1 && j!=0)
				count+=tab[i+1][j-1];
			if(i!=row-1 && j!=column-1)
				count+=tab[i+1][j+1];
	//zmienia stan komorki zalenie od liczby sasiadow
			if(count < 2 || count >3) {
				copy[i][j] = 0;
			}
			else if(count == 2) {
				copy[i][j] = tab[i][j];
			}
			else {//if count ==3
				copy[i][j] = 1;
			}
//			printf("sasiedzi [%d][%d] = %d\n", i+1, j+1, count);
			count=0;
		}
	}
	return copy;
}

/*	for(int i=0; i<row; i++) {
                for(int j=0; j<column; j++) {
                        printf("%d ", copy[i][j]);
                }
                printf("\n");
        }
*/

int* copy_tab(int*tab, int row, int column) {
	//kopiuje zmieniona tablice copy->tab
	for(int i=0; i<row; i++) {
                memcpy(&tab[i], &copy[i], sizeof(tab[0]));
        }

        for(int i=0; i<row; i++) {
                for(int j=0; j<column; j++) {
                        printf("%d ", tab[i][j]);
                }
                printf("\n");
        }
	return copy;
}


