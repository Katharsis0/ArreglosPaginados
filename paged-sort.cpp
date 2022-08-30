//Tarea extraclase Sebastian Hidalgo Vargas
//main
#include "SortingAlgos.h"
#include "cmdline.h"
#include "FileManager.h"

int main(int argc, char* argvc[]){

    cmdline::parser P;
    //Prueba B
    // P.add<std::string>("Input",'i',"Input File", true,"");
    // P.add<std::string>("Algorithm", 'a', "Sorting Algorithm to apply", true, "",cmdline::oneof<std::string>("QS","IS","SS"));
    // P.add<std::string>("Output",'o',"Output File", true,"resFile.txt");
    // P.parse_check(argc,argvc);
    //sustitucion
    std::FILE* file= FileManager::openFile("1kb.txt","r");
    SortingAlgos* algo= new SortingAlgos();

    //prueba B
    //std::FILE* file= FileManager::openFile(P.get<std::string>("Input"),"r");//r for reading the stream
    std::FILE* binFile=FileManager::translateToBin(file);

    long len= FileManager::getFileSize(binFile)/sizeof(int);
    
    PagedArray pagedArray= PagedArray(binFile);

    //sustitucion
    algo->quickSort(&pagedArray, 0, (int)(len-1));
    pagedArray.wrapUp("resFile");

    //prueba B
    //std::string algorithm= P.get<std::string>("Algorithm");
    // if(algorithm=="QS"){
    // SortingAlgos::quickSort(&pagedArray, 0, (int)(len-1));
    // }
    // else if(algorithm=="SS"){
    // SortingAlgos::selectionSort(&pagedArray,(int)len);
    // }else if(algorithm=="IS"){
    //     SortingAlgos::insertionSort(&pagedArray,(int)(len));
    // }

    //Prueba B
    //pagedArray.wrapUp(P.get<std::string>("output"));


    return 0;
}