/*
 * FileNotFound.h
 *
 *  Created on: 25 Jan 2021
 *      Author: faez zangariya
 */

#ifndef FILENOTFOUND_H_
#define FILENOTFOUND_H_

class FileNotFound {
public:
	const char * what () const throw ()
	    {
	    	return "the file you seek doesn't exist!";
	    }
};

#endif /* FILENOTFOUND_H_ */
