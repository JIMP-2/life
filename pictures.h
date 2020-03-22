#ifndef __PICTURES_H__
#define __PICTURES_H__



int save_2_png(char *file_name, int x, int y, int *t[]);
void save_png(char *out_png, int x, int y, int *t[], int n);

char *create_name(char *out_png, char *file_name, int n, char *ext);


#endif
