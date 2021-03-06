//
// config.hpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:25:22 2014 camill_n
// Last update Sun Oct 19 18:25:39 2014 camill_n
//

#ifndef CONFIG_H_
# define CONFIG_H_

#include <iostream>
#include <map>
#include <deque>
#include "network.hpp"

using namespace std;

class KernelController;

class ConfigController
{
public:
  map<string, string> currentConfig;
  ConfigController(KernelController *kernel);
  virtual ~ConfigController();
  string *getConfig(string configName);
  string *GetDataInFile(string *fileName, string *dataName);
  void	 SaveData(string fileName, char sep, map<string, string> *splitTab);
  void	 SaveData(string fileName, deque<string> *splitTab);
  bool	ReadConfig(KernelController *kernel);
  bool	getAllDataInFile(string fileName, map<string, string> *splitTab);
  bool	getAllDataInFile(string fileName, KernelController *kernel);
};

int	Split(vector<string>&vecteur, string buffer, char sep);

#endif
