//============================================================================
// Name        : SWC.cpp
// Author      : Michael Bastos
// Version     :
// Copyright   : This is open source software
// Description : C++ Crawler
//============================================================================

#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdlib>
//#include <locale>
//#include <sstream>
#include <sys/stat.h>
//#include <sys/types.h>
//#include <fstream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <regex.h>
//#include <string.h>
//#include <algorithm>   // remove_if()
//#include <cctype>      // isspace()
//#include <functional>  // ptr_fun <>
//#include <boost/regex.hpp>


#include "Crawler.h"
#include "Database.h"
#include "IO.h"
#include "Parser.h"
#include "Storage.h"
using namespace std;

int main(int argc, char *argv[]) {
	Storage cache;
	cache.checkForCacheFolder();
    for (int i=0; i < argc; i++){
    	//cout << argv[i] << endl;
        IO argument;
        argument.processArguments(argv[i],cache);
    }
    return 0;
}
