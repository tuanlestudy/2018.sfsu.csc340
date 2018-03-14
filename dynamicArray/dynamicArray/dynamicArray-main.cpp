//
//  main.cpp
//  dynamicArray
//
//  Created by Le Tuan on 3/13/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include <iostream>
#include "dynamicArray.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int size = 0;
    int * myArray;
    
    //array_constructor( myArray, size=5);
    myArray = array_constructor(myArray, size);
    
    printTest(myArray, size);
    
    //array_resize( myArray, currSize, newSize);
    int currSize = size;
    int newSize = 0;
    myArray = array_resize(myArray, currSize, newSize);
    currSize = newSize;
    printTest(myArray, currSize);
    
    //array_set( myArray, currSize);
    array_set(myArray, currSize);
    
    printTest(myArray, currSize);
    
    mysort(myArray, currSize, my_less_equal);
    
    printTest(myArray, currSize);
    
    mysort(myArray, currSize, my_greater_equal);
    
    printTest(myArray, currSize);
    
    array_destructor(myArray);
    
    return 0;
}
