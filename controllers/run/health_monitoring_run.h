#ifndef HEALTH_MONITORING_RUN_H
#define HEALTH_MONITORING_RUN_H

#include "run_abstract.h"
#include "../../manifest/metadata/file_info.h"
#include "../../manifest/metadata/delay_info.h"
#include "../../manifest/metadata/text_info.h"

class HealthMonitoringRun : public RunAbstract{
private:
    /***** attributes *****/
    FileInfo fileinfo;
    DelayInfo delayinfo;
    TextInfo textinfo;

public:
    /****** constructor *****/
    HealthMonitoringRun(FileInfo fileinfo, DelayInfo delayinfo, TextInfo textinfo);

    /****** fundemental functions *****/
    void run() override;
};

#endif