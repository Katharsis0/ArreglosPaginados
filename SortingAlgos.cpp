
#include "SortingAlgos.h"
#include "PagedArray.h"
//QUICK SORT

//Funcion auxiliar que intercambia dos elementos
void swap(int* numA, int* numB){
    
    int temp= *numA;
    *numA=*numB;
    *numB=temp;
}
//Funcion auxiliar que toma el ultimo elemento como pivote, lo posiciona correctamente, y ubica todos los elementos mayores a la derecha y todos los menores a su izquierda. 
int partition(PagedArray* pagedArray, int low, int high){
    
    //pivote
    int pivot= pagedArray->operator[](high);
    //indice menor elemento
    int i = low-1;
    for(int j=low; j<=high-1;j++){
        //Si el elemento es menor al pivote
        if(pagedArray->operator[](j)<pivot){
        i++;
        swap(&(pagedArray->operator[](i)),&(pagedArray->operator[](j)));
    }
    }
    swap(&(pagedArray->operator[](i+1)),&(pagedArray->operator[](high)));
    return (i+1);
}

//Funcion para mostrar el arreglo
//void showArray(PagedArray* pagedArray, int size){
  //  for(int i=0; i<size;i++){
    //    cout<<pagedArray[i]<<" ";
    //cout<<endl;

    //}
//}

//QuickSort
//low es el indice inicial y high es el indice final    
void quickSort(PagedArray* pagedArray,int low,int high){
    if (low<high){

        int pivot= partition(pagedArray, low, high);
        //Ordena elementos antes y despues de realizar la particion del arr
        quickSort(pagedArray, low, pivot-1);
        quickSort(pagedArray, pivot+1, high);

    }
}
//InsertionSort
void insertionSort(PagedArray* pagedArray, int size) 
{ 
    int flag, j; 
    for (int i = 1; i < size; i++)
    { 
        flag = pagedArray->operator[](i); 
        j = i - 1; 
  
        //Mueve los elementos del array que son mayores a flag un espacio mas de la position actual
        while (j >= 0 && pagedArray->operator[](j) > flag)
        { 
            pagedArray->operator[](j + 1) = pagedArray->operator[](j); 
            j = j - 1; 
        } 
        pagedArray->operator[](j + 1) = flag; 
    } 
}
//SelectionSort
void selectionSort(PagedArray* pagedArray, int size){
    int minVal,i,j;

    for(i=0;i<(size-1);i++){
        //Encontrar el minimo elemento en el arreglo
        minVal=i;
        for(j=i+1;j<size;j++)
        if(pagedArray->operator[](j)<pagedArray->operator[](minVal))
            minVal=j;
          
        if(minVal!=i){
            //swap
            swap(&(pagedArray->operator[](i)),&(pagedArray->operator[](minVal)));
        }

    }
}
