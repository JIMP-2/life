#include <png.h>
#include <stdlib.h>

#include "life.h"



int save_2_png(char *file_name, int x, int y, int *t[] ) {
    FILE *f = fopen(file_name, "wb");
    png_structp png_data;
    png_infop png_info;
    png_bytep png_row;

    int zoom= 800/x < 1700/y ? 800/x : 1700/y ;
    int p_width = y*zoom;
    int p_height = x*zoom;

    if (f == NULL) return 1; 

    png_data = png_create_write_struct(
        PNG_LIBPNG_VER_STRING,
        NULL, NULL, NULL
    );
    if (png_data == NULL) return 2;

    png_info = png_create_info_struct(png_data);
    if (png_info == NULL) return 3;
    
    png_init_io(png_data, f);

    png_set_IHDR(
        png_data, png_info,
        p_width, p_height,
        8, PNG_COLOR_TYPE_GRAY,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_BASE,
        PNG_FILTER_TYPE_BASE
    );
    png_write_info(png_data, png_info);

    png_row = (png_bytep)malloc(
        p_width * sizeof(png_byte)
    );

    for (int x = 0; x < p_height; x++) {
        for (int y = 0; y < p_width; y++) {
            png_row[y] = t[x/zoom][y/zoom] * 255;
        } 
        png_write_row(png_data, png_row);
    }

    png_write_end(png_data, NULL);


    fclose(f);
    png_free_data(
        png_data, png_info, PNG_FREE_ALL, -1
    );
    png_destroy_write_struct(
        &png_data, (png_infopp)NULL
    );
    free(png_info);
    if (png_row != NULL) free(png_row);

    return 0;
}

void save_png(char *out_png, int x, int y, int *t[] , int n) {
    char *file_name = create_name(out_png, "pngout", n, "png");

    int err = save_2_png(file_name, x,y,t) ;
    if (err) {
        printf("Problem with saving generation #%d to %s.\n", n, file_name);
    } else {
        printf("Saved generation #%d to %s.\n", n, file_name);
    }

    free(file_name);
}
