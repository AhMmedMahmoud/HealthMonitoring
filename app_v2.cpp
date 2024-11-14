#include<iostream>
#include "controllers/init/health_monitoring_init.h"
#include "manifest/metadata/file_info.h"
#include "manifest/metadata/delay_info.h"
#include "manifest/metadata/text_info.h"
#include "controllers/run/health_monitoring_run.h"

int main() {
    HealthMonitoringInit init;
    
    INIT_ReturnType res = init.try_init();
    
    if(res == INIT_ReturnType::E_OK) {  // initalization occurs sucessfully
        // get parsing output
        FileInfo fileinfo = init.getFileInfo();
        DelayInfo delayinfo = init.getDelayInfo();
        TextInfo textinfo = init.getTextInfo();

        // call run class
        HealthMonitoringRun runner(fileinfo, delayinfo, textinfo);
        runner.run();
    }
    else {
        std::cout << "Failed in init\n";
    }

    return 0;
}