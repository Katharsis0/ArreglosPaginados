//Tarea extraclase Sebastian Hidalgo Vargas
#include "SortingAlgos.cpp"

int main(){

    int s[]={25,12,1,45,28,6,3,8,4,9,10,69,420,287,5};
    int n=sizeof(s)/sizeof(s[0]);
    //quickSort(s,0,n-1);
    insertionSort(s,n);
    cout <<"Sorted array: \n";
    showArray(s,n);

    return 0;
}