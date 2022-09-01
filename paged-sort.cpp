//Tarea extraclase Sebastian Hidalgo Vargas
//main
#include "SortingAlgos.h"
#include "cmdline.h"
#include "FileManager.h"

int main(int argc, char* argvc[]){

    cmdline::parser P;

    P.add<std::string>("Input",'i',"Input File", true,"");
    P.add<std::string>("Algorithm", 'a', "Sorting Algorithm to apply", true, "",cmdline::oneof<std::string>("QS","IS","SS"));
    P.add<std::string>("Output",'o',"Output File", true,"resFile.txt");
    P.parse_check(argc,argvc);

    std::FILE* file= FileManager::openFile(P.get<std::string>("Input"),"r");//r for reading the stream
    std::FILE* binFile=FileManager::translateToBin(file);

    long len= FileManager::getFileSize(binFile)/sizeof(int);
    
    PagedArray pagedArray= PagedArray(binFile);

    std::string algorithm= P.get<std::string>("Algorithm");

    if(algorithm=="QS"){
    SortingAlgos::quickSort(&pagedArray, 0, (int)(len-1));
    }
    else if(algorithm=="SS"){
    SortingAlgos::selectionSort(&pagedArray,(int)len);
    }else if(algorithm=="IS"){
        SortingAlgos::insertionSort(&pagedArray,(int)(len));
    }
    pagedArray.wrapUp(P.get<std::string>("Output"));
     //int s[]={25,12,1,45,28,6,3,8,4,9,10,69,420,287,5};
    //int n=sizeof(s)/sizeof(s[0]);
    //quickSort(s,0,n-1);
    //insertionSort(s,n);
    //selectionSort(s,n);
    //cout <<"Sorted array: \n";
    //showArray(s,n);


    return 0;
}