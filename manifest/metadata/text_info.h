#ifndef TEXT_INFO_H
#define TEXT_INFO_H

#include "manifest_headers.h"

class TextInfo
{
private:
    /****** attributes ********/
    std::string value;

public:
    /******** getter and setter  ******/
    std::string getValue();
    void setValue(std::string value);

    /******* empty constructor ******/
    TextInfo();

    /******* parametrized constructor ********/
    TextInfo(std::string _value);

    /********* helper functions *********/
    void parse(const rapidjson::Value& file);
    void print(); 
};

#endif