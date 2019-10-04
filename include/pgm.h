#ifndef PGM_H
#define PGM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct pgm {
     unsigned char width;
     unsigned char height;
     unsigned char max_value;
     unsigned char** image;
};

typedef struct pgm pgm;

pgm* init_pgm(const unsigned int width, const unsigned int height, const unsigned char max_value);
pgm* create_pgm(const unsigned int width, const unsigned int height, const unsigned char max_value, unsigned char** image);

bool write_pgm(const char* file_path, const pgm* p);

void destroy_pgm(pgm** p);

#endif
