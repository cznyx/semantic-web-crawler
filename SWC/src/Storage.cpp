/*
 * Storage.cpp
 *
 *  Created on: May 5, 2012
 *      Author: michael
 */

#include "Storage.h"

namespace std {

Storage::Storage() {
	// TODO Auto-generated constructor stub

}

Storage::~Storage() {
	// TODO Auto-generated destructor stub
}

void Storage::checkForCacheFolder(){
	if(mkdir("cache",0777)==-1)//creating a directory
		{
		        cerr<<"Caching...\n" <<endl;
		}
}

void Storage::generateUrlHash(std::string url){
	locale loc;
	const collate<char>& coll = use_facet<collate<char> >(loc);
	long urlhash = coll.hash(url.data(),url.data()+url.length());
	std::string hash;
	std::stringstream strstream;
	strstream << urlhash;
	strstream >> hash;
	string path = "cache/" + hash;
	const char *p;
	p=path.c_str();
	//cout << p << endl;
	cout << " " << url << " " << hash << endl;
	//loadPage(p,url,hash);
}

} /* namespace std */
