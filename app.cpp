#include<iostream>
#include<thread>
#include<chrono>
#include "manifest/manager/manifest_manager.h"
#include "file_writer/file_writer.h"

int main() {
    std::cout << "Health Monitoring Application\n";

    // path is relative to the excutable (binary in build directory) no source code
    ManifestManager parser("../manifest/manifest.json");
    
    MANIFEST_ReturnType parsingResult = parser.parseJSON();
    
    if(parsingResult == MANIFEST_ReturnType::E_OK) {
        FileInfo fileinfo = parser.getFileInfo();
        DelayInfo delayinfo = parser.getDelayInfo();
        TextInfo textinfo = parser.getTextInfo();

        fileinfo.print();
        delayinfo.print();
        textinfo.print();

        FileWriter fileWriter(fileinfo.getPath() + fileinfo.getName());
        bool res = fileWriter.open();

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
    else {
        std::cout << "Failling ...\n";
    }
   
    return 0;
}