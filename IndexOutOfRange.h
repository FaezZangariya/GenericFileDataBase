/*
 * IndexOutOfRange.h
 *
 *  Created on: 25 Jan 2021
 *      Author: faez zangariya
 */

#ifndef INDEXOUTOFRANGE_H_
#define INDEXOUTOFRANGE_H_
#include<iostream>

class IndexOutOfRange:public std::exception {
public:

	const char * what () const throw ()
    {
    	return "your index is bigger than the size of the store! please try again with a valid index.";
    }
};

#endif /* INDEXOUTOFRANGE_H_ */
