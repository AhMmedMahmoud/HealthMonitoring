#ifndef MANIFEST_MANAGER_H
#define MANIFEST_MANAGER_H

#include "../metadata/manifest_types.h"
#include "../metadata/manifest_headers.h"
#include "../metadata/file_info.h"
#include "../metadata/delay_info.h"
#include "../metadata/text_info.h"

class ManifestManager
{
    private:
        /************ attributes ***********/
        std::string jsonFilePath;
        FileInfo parsedFileInfo;
        DelayInfo parsedDelayInfo;
        TextInfo parsedTextInfo;

    public: 
        /*********** constructor ***********/
        ManifestManager(std::string _jsonFilePath) noexcept;

        /********** getter and setter ******/
        std::string getJsonFilePath();
        FileInfo getFileInfo();
        DelayInfo getDelayInfo();
        TextInfo getTextInfo();
        void setJsonFilePath(std::string _jsonFilePath);

        /******* fundmental functions ******/
        MANIFEST_ReturnType parseJSON(); 
};

#endif