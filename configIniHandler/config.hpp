#ifndef CONFIG_H
#define CONFIG_H
#include <string.h>
#include <iostream>
class ConfigIniHandler
{

public:

 ConfigIniHandler(std::string szFileName);

 int GetInteger(std::string section, std::string key);
 float GetFloat(std::string section, std::string key);
 bool GetBoolean(std::string section, std::string key);
 std::string GetString(std::string section, std::string key);

 /* if a section doesnt exists, creates it */
 void SetInteger(std::string section, std::string key, int iValue);
 void SetFloat(std::string section, std::string key, float fltValue);
 void SetBoolean(std::string section, std::string key, bool bolValue);
 void SetString(std::string section, std::string key, std::string strValue);

 void deleteKey(std::string section,std::string key);
 void deleteSection(std::string section);

private:
  std::string m_szFileName;

};
#endif
