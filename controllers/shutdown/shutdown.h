#ifndef SHUTDOWN_H
#define SHUTDOWN_H

#include <iostream>  
#include <csignal>  
#include <unistd.h>  
#include <cstring> // Include this for strerror  
#include <errno.h> // Include this for errno  

#include "shutdown_returnType.h"

class Shutdown {
private:
    /****** attributes ******/
    std::string processName;

public:
    /***** constructor ******/
    Shutdown(const std::string& _processName);

    /********** fundemental functions ***********/
    SHUTDONW_ReturnType try_shutdown();

    /********* helper functions *****************/
    pid_t findProcessIdByName(const std::string& processName);
};

#endif