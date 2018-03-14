//
//  dynamicArray.h
//  dynamicArray
//
//  Created by Le Tuan on 3/13/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#ifndef dynamicArray_h
#define dynamicArray_h

const int firstValue = 0;
const int secondValue = 1;

int * array_constructor(int *  &intPtr, int &size );
int * array_resize(int * &intPtr, int& currSize, int& newSize);
void array_destructor(int * &intPtr);
void array_set(int* &intPtr, int &size);

void mysort( int* &intPtr, int size, bool (* comp)(int&, int&) );
bool my_less_equal(int& x, int & y);         //return true if x<=y, false otherwise.
bool my_greater_equal(int& x, int & y );    //return true if x>=y, false otherwise


void printTest(int * &intPtr, int &size);
#endif /* dynamicArray_h */
