#include <stddef.h>  // defines NULL
#include "logger.hpp"
/* 
 * 
 * @author: Mandrewcito
 * @info: GOTO logger.hpp
 *
 */

// Global static pointer used to ensure a single instance of the class.
Logger* Logger::m_pInstance = NULL;  

/** This function is called to create an instance of the class. 
    Calling the constructor publicly is not allowed. The constructor 
    is private and is only called by this Instance function.
*/
  
Logger* Logger::Instance()
{
   if (!m_pInstance)   // Only allow one instance of class to be generated.
      m_pInstance = new Logger;

   return m_pInstance;
}
/**
 * @Params :
 *	logFIleSr: log file path
 *	
 *	
 */

bool Logger::openLogFile(std::string logFileSrc){
  if (logFile.is_open()) return false;
  if (strcmp(logFileSrc.c_str(),"") == 0)
    logFileSrc = defaultLogFile;
  logFile.open(logFileSrc, std::ios_base::app | std::ios_base::out);
  return logFile.is_open();
}

/**
 * @Params :
 *	level: Indent level
 *	logType: type of log
 *	msg: log line 	
 */

void Logger::writeLine(int level,logType type,std::string msg){

  std::string line = "";
  for(int i =0;i<level;i++)
    line.insert(0,"  ");
  line+=std::string(types[type])+":";
  line+=msg;
  logFile << line<<std::endl;
	
}

bool Logger::closeLogFile(){
  if (logFile.is_open()){
    logFile.close();
    return true;
  }
  return false;
}

