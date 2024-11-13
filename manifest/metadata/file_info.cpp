#include "file_info.h"

/***** getter and setter *****/
std::string FileInfo::getName() {
    return name;
}

std::string FileInfo::getPath() {
    return path;
}


void FileInfo::setName(std::string name) {
    this->name = name;
}

void FileInfo::setPath(std::string path) {
    this->path = path;
}

/********* empty constructor ********/
FileInfo::FileInfo() 
{}

/***** parametrized constructor *****/
FileInfo::FileInfo(std::string _name, std::string _path) : name(_name), path(_path)
{}

void FileInfo::parse(const rapidjson::Value& fileinfo) {
    if (fileinfo.HasMember("Name") && fileinfo["Name"].IsString()) 
    {
        name = fileinfo["Name"].GetString();
    } 
    else 
    {
        std::cerr << "FileName is missing or not a string" << std::endl;
    }


    if (fileinfo.HasMember("Path") && fileinfo["Path"].IsString()) 
    {
        path = fileinfo["Path"].GetString();
    } 
    else 
    {
        std::cerr << "FilePath is missing or not a string" << std::endl;
    }    
}

void FileInfo::print() {
    std::cout << "Name: " << name << "\n";
    std::cout << "Path: " << path << "\n";
}