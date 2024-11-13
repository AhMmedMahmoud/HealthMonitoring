#ifndef FILE_INFO_H
#define FILE_INFO_H

#include "manifest_headers.h"

class FileInfo
{
    private:
        /***** attributes *****/
        std::string name;
        std::string path;

    public:
        /***** getter and setter *****/
        std::string getName();
        std::string getPath();
        void setName(std::string name);
        void setPath(std::string path);

        /********* empty constructor ********/
        FileInfo();

        /***** parametrized constructor *****/
        FileInfo(std::string _name, std::string _path);

        /********* helper functions *********/
        void parse(const rapidjson::Value& file);
        void print();
};

#endif