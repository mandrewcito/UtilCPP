#include "configReader.hpp"

int dividir(char * cadena, char * trozos[])
{
    int i=1;
    if ((trozos[0]=strtok(cadena,"="))==NULL)return 0;
    while ((trozos[i]=strtok(NULL,"="))!=NULL)i++;
    return i;
}

std::vector<std::string> getFileToVector(std::string src){
  std::vector<std::string> lines;
  lines.reserve(MAX_LINES); //maximo 100 lineas de config 

  std::string fileName(src);

  std::ifstream file;
  file.open(fileName.c_str());

  if(!file.is_open())
  {
    perror("Error opening file ");
    exit(0);
  }

  //Read the lines and store it in the vector
   std::string line;
   while(getline(file,line))
   {
     lines.push_back(line);
   }

   file.close();
   return lines;
}

ConfigReader::ConfigReader(std::string srcFile){
  std::vector<std::string> myLines =getFileToVector(srcFile);
  for(auto i : myLines) {
    char  *trozos[16];
    char *cstr = new char[i.length() + 1];
    strcpy(cstr, i.c_str());
    int numTrozos= dividir(cstr,trozos);
    if (numTrozos!=2) continue;
    fileMap.insert(std::pair<std::string,std::string>(trozos[0],trozos[1]));
  }
}

std::string ConfigReader::getString(std::string field){
  return fileMap[field];
}

bool ConfigReader::getBoolean(std::string field){
  bool valor=false;
  if (strcmp(fileMap[field].c_str(),"true") == 0)
    valor=true;
  else if (strcmp(fileMap[field].c_str(),"true") == 0)
    valor=false;
  else
     throw std::invalid_argument("boolean value must be true or false ");
  return valor;
    
}

int ConfigReader::getInteger(std::string field){
  if (strcmp(fileMap[field].c_str(),"true") == 0)
     return 0;
  int num = atoi(fileMap[field].c_str());
  if (num == 0) 
      throw std::invalid_argument(" invalid integer ");
  return num;
}

float ConfigReader::getFloat(std::string field){
  return atof(fileMap[field].c_str());
}




