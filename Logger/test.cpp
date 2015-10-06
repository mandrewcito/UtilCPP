#include "logger.hpp"

int main(){

std::string cadena="eeeeeeeeeehhhhh ";


Logger::Instance()->openLogFile("logFile.txt");

Logger::Instance()->writeLine(1,Error,cadena);
Logger::Instance()->writeLine(3,Error,cadena);
Logger::Instance()->writeLine(5,Error,cadena);

Logger::Instance()->writeLine(3,Sumary,cadena);
Logger::Instance()->writeLine(1,Init,cadena);
Logger::Instance()->writeLine(1,Info,cadena);



return 0;
}
