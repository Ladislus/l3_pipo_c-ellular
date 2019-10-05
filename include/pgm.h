/**
 * @file pgm.h
 * @author Ladislas WALCAK (ladislas.walcak@etu.univ-orleans.fr), Simon DRIEUX (simon.drieux@etu.univ-orleans.fr)
 * @brief HEADER - Functions used to manipulate the pgm struct
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PGM_H
#define PGM_H

#include "constants.h"

/**
 * @brief Function to initialise the pgm file header
 * 
 * @param width const unsigned int : The  width of the file
 * @param height const unsigned int : The height of the file
 * @param max_value const unsigned char : The maximum value in the pixels
 * @return pgm* The pointer of the created pgm
 */
pgm* init_pgm(const unsigned int width, const unsigned int height, const unsigned char max_value);

/**
 * @brief Function to create a pgm
 * 
 * @param width const unsigned int : The width of the file
 * @param height const unisgned int : The height of the file
 * @param max_value const unsigned char : The maximum value in the pixels
 * @param image unsigned char** : The array of pixels
 * @return pgm* The pointer of the created pgm
 */
pgm* create_pgm(const unsigned int width, const unsigned int height, const unsigned char max_value, unsigned char** image);

/**
 * @brief Function to write the pgm into a file
 * 
 * @param file_path const char* : The absolute path of file
 * @param p const pgm* : The pgm to write
 * @return true if the file was written
 * @return false if an error occured and the file wasn't written
 */
bool write_pgm(const char* file_path, const pgm* p);

/**
 * @brief Function to destroy the pgm
 * 
 * @param p pgm** : The pointer of the pgm to destroy
 */
void destroy_pgm(pgm** p);

#endif
