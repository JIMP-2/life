#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "life.h"

char *create_name(char *out_png, char *file_name, int n, char *ext) {
    char *new_str = malloc(sizeof(char) * (strlen(out_png) + strlen(file_name) + 7 + strlen(ext)));

    sprintf(new_str, "%s/%s_%03d.%s", out_png, file_name, n, ext);

    return new_str;
}
