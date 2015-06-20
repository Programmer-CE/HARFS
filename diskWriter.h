#ifndef DISKWRITER_H
#define DISKWRITER_H
#include <iostream>
#include <iostream>
#include <cstring>
#include "io/rowelement.h"

class DiskWritwer{

public:
    DiskWritwer();
    void writeElement(std::string path,RowElement *archivo );
    RowElement viewElement(std::string path,int ofset);
    void deleteElement(std::string path,int ofset);
    void WriteLevels(std::string path,int ofset,int ndata);
};

#endif // DISKWRITER_H
