
#include "PagedArray.h"
#include "FileManager.h"


//Variables
const int PGSZE= 256;//Tamaño respectivo
const int PGQTY=6;//Cantidad de paginas 

//Puntero al contenedor de las paginas
int* pageCtrPtr[PGQTY];


int lastAccessed=1;
int loadedPages[PGQTY]={1,1,1,1,1,1};

int accessedPages[PGQTY]={0,0,0,0,0,0};
std::FILE* file;


//Constructor de la clase PagedArray
PagedArray::PagedArray(std::FILE* binFile){
    file=binFile;

    for(int i=0; i<PGQTY;i++){
        pageCtrPtr[i]= (int*) malloc(PGSZE* sizeof(int));
        std::fill_n(pageCtrPtr[i], PGSZE,-1);
    }
}

//Overloads of the [] operator
int& PagedArray::operator[](int index){
    int pageCalled= (int) floor(index/PGSZE);
    int pos= index%PGSZE;

    int* page= findPage(pageCalled);
    return page[pos];
}



//Algoritmo de Reemplazo
int PagedArray::replacePage(){
    int replaced=0;
    int maxVal=-1;

    for(int i=0; i<PGQTY; i++){
        if(accessedPages[i]>=maxVal){
            replaced=i;
            maxVal=accessedPages[i];
        }
        if(loadedPages[i]==lastAccessed){
            continue;
        }
        if (loadedPages[i]==-1){
            replaced=i;
            break;
        }
    }
    FileManager::writeNumbers(file, pageCtrPtr[replaced],loadedPages[replaced]);
    delete(pageCtrPtr[replaced]);
    loadedPages[replaced]=-1;

    
    return replaced;
}


//Encuentra la pagina
int* PagedArray::findPage(int page){
    for(int i=0;i<PGQTY; i++){
        if(loadedPages[i]==page){
            lastAccessed=page;
            accessedPages[i]+=1;
            return pageCtrPtr[i];
        }
    }
    int posToLoad=replacePage();
    accessedPages[posToLoad]=0;
    return loadPage(posToLoad,page);
}

//Carga una pagina del disco a la memoria

int* PagedArray::loadPage(int pos, int element){
    int* loadedPage= FileManager::readNumbers(file, pos*PGSZE,PGSZE);
    pageCtrPtr[pos]=loadedPage;
    loadedPages[pos]=element;
    
    return loadedPage;
}

//Finaliza y crea el archivo final
void PagedArray::wrapUp(std::string fileName){
    for(int i=0; i<PGQTY;i++){
        if (loadedPages[i]!=-1){
            FileManager::writeNumbers(file, pageCtrPtr[i], loadedPages[i]);
        }
        FileManager::makeFinalFile(file, fileName);
    }
}