#ifndef MANIFEST_TYPES
#define MANIFEST_TYPES

enum class MANIFEST_ReturnType{
    E_OK = 0,
    E_MANIFEST_FILE_NOT_EXIST = 1,
    E_MANIFEST_FORMAT_NOT_CORRECT = 2,
    E_MANIFEST_NOT_CONTAIN_KEY_FILEINFO = 3,
    E_MANIFEST_NOT_CONTAIN_KEY_DELAY = 4
};

#endif