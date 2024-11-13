#include "text_info.h"

/******** getter and setter  ******/
std::string TextInfo::getValue() {
    return value;
}

void TextInfo::setValue(std::string value) {
    this->value = value;
}

/******* empty constructor ******/
TextInfo::TextInfo(): value("") 
{}

/******* parametrized constructor ********/
TextInfo::TextInfo(std::string _value) : value(_value)
{}

/********* helper functions *********/
void TextInfo::parse(const rapidjson::Value& textinfo) {
    if (textinfo.HasMember("Value") && textinfo["Value"].IsString()) 
    {
        value = textinfo["Value"].GetString();
    } 
    else 
    {
        std::cerr << "Text is missing or not a string" << std::endl;
    }
}

void TextInfo::print() {
    std::cout << "Text: " << value << "\n";
} 
