#ifndef FILE_WRITER
#define FILE_WRITER

#include <iostream>
#include <fstream>
#include <string>

class FileWriter {
private:
    /******** attributes ******/
    std::string filename;
    std::ofstream fileStream;
    bool isOpen;

public:
    /********* parametrized constructor ******/
    FileWriter(const std::string& file);

    /********* deconstructor **********/
    ~FileWriter();

    /********* fundemetal functions ******/
    bool openExistingFile();

    bool openFile();

    bool write(const std::string& data);

    void close();

    bool isFileOpen() const;

    bool isFileExist() const;
};

#endif