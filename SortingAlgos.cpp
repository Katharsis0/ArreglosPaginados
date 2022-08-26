#include <iostream>
#include <cstdio>
using namespace std;

//Funcion auxiliar que intercambia dos elementos
void swap(int* numA, int* numB){
    
    int temp= *numA;
    *numA=*numB;
    *numB=temp;
}
//Funcion auxiliar que toma el ultimo elemento como pivote, lo posiciona correctamente, y ubica todos los elementos mayores a la derecha y todos los menores a su izquierda. 
int partition(int arr[], int low, int high){
    
    //pivote
    int pivot= arr[high];
    //indice menor elemento
    int i = low-1;
    for(int j=low; j<=high-1;j++){
        //Si el elemento es menor al pivote
        if(arr[j]<pivot){
        i++;
        swap(&arr[i],&arr[j]);
    }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}


//low es el indice inicial y high es el indice final    
void quickSort(int arr[],int low,int high){
    if (low<high){

        int pivot= partition(arr, low, high);
        //Ordena elementos antes y despues de realizar la particion del arr
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);

    }
}

//Funcion para mostrar el arreglo
void showArray(int arr[], int size){
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    cout<<endl;

    }
}
