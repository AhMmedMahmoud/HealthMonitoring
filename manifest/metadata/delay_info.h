#ifndef DELAY_INFO_H
#define DELAY_INFO_H

#include "manifest_headers.h"

class DelayInfo
{
private:
    /****** attributes ********/
    int value;

public:
    /******** getter and setter  ******/
    int getValue();
    void setValue(int value);

    /******* empty constructor ******/
    DelayInfo();

    /******* parametrized constructor ********/
    DelayInfo(int _value);

    /********* helper functions *********/
    void parse(const rapidjson::Value& file);
    void print(); 
};

#endif