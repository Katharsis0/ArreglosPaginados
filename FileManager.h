#pragma once

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

class FileManager{
    public:

    static FILE* openFile(std::string fileName, std::string fopenMode);
    static void writeNumbers(FILE* fileName, int* arr, int page);;
    static int* readNumbers(FILE* binFilePtr, int start, int length);
    static FILE* makeTempFile();
    static FILE* translateToBin(FILE *fileName);
    static void writeBinFile(FILE* file, int num);
    static void makeFinalFile(FILE* binFile, std::string fileName);
    static long getFileSize(FILE *binFileptr);
    

};