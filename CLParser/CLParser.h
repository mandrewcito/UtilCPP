#ifndef CLParser_H
#define CLParser_H
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

class CLParser
{
public:

    CLParser(int argc_, char * argv_[],bool switches_on_=false);
    ~CLParser(){}

    string get_arg(int i);
    string get_arg(string s);
	bool has_arg(string s);

private:

    int argc;
    vector<string> argv;

    bool switches_on;
    map<string,string> switch_map;
};

#endif
