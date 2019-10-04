#include "pgm.h"

pgm* initialiser_image_pgm(const  unsigned char width, const unsigned char height, const unsigned char max_value) {

    pgm* returned_pgm = (pgm*)malloc(sizeof(pgm));

    returned_pgm->width = width;
    returned_pgm->height = height;
    returned_pgm->max_value = max_value;

    returned_pgm->image = (unsigned char**)malloc(sizeof(unsigned char*) * height);
    if(returned_pgm->image == NULL) fprintf(stderr, "Couldn't allocate space for the image (HEIGHT_ERROR)");

    for(size_t i = 0; i < height; i++) {
        returned_pgm->image[i] = (unsigned char*)calloc(height, sizeof(unsigned char));
        if(returned_pgm->image[i] == NULL) fprintf(stderr, "Couldn't allocate space for image (WIDTH_ERROR, INDEX:%ld)", i);
    }
    return returned_pgm;
}

pgm* create_pgm(const unsigned char width, const unsigned char height, const unsigned char max_value, unsigned char** image) {
    pgm* returned_pgm = initialiser_image_pgm(width, height, max_value);

    for(size_t i = 0; i < height; i ++) {
        strcpy((char*)returned_pgm->image[i], (char*)image[i]);
    }    
    
    return returned_pgm;
}

bool write_pgm(const char* file_path, const pgm* p) {

    FILE* file = fopen(file_path, "wb");
    if(file == NULL) {
        fprintf(stderr, "Couldn't open image in write mode (OPENNING_ERROR)");
        return false;
    }

    fprintf(file, "P5\n");
    fprintf(file, "%u %u\n", p->width, p->height);
    fprintf(file, "%u\n", p->max_value);

    const unsigned char BYTES_SIZE = 1;
    const unsigned char BYTES_TO_WRITE = 1;

    for(size_t i = 0; i < p->height; i++) {
        for(size_t j = 0; j < p->width; j++) {
            fwrite(&p->image[i][j], BYTES_SIZE, BYTES_TO_WRITE, file);
        }
    }
    fclose(file);
    file = NULL;

    return true;
}

void destroy_pgm(pgm** p) {
    for(size_t i = 0; i < (*p)->height; i++)
        free((*p)->image[i]);
    free((*p)->image);
    free(*p);
    *p = NULL;
}
