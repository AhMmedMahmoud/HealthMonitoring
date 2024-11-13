#include "manifest_manager.h"
#include "../metadata/file_info.h"

/*********** constructor ***********/
ManifestManager::ManifestManager(std::string _jsonFilePath) noexcept : jsonFilePath{_jsonFilePath}
{}


/********** getter and setter ******/
std::string ManifestManager::getJsonFilePath()
{
    return jsonFilePath;
}

void ManifestManager::setJsonFilePath(std::string _jsonFilePath)
{
    jsonFilePath = _jsonFilePath;
}

FileInfo ManifestManager::getFileInfo() {
    return parsedFileInfo;
}

DelayInfo ManifestManager::getDelayInfo() {
    return parsedDelayInfo;
}

TextInfo ManifestManager::getTextInfo() {
    return parsedTextInfo;
}

/******* fundmental functions ******/
MANIFEST_ReturnType ManifestManager::parseJSON() 
{    
    // Open the file
    FILE* fp = fopen(jsonFilePath.c_str(), "rb");
    if (!fp) {
        std::cerr << "Could not open file: " << jsonFilePath << std::endl;
        return MANIFEST_ReturnType::E_MANIFEST_FILE_NOT_EXIST;
    }

    // Read the file
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    // Parse the JSON
    rapidjson::Document document;
    document.ParseStream(is);
    fclose(fp);

    if (document.HasParseError()) {
        std::cerr << "Error parsing JSON" << std::endl;
        return MANIFEST_ReturnType::E_MANIFEST_FORMAT_NOT_CORRECT;
    }

    // Accessing FileInfo  
    if (document.HasMember("FileInfo") && document["FileInfo"].IsArray()) {  
        const rapidjson::Value& fileInfoArray = document["FileInfo"];  
        for (rapidjson::SizeType i = 0; i < fileInfoArray.Size(); i++) {  
            parsedFileInfo.parse(fileInfoArray[i]);
        }  
    }  
    else {
        std::cout << "manifest doesnot contain ley called FileInfo\n";
        return MANIFEST_ReturnType::E_MANIFEST_NOT_CONTAIN_KEY_FILEINFO;
    }
 
    // Accessing Delay
    if (document.HasMember("Delay") && document["Delay"].IsArray()) {  
        const rapidjson::Value& delayArray = document["Delay"];  
        for (rapidjson::SizeType i = 0; i < delayArray.Size(); i++) {  
            parsedDelayInfo.parse(delayArray[i]);
        }  
    }  
    else {
        std::cout << "manifest doesnot contain Key called Delay\n";
        return MANIFEST_ReturnType::E_MANIFEST_NOT_CONTAIN_KEY_FILEINFO;
    }

    // Accessing Text
    if (document.HasMember("Text") && document["Text"].IsArray()) {  
        const rapidjson::Value& textArray = document["Text"];  
        for (rapidjson::SizeType i = 0; i < textArray.Size(); i++) {  
            parsedTextInfo.parse(textArray[i]);
        }  
    }  
    else {
        std::cout << "manifest doesnot contain Key called Delay\n";
        return MANIFEST_ReturnType::E_MANIFEST_NOT_CONTAIN_KEY_FILEINFO;
    }
    
    return MANIFEST_ReturnType::E_OK;
}

