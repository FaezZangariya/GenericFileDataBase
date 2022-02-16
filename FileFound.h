/*
 * FileFound.h
 *
 *  Created on: 25 Jan 2021
 *      Author: faez zangariya
 */

#ifndef FILEFOUND_H_
#define FILEFOUND_H_

class FileFound {
public:
	const char * what () const throw ()
		    {
		    	return "the file you seek to create already exists!";
		    }
};

#endif /* FILEFOUND_H_ */
