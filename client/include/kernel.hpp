//
// kernel.hpp for ppm in /home/camill_n/pinkponymonitoring/client
//
// Made by camill_n
// Login   <camill_n@epitech.net>
//
// Started on  Sat Oct 11 14:36:07 2014 camill_n
// Last update Sat Oct 11 18:44:25 2014 camill_n
//

#ifndef KERNEL_H_
# define KERNEL_H_

#include "config.hpp"
#include "network.hpp"

class KernelController
{
public:
  NetworkController	*network;
  ConfigController	*config;
};

#endif