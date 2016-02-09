#ifndef ConfigReader_H
#define ConfigReader_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <errno.h>
#include <map>
#include <fstream>
/* strcmp */
#include <stdio.h>
#include <string.h>
/*exceptions */
#include <stdexcept>
/* atoi */
#include <stdlib.h>

#define MAX_LINES 100

class ConfigReader
{
public:

    ConfigReader(std::string srcFile);
    ~ConfigReader(){}

    std::string getString(std::string field);
    bool getBoolean(std::string field);
    int  getInteger(std::string field);
    float getFloat(std::string field);

private:

    std::string srcFile;
    std::map<std::string,std::string> fileMap;

};

#endif
