/*
 * utilities.h
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_
#include "../includes/constants.h"

/**
 * determine how many data structs can fit
 * in the total amount of memory
 *
 * \param total_memory: the maximum memory to use
 * \return  either the number of structs that can fit in total_memory
 * 			or 0 if none will fit (hint use sizeof to determine the size of the struct)
 */
int how_many_structs_can_fit_in_memory(int total_memory){
int length = sizeof(data)/sizeof(data[0]);
	if (!length==0)
		return length;
	else
		return 0;
}

#endif /* UTILITIES_H_ */
