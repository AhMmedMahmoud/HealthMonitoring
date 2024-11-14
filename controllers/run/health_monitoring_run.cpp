#include "health_monitoring_run.h"
#include "../../file_writer/file_writer.h"
#include<thread>
#include<chrono>

/****** constructor *****/
HealthMonitoringRun::HealthMonitoringRun(FileInfo _fileinfo, DelayInfo _delayinfo, TextInfo _textinfo) : RunAbstract(), fileinfo(_fileinfo),  delayinfo(_delayinfo), textinfo(_textinfo)
{}

/****** fundemental functions *****/
void HealthMonitoringRun::run() {
    FileWriter fileWriter(fileinfo.getPath() + fileinfo.getName());
    
    //bool res = fileWriter.openFile();
    
    bool res = fileWriter.openExistingFile();

    if(!res) {
        std::cout << "failed in opening file\n";
    }
    else {
        while(res) {
            std::this_thread::sleep_for(std::chrono::seconds(delayinfo.getValue()));
            
            res &= fileWriter.write(textinfo.getValue());            
            if(!res) {
                std::cout << "failed to write\n";
                break;   
            }       
        }
        fileWriter.close();
    }
    
}