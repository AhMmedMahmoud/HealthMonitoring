#include "file_writer.h"

/********* parametrized constructor ******/
FileWriter::FileWriter(const std::string& file) : filename(file), isOpen(false) {}

/********* deconstructor **********/
FileWriter::~FileWriter() {
    if (isOpen) {
        close();
    }
}

/********* fundemetal functions ******/
bool FileWriter::openExistingFile() {
    if(!isFileExist()) {
        std::cout << "file doesnot exist\n";
        return 0;
    }
    
    if(!isOpen) {
        /* std::ofstream::open is used to open an existing file or create a new file for output.*/
        fileStream.open(filename);
        isOpen = fileStream.is_open();
    }
    
    return isOpen;
}

bool FileWriter::openFile() {
    if(!isOpen) {
        /* std::ofstream::open is used to open an existing file or create a new file for output.*/
        fileStream.open(filename);
        isOpen = fileStream.is_open();
    }
    
    return isOpen;
}

bool FileWriter::write(const std::string& data) {
    if (!isOpen) {
        std::cerr << "File is not open." << std::endl;
        return false;
    }
    fileStream << data;

    fileStream.flush(); // Flush the output buffer to ensure data is written to the file  
    
    return fileStream.good(); // Returns true if the last operation was successful.
}

void FileWriter::close() {
    if (isOpen) {
        fileStream.close();
        isOpen = false;
    }
}

bool FileWriter::isFileOpen() const {
    return isOpen;
}

bool FileWriter::isFileExist() const {
    std::ifstream fileCheck(filename);  
    return fileCheck.good(); // Returns true if the file can be opened  
}