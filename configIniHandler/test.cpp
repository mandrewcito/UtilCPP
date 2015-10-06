#include "config.hpp"
#include <string.h>
int main(int argc, char * argv[])
{

 ConfigIniHandler Config("Logger.ini");
 Config.SetString("Setting", "Name", "jianxx");   
 Config.SetInteger("Setting", "Age", 27); 
 Config.SetFloat("Setting", "Height", 1.82f); 
 Config.SetBoolean("Setting", "Marriage", false);  
 std::string szName = Config.GetString("Setting", "Name");   
 int iAge = Config.GetInteger("Setting", "Age"); 
 float fltHieght = Config.GetFloat("Setting", "Height"); 
 bool bMarriage = Config.GetBoolean("Setting", "Marriage"); 
 
 std::cout<<"Name:"<<szName<<std::endl
   <<"Age:"<<iAge<<std::endl 
   <<"Height:"<<fltHieght<<std::endl 
   <<"Marriage:"<<bMarriage<<std::endl;   
 return 1;   
}
