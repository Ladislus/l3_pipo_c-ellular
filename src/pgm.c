/**
 * @file pgm.c
 * @author Ladislas WALCAK, Simon DRIEUX
 * @brief Functions used to manipulate the pgm struct
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "pgm.h"

/**
 * @brief Function to initialise the pgm file header
 * 
 * @param width const unsigned int : The  width of the file
 * @param height const unsigned int : The height of the file
 * @param max_value const unsigned char : The maximum value in the pixels
 * @return pgm* The pointer of the created pgm
 */
pgm* init_pgm(const unsigned int width, const unsigned int height, const unsigned char max_value) {

    //Allocate space for the pgm
    pgm* returned_pgm = (pgm*)malloc(sizeof(pgm));

    //Assign value to the header
    returned_pgm->width = width;            //The width
    returned_pgm->height = height;          //The height
    returned_pgm->max_value = max_value;    //The maximum value in the pixels

    //Allocate space for matrix of pixels
    returned_pgm->image = (unsigned char**)malloc(sizeof(unsigned char*) * height);
    //Test to check if the allocation was successful
    if(returned_pgm->image == NULL) fprintf(stderr, "Couldn't allocate space for the image (HEIGHT_ERROR)");

    //Allocate space for each array in the matrix
    for(size_t i = 0; i < height; i++) {
        returned_pgm->image[i] = (unsigned char*)calloc(width, sizeof(unsigned char));
        if(returned_pgm->image[i] == NULL) fprintf(stderr, "Couldn't allocate space for image (WIDTH_ERROR, INDEX:%ld)", i);
    }

    //Return the pointer to the created pgm
    return returned_pgm;
}

/**
 * @brief Function to create a pgm
 * 
 * @param width const unsigned int : The width of the file
 * @param height const unisgned int : The height of the file
 * @param max_value const unsigned char : The maximum value in the pixels
 * @param image unsigned char** : The array of pixels
 * @return pgm* The pointer of the created pgm
 */
pgm* create_pgm(const unsigned int width, const unsigned int height, const unsigned char max_value, unsigned char** image) {

    //Initialise the pgm and fill the header
    pgm* returned_pgm = init_pgm(width, height, max_value);

    //Copy the pixels into the image
    for(size_t i = 0; i < height; i ++)
        for(size_t j = 0; j < width; j++)
            returned_pgm->image[i][j] = image[i][j];

    //Return the pointer of the created and filled pgm
    return returned_pgm;
}

/**
 * @brief Function to write the pgm into a file
 * 
 * @param file_path const char* : The absolute path of file
 * @param p const pgm* : The pgm to write
 * @return true if the file was written
 * @return false if an error occured and the file wasn't written
 */
bool write_pgm(const char* file_path, const pgm* p) {

    //Open the file with the given filepath
    FILE* file = fopen(file_path, "wb");
    //If the opening wasn't successful ...
    if(file == NULL) {
        //Print the error
        fprintf(stderr, "Couldn't open image in write mode (OPENNING_ERROR)");
        //Exit the function with errors
        return false;
    }

    //Write the magic number (P5 = grey binary) into the file
    fprintf(file, "P5\n");
    //Write the width and height into the file
    fprintf(file, "%u %u\n", p->width, p->height);
    //Write the maximum value into the file
    fprintf(file, "%u\n", (unsigned int)p->max_value);


    const unsigned char BYTES_SIZE = 1;     //Size of each pixel
    const unsigned char BYTES_TO_WRITE = 1; //Number of pixels to write each time

    //Write the pixels into the file
    for(size_t i = 0; i < p->height; i++) {
        for(size_t j = 0; j < p->width; j++) {
            fwrite(&p->image[i][j], BYTES_SIZE, BYTES_TO_WRITE, file);
        }
    }

    //Close the opened file
    fclose(file);
    file = NULL;

    //Exit the function without errors
    return true;
}

/**
 * @brief Function to destroy the pgm
 * 
 * @param p pgm** : The pointer of the pgm to destroy
 */
void destroy_pgm(pgm** p) {

    //Free each line of the matrix of pixels
    for(size_t i = 0; i < (*p)->height; i++) {
        free((*p)->image[i]);
        (*p)->image[i] = NULL;
    }
    
    //Free the matrix
    free((*p)->image);
    (*p)->image = NULL;

    //Free the pgm struct
    free(*p);
    *p = NULL;
}
