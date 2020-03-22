#ifndef __RULES_H__
#define __RULES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zmien_stan(int** tab, int** copy, int rows, int columns);
void copy_tab(int** tab, int** copy, int row, int column);
void show(int **tab, int rows, int columns);

#endif
