#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char ** argv) {
//alokacja i wpisanie danych do tablicy dwuwymiarowej
	//powinien byc warunek sprawdzajacy argumenty, na razie zakladamy, ze jest poprawnie i nie ma mazania po pamieci
	int row = atoi(argv[1]);	
	int column= atoi(argv[2]);
	int elem=3;
	int count=0;
	
	int **tab = (int**)malloc(row*sizeof(int*));
	for(int i=0; i<row; i++) {
		tab[i]=(int*)malloc(column*sizeof(int));
	}

	for(int i=0; i<row; i++) {
		for(int j=0; j<column; j++) {
			tab[i][j] = atoi(argv[elem++]);
		}
	}

	for(int i=0; i<row; i++) {
		for(int j=0; j<column; j++) {
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//alokuje druga  tablice tab
	int **copy = (int**)malloc((row+1)*sizeof(int*));
        for(int i=0; i<(row+1); i++) {
                copy[i]=(int*)malloc((column+1)*sizeof(int));
        }

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

/*	for(int i=0; i<row; i++) {
                for(int j=0; j<column; j++) {
                        printf("%d ", copy[i][j]);
                }
                printf("\n");
        }
*/
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


	//zwalnianie pamieci
	for(int i=0; i<column; i++) {
		free(tab[i]);
	}
	free(tab);

	for(int i=0; i<column; i++) {
                free(copy[i]);
        }
        free(copy);


	return 0;
}

