#include "diskWriter.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include "io/rowelement.h"

using namespace std;

void DiskWritwer::writeElement(string path, RowElement * archivo){
    std::ofstream fileOut(path.c_str(),ios::out | ios::binary | ios::app);
    fileOut.write(reinterpret_cast<char*>(archivo),sizeof(RowElement)*3+sizeof(int)+sizeof(char)*16);
    fileOut.close();
}

RowElement DiskWritwer::viewElement(string path, int ofset){
    RowElement *rowelement=new RowElement[3];
    ifstream fileIn(path.c_str(),ios::in | ios::binary);
    fileIn.seekg(ofset);
    fileIn.read(reinterpret_cast<char*>(rowelement),sizeof(RowElement)*3+sizeof(int)+sizeof(char)*16);
    fileIn.close();
    return *rowelement;
}

void DiskWritwer::deleteElement(std::string path, int ofset){
    int nData=0;
    WriteLevels(path,ofset,nData);

}

void DiskWritwer::WriteLevels(string path,int ofset, int nChange){
    std::ofstream fileOut(path.c_str(),ios::out | ios::binary );
    fileOut.seekp(ofset);
    fileOut.write(reinterpret_cast<char*>(nChange),sizeof(int));
    fileOut.close();
}


int DiskWritwer::ReadLevels(string path,int ofset){
    int num;
    std::ifstream fileIn(path.c_str(),ios::in | ios::binary );
    fileIn.seekg(ofset);
    fileIn.Read(reinterpret_cast<char*>(num),sizeof(int));
    fileIn.close();
    return num;
}

