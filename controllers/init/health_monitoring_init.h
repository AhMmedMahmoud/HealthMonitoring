#ifndef HEALTH_MONITORING_INIT_H
#define HEALTH_MONITORING_INIT_H

#include<string>
#include "init_abstract.h"
#include "../../manifest/metadata/file_info.h"
#include "../../manifest/metadata/delay_info.h"
#include "../../manifest/metadata/text_info.h"

class HealthMonitoringInit : public InitAbstract{
private:
    /****** attributes ******/
    FileInfo fileinfo;
    DelayInfo delayinfo;
    TextInfo textinfo;

public:
    /********* constructor ********/
    HealthMonitoringInit();

    /********* getters and setters *****/
    FileInfo getFileInfo();
    DelayInfo getDelayInfo();
    TextInfo getTextInfo();

    /********** fundemental functions ***********/
    INIT_ReturnType try_init() override;
};

#endif