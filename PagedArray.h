#pragma once

#include <stdio.h>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class PagedArray{
    public:

    PagedArray(FILE* binaryFile);
    //Overloading [] operator para acceder a los elementos como si fuera un array.
    int& operator[](int index);
    //Replacement algorithm
    int replacePage();
    int* findPage(int page);   
    int* loadPage(int pos, int element);
    void wrapUp(std::string fileName);

};