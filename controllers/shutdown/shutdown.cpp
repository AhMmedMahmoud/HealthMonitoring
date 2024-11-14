#include "shutdown.h"
#include <iostream>  
#include <csignal>  
#include <unistd.h>  
#include <cstring> // Include this for strerror  
#include <errno.h> // Include this for errno  
#include <fstream>  
#include <string>  
#include <dirent.h>  
#include <algorithm> // Include this for std::all_of  


/***** constructor ******/
Shutdown::Shutdown(const std::string& _processName) : processName(_processName)
{}

/********** fundemental functions ***********/
SHUTDONW_ReturnType Shutdown::try_shutdown() {
    SHUTDONW_ReturnType _ret; 

    pid_t res = findProcessIdByName(processName);

    if(res == -1) {
        _ret = SHUTDONW_ReturnType::E_PROCESS_NO_FOUND;
    }
    else {
        pid_t targetPid = res;  

        std::cout << "Sending SIGTERM to process " << targetPid << std::endl;  
        if (kill(res, SIGTERM) == 0) {  
            std::cout << "Signal sent successfully." << std::endl;  
            return SHUTDONW_ReturnType::E_OK;
        } 
        else {  
            std::cerr << "Error sending signal: " << strerror(errno) << std::endl;  
            return SHUTDONW_ReturnType::E_NOT_OK;
        }  
    }

    return _ret;
}

/********* helper functions *****************/
pid_t Shutdown::findProcessIdByName(const std::string& processName) {  
    DIR* dir = opendir("/proc");  
    struct dirent* entry;  

    if (dir == nullptr) {  
        perror("opendir /proc");  
        return -1;  
    }  

    while ((entry = readdir(dir)) != nullptr) {  
        // Check if the directory name is a number (PID)  
        if (entry->d_type == DT_DIR) {  
            std::string pidStr = entry->d_name;  
            if (std::all_of(pidStr.begin(), pidStr.end(), isdigit)) {  
                // Construct the path to the status file  
                std::string statusFilePath = "/proc/" + pidStr + "/comm";  
                std::ifstream statusFile(statusFilePath);  

                if (statusFile.is_open()) {  
                    std::string name;  
                    statusFile >> name; // Read the name from the file  

                    if (name == processName) {  
                        closedir(dir);  
                        return std::stoi(pidStr); // Return the PID found  
                    }  
                }  
            }  
        }  
    }  

    closedir(dir);  
    return -1; // Not found  
}  