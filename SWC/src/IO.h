/*
 * IO.h
 *
 *  Created on: May 5, 2012
 *      Author: michael
 */

#ifndef IO_H_
#define IO_H_
#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
#include "Storage.h"
namespace std {

class IO {
public:
	IO();
	virtual ~IO();
	void processArguments(std::string inputs, Storage cache);
};

} /* namespace std */
#endif /* IO_H_ */
