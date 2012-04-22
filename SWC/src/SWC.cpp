//============================================================================
// Name        : SWC.cpp
// Author      : Michael Bastos
// Version     :
// Copyright   : This is open source software
// Description : C++ Crawler
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <locale>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
using namespace std;
void downloadUrl (const char *path, string url, string urlhash);
void loadpage(const char *p, string url, string urlhash);



int main(int argc, char *argv[])
{

	locale loc;
	const collate<char>& coll = use_facet<collate<char> >(loc);
	//cout << "There are " << argc << " arguments:" << endl;
	if(mkdir("cache",0777)==-1)//creating a directory
	{
	        //cerr<<"Caching..." <<endl;
	}

    // Loop through each argument and print its number and value
    for (int i=0; i < argc; i++){
        std::string inputs = argv[i];
        long inputhash = coll.hash(inputs.data(),inputs.data()+inputs.length());
        std::string hash;
        std::stringstream strstream;
        strstream << inputhash;
        strstream >> hash;
        string path = "cache/" + hash;
        const char *p;
        p=path.c_str();
        cout << p << endl;
        if(inputs.find("http://") != string::npos){
        	cout << i << " " << inputs << " " << inputhash << endl;
        	loadpage(p,inputs,hash);
        }
    }

    return 0;
}

void downloadUrl (const char *path, string url, string urlhash){
	std::string command = "cd cache && wget " + url + " --output-document=" + urlhash + " --continue --force-html";
	system(command.c_str());
	//cout << command << endl;
	loadpage(path,url,urlhash);
}

void loadpage(const char *path, string url, string urlhash){
	string line;
	ifstream read (path);//reading a file
	if (read.is_open()) {
		while (! read.eof() ) {
			getline (read,line);
			cout<<line<<endl;
	    }
	    read.close();
	} else {
		downloadUrl(path,url,urlhash);
	}
}