#include<iostream>
#include "controllers/shutdown/shutdown.h"
#include <thread>
#include <chrono>


int main() {
    std::cout << "--- Killer ---\n";
    
    int count = 0;

    while(count-- > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    Shutdown shutdown("app_v2");
    SHUTDONW_ReturnType res = shutdown.try_shutdown();

    switch(res) {
        case SHUTDONW_ReturnType::E_OK: 
            std::cout << "shutdown sucesses\n";
        break;

        case SHUTDONW_ReturnType::E_PROCESS_NO_FOUND: 
            std::cout << "process not found\n"; 
        break;
    }

    return 0;
}