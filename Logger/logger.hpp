#ifndef _Log_H
#define _Log_H
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>      

/* 
 * 
 * @author: Mandrewcito
 * @description: Un log un poco cutre  
 * @version: 0.1 
 *
 */ 

enum logType{Init=0, 
             Info=1, 
             Error=2, 
             Sumary=3};


static const char *types[] = {"Init","Info", "Error","Sumary" };

#include <string>

class Logger{

public:
   static Logger* Instance();
   bool openLogFile(std::string logFileSrc);
   void writeLine(int level,logType type,std::string msg);// level para el nivel de indent
   bool closeLogFile();

private:
   std::string defaultConfFile = "conf.ini";
   std::string defaultLogFile ="defaultLog.log";
   std::string logFileSrc;
   std::ofstream logFile;
   Logger(){};  // Private so that it can  not be called
   Logger(Logger const&){};             // copy constructor is private
   Logger& operator=(Logger const&){};  // assignment operator is private
   static Logger* m_pInstance;
};

#endif
