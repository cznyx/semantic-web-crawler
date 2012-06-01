/*
 * Storage.h
 *
 *  Created on: May 5, 2012
 *      Author: michael
 */

#ifndef STORAGE_H_
#define STORAGE_H_
#include <iostream>
#include <sys/stat.h>
#include <locale>
#include <sstream>
namespace std {

class Storage {
public:
	Storage();
	virtual ~Storage();
	void checkForCacheFolder();
	void generateUrlHash(std::string url);
};

} /* namespace std */
#endif /* STORAGE_H_ */
