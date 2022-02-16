/*
 * Mapval.h
 *
 *  Created on: 25 Jan 2021
 *      Author: faez zangariya
 */

#ifndef MAPVAL_H_
#define MAPVAL_H_

class Mapval{
public:
	virtual ~Mapval(){
		delete this;
}
	virtual void dont()=0;
};

#endif /* MAPVAL_H_ */
