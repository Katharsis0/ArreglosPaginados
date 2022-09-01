#pragma once
#include "PagedArray.h"
#include <iostream>
#include <cstdio>
#include <vector>


class SortingAlgos{

    public:
            //Algoritmos de ordenamiento
           static void selectionSort(PagedArray* pagedArray, int size);
           static void quickSort(PagedArray* pagedArray, int low, int high);
           static void insertionSort(PagedArray* pagedArray,int size);

};