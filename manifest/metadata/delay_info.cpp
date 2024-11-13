#include "delay_info.h"

/******** getter and setter  ******/
int DelayInfo::getValue() {
    return value;
}

void DelayInfo::setValue(int value) {
    this->value = value;
}

/******* empty constructor ******/
DelayInfo::DelayInfo(): value(-1) 
{}

/******* parametrized constructor ********/
DelayInfo::DelayInfo(int _value) : value(_value)
{}

/********* helper functions *********/
void DelayInfo::parse(const rapidjson::Value& delayinfo) {
    if (delayinfo.HasMember("Value") && delayinfo["Value"].IsInt()) 
    {
        value = delayinfo["Value"].GetInt();
    } 
    else 
    {
        std::cerr << "Delay is missing or not a Int" << std::endl;
    }
}

void DelayInfo::print() {
    std::cout << "Delay: " << value << "\n";
} 
