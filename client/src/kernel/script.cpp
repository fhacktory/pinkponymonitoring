//
// script.cpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 22:08:25 2014 camill_n
// Last update Sun Oct 12 01:37:04 2014 camill_n
//

#include "../../include/global.hpp"
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <fstream>

bool		ScriptController::ManageRequestStack(NetworkController *network)
{
  vector<string>	currentRequest;
  string		request;
  int			nbRequest = 0;
  std::vector<string>::iterator it2;

  for (std::vector<string>::iterator it = network->requestStack.begin(); it != network->requestStack.end(); ++it)
    {
      request = *it;
      nbRequest = Split(currentRequest, request, ' ');
      if (nbRequest >= 2)
	{
	  // ADD COMMAND
	  if (currentRequest[0].compare("add") == 0)
	    {
	      if (this->IsAlreadyEnable(currentRequest[1]) == false)
		this->currentScript.push_back(currentRequest[1]);
	    }
	  // // DEL COMMAND
	  // if (currentRequest[0].compare("del") == 0)
	  //   {
	  //     bool	lastElement = false;

	  //     for (std::vector<string>::iterator it = this->currentScript.begin(); !lastElement && it != this->currentScript.end(); ++it)
	  // 	{
	  // 	  if (currentRequest[1].compare((string)*it) == 0)
	  // 	    {
	  // 	      this->currentScript.erase(it);
	  // 	    }
	  // 	}
	  //   }
	}
    }
  return (true);
}

void	ScriptController::ShowScriptEnable()
{
  cout << "Script Enable:" << endl;

  for (std::vector<string>::iterator it = this->currentScript.begin(); it != this->currentScript.end(); ++it)
    {
      cout << *it << endl;
    }
}

bool	ScriptController::IsAlreadyEnable(string needle)
{
  string str;

  for (std::vector<string>::iterator it = this->currentScript.begin(); it != this->currentScript.end(); ++it)
    {
      str = *it;
      if (str.compare(needle) == 0)
	return (true);
    }
  return (false);
}

bool	ScriptController::SaveResponse(string *saveData, string cmdName, string response)
{
  saveData->append(cmdName);
  saveData->append("%20");
  saveData->append(response);
  saveData->append(":");
  return (true);
}

string *ScriptController::ExecScript(NetworkController *network, ConfigController *config)
{
  string *formatLine;
  string scriptName;
  string buffer;
  string outputFile("test");
  string saveData("");

  for (std::vector<string>::iterator it = this->currentScript.begin(); it != this->currentScript.end(); ++it)
    {
      formatLine = new string("./scripts/");
      scriptName = *it;
      formatLine->append(scriptName);
      formatLine->append(" >> " + outputFile);
      cout << "COMMAND EXEC: " << formatLine->data() << endl;
      system(formatLine->data());
      ifstream file(outputFile.data());
      if (file)
	{
	  getline(file, buffer);
	  cout << "REPONSE COMMANDE: " << scriptName.data() << endl << buffer << endl;
	  this->SaveResponse(&saveData, scriptName, buffer);
	  file.close();
	  remove(outputFile.data());
	}
      network->WriteAPI(&saveData, config->GetsetAPI(), config->GetToken());
      free(formatLine);
    }
}
