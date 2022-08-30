#include "FileManager.h"

#include <iostream>
#include <fstream>

using namespace std;

//Chequea si el archivo existe
bool fileExists(const char* fileName){
    //Construye un objeto ifstream asociado con el fileName
    //en su argumento
    std::ifstream inFile(fileName);
    bool exists=inFile.good();
    return exists;
}
//Abre el archivo
std::FILE* FileManager::openFile(string fileName, string fopenMode){
    std:FILE* filePtr;

    if (!fileExists(fileName.c_str()) || (filePtr=std::fopen(fileName.c_str(), fopenMode.c_str()))==NULL){
        cout <<"Couldn't open selected file: " + fileName << endl;
        exit(EXIT_FAILURE);
    };
    return filePtr;
}

//Genera un archivo temporal en binario
std::FILE* FileManager::makeTempFile(){
    std::FILE* tmpFile= std::tmpfile();
    return tmpFile;
}

//Traduce una lista de enteros separados por coma en un archivo de texto a binario
std::FILE* FileManager::translateToBin(std::FILE* fileName){
    int asciiCode;
    string tmpNum;

    //Reposiciona el indicador asociado al stream a una nueva posicion.
    std::fseek(fileName,0,SEEK_SET);

    std::FILE* binFile= FileManager::makeTempFile();
    //fgetc retorna el character del stream. EOF= End of file.
    while((asciiCode=std::fgetc(fileName)!=EOF)){
        char asciiData= asciiCode;
        if(asciiCode==44){

            try{
                FileManager::writeBinFile(binFile, std::stoi(tmpNum));

            } catch(std::invalid_argument& ){
                std::cout <<"Data fetched from input file is invalid. It must be a list of integers separated by comma.";
                exit(EXIT_FAILURE);
            }
            tmpNum= "";
            continue;
        }
        tmpNum+=asciiData;
    }
    if(tmpNum!= ""){
        FileManager::writeBinFile(binFile, std::stoi(tmpNum));
    }
    return binFile;

}

//Escribe los numeros en el archivo binario
void FileManager::writeBinFile(std::FILE* file, int num){
    std::fseek(file,0,SEEK_END);
    std::fwrite(&num,sizeof(int), 1, file);

}

//Escribe el array de numeros en el archivo binario
void FileManager::writeNumbers(std::FILE* file, int* arr, int page){

    if(page==-1){
        return;
    }
    int PGSIZE=256;
    std::fseek(file, sizeof(int)*page*PGSIZE, SEEK_SET);
    for(int i=0; i<PGSIZE; i++){
        if(arr[i]==-1){continue;}
        std::fwrite(&arr[i], sizeof(int), 1, file);
    }
}
//Crea el archivo final
void FileManager::makeFinalFile(FILE* binFile, std::string fileName){
    std::FILE* filePtr= std::fopen(fileName.c_str(),"wb");
    std::fclose(filePtr);

    std::ofstream out(fileName.c_str());

    std::fseek(binFile, 0, SEEK_END);
    long size= ftell(binFile);

    std::fseek(binFile,0,SEEK_SET);

    int length= size/sizeof(int);

    for(int i=0; i<length; i++){
        int result;

        std::fread(&result, sizeof(int),1, binFile);
        out <<result;

        if(i+1<length){
            out<<",";
        }




    }
}


//Lee el array de numeros en el archivo binario
int* FileManager::readNumbers(FILE* binFilePtr, int start, int length){
    
    static int* resPtr;
    resPtr= (int*) malloc(length*sizeof(int));
    std::fill_n(resPtr,length,-1);
    std::fseek(binFilePtr, sizeof(int)*start, SEEK_SET);

    for (int i=0; i<length;i++){
        std::fread(&resPtr[i], sizeof(int),1,binFilePtr);
    }
    return resPtr;
}
//Obtiene el tamaño del file
long FileManager::getFileSize(FILE* binFile){
    std::fseek(binFile, 0L, SEEK_END);
    long size= ftell(binFile);

    std::fseek(binFile, 0, SEEK_SET);
    
    return size;
}


