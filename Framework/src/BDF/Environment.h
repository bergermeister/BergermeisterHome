/**
 * @file Environment.h
 * @author Eisenberger, Edward (Edward.Eisenberger@live.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BDF_Environment_h
#define BDF_Environment_h

// StdLib Includes
#include <cstring>
#include <cstdint>
#include <string>
#include <chrono>
#include <iostream>

#ifdef __APPLE__
#elif defined _WIN32
#else // Linux
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <gpiod.h>
#endif


#endif

