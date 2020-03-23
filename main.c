#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<getopt.h>

#include"rules.h"
#include"tab2d.h"
#include"pictures.h"

char *usage =
  "\nUSAGE: %s -i txt_file_with_the_grid -o txt_file_with_output -n number_of_generations\n\n";

int main ( int argc, char *argv[]){
 
    
char *out_png = ".";
	int opt;
      	char* min = NULL;
	char* mout = NULL;
  	int n = 5;
	char* programe = argv[0];

	while((opt = getopt (argc, argv, "i:o:n:")) != -1) {
		switch (opt) {
			case 'i': min = optarg; break;
			case 'o': mout = optarg; break;
			case 'n': n = atoi(optarg); break;
			default: fprintf(stderr, usage, programe);
		}
	}


	if(min != NULL) {
		FILE *out = NULL;
		FILE *in = fopen( min, "r");
		
		if(in == NULL) {
			fprintf(stderr, "wrong in\n");
			exit (EXIT_FAILURE);
		}

		out = fopen (mout, "w");
		if(out == NULL) {
			out=stdout;

		}
		if (n <0) {
			fprintf(stderr, "\nthe index can't be negative\n\n");
			exit (EXIT_FAILURE);
		}




	int x;
    	int y;
	
	//  czytanie z pliku
	
       	fscanf(in,"%d %d",&x,&y); 

	int **t = alokuj2d(x,y);

	for (int  i = 0; i < x; i++ ) {
        	for ( int j = 0; j < y; j++ ) 
           	fscanf(in,"%d", &t[i][j] ); 
  	}

	
	fclose(in);	

    	int **copy = alokuj2d(x,y);


save_png(out_png, x, y, t, 0);
show(t, x, y);

 // wywołanie funkcji odpowiedzialnej za zmianę stanu

    for (int i=1; i<=n; i++ ){

	zmien_stan(t,copy,x,y);
	
	copy_tab(t,copy,x,y);

        save_png(out_png, x, y, t, i);
        show(t, x, y);

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
} 

