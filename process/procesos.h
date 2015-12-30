#ifndef Procesos_H
#define Procesos_H
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <errno.h>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include "util.h"
using namespace std;
int exec(string str,bool redirect,string ficheroRedirect);
#endif