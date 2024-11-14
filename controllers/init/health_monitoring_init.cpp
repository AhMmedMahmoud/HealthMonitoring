#include<iostream>
#include<thread>
#include<chrono>
#include "health_monitoring_init.h"
#include "../../manifest/manager/manifest_manager.h"
#include "../../file_writer/file_writer.h"


/********* constructor ********/
HealthMonitoringInit::HealthMonitoringInit() : InitAbstract()
{}

/********** fundemental functions ***********/
INIT_ReturnType HealthMonitoringInit::try_init() {
    INIT_ReturnType result;

    // path is relative to the excutable (binary in build directory) no source code
    ManifestManager parser("../manifest/manifest.json");
    
    MANIFEST_ReturnType parsingResult = parser.parseJSON();
    
    if(parsingResult == MANIFEST_ReturnType::E_OK) {
        fileinfo = parser.getFileInfo();
        delayinfo = parser.getDelayInfo();
        textinfo = parser.getTextInfo();

        fileinfo.print();
        delayinfo.print();
        textinfo.print();
        
        result = INIT_ReturnType::E_OK;
    }
    else {
        std::cout << "Failling ...\n";
        result = static_cast<INIT_ReturnType>(parsingResult);
    }

    return result;
}

/********* getters and setters *****/
FileInfo HealthMonitoringInit::getFileInfo() {
    return fileinfo;
}

DelayInfo HealthMonitoringInit::getDelayInfo() {
    return delayinfo;
}

TextInfo HealthMonitoringInit::getTextInfo() {
    return textinfo;
}