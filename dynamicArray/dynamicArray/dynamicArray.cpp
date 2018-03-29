//
//  dynamicArray.cpp
//  dynamicArray
//
//  Created by Le Tuan on 3/13/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include "dynamicArray.h"
#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//print test
void printTest(int * &intPtr, int &size){
    //print
    for (int k = 0; k < size; k++){
        cout << intPtr[k] << " ";
    }
    cout << endl;
}


//array_constructor( myArray, size=5);
int * array_constructor(int *  &intPtr, int &size ){
    if (size >= 1) {
        try{
            intPtr = new int [size];
        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }
        
        if (size < 1){
            cout << "Empty value" << endl;
        }else{
            if (size == 1){
                intPtr[0] = firstValue;
            }else if(size == 2){
                intPtr[0] = firstValue;
                intPtr[1] = secondValue;
            }else{
                intPtr[0] = firstValue;
                intPtr[1] = secondValue;
                int temp = secondValue;
                for (int i = 2; i < size; i++){
                    temp += 2;
                    intPtr[i] = intPtr[i-1]+temp;
                }
            }
        }
        return intPtr;
    }else{
        return 0;
    }
}

//array_resize( myArray, currSize, newSize);
int * array_resize(int * &intPtr, int& currSize, int& newSize){
    /*
     currSize==newSize or newSize<0: do nothing
     currSize>newSize: the array's size is reduced to newSize. Furthermore, its content is reduced to its first newSize elements.
     currSize<newSize: the array's size is increased to newSize. The content of the array will be expanded by inserting at the end as many elements as needed to reach newSize. Furthermore, initialize each of the new elements to i*i, where i is the index of the element.
     */
    if (newSize < 1){
        cout << "ERROR. newSize < 1 !!!" << endl;
    }else{
        if(currSize == newSize || newSize < 1){
            cout << "DO NOTHING" << endl;
        }else{
            /*
             int *temp;
             temp = new int[newSize];
             for (int i = 0; i < (newSize); i++) {
             temp[i] = intPtr[i];
             }
             delete[] intPtr;
             intPtr = temp;
             delete [] temp;
             currSize = newSize;
             */
            if (newSize < 1){
                cout << "Empty value" << endl;
            }else{
                array_destructor(intPtr);
                try{
                    intPtr = new int [newSize];
                }
                catch (exception& e)
                {
                    cout << e.what() << '\n';
                }
                if (newSize == 1){
                    intPtr[0] = firstValue;
                }else if(newSize == 2){
                    intPtr[0] = firstValue;
                    intPtr[1] = secondValue;
                }else{
                    intPtr[0] = firstValue;
                    intPtr[1] = secondValue;
                    int temp = secondValue;
                    for (int i = 2; i < newSize; i++){
                        temp += 2;
                        intPtr[i] = intPtr[i-1]+temp;
                    }
                }
            }
        }
    }
    
    return intPtr;
}

void array_destructor(int * &intPtr){
    delete [] intPtr;
    if (intPtr != NULL) {
        intPtr = NULL;
    }
}

//array_set( myArray, currSize);
//Randomizing the content of the dynamic array intPtr by calling the srand() and rand() functions
void array_set(int* &intPtr, int &size){
    //Specifically, after having set a seed value using the srand( time(0) ) function. Then invoke the rand() to assign each element in the array a random value.
    //srand(time(0));    //Unique seed
    
    for (int i = 0; i < size; i++){
        intPtr[i] = rand();
    }
}

void mysort( int* &intPtr, int size, bool (* comp)(int&, int&) ){
    
    if(* comp == my_less_equal){
        for (int i = 0; i < size - 1; i++)
        {
            int minIndex = i;
            
            for (int j = i + 1; j < size; j++)
                if (intPtr[j] < intPtr[minIndex])
                    minIndex = j;
            //swap(x, i, minIndex);
            int temp = intPtr[i];
            intPtr[i] = intPtr[minIndex];
            intPtr[minIndex] = temp;
        }
    }
    
    if(* comp == my_greater_equal){
        for (int i = 0; i < size - 1; i++)
        {
            int maxIndex = i;
            
            for (int j = i + 1; j < size; j++)
                if (intPtr[j] > intPtr[maxIndex])
                    maxIndex = j;
            //swap(x, i, minIndex);
            int temp = intPtr[i];
            intPtr[i] = intPtr[maxIndex];
            intPtr[maxIndex] = temp;
        }
    }
    
}

bool my_less_equal(int& x, int & y){         //return true if x<=y, false otherwise.
    if (x <= y) return true;
    else return false;
}

bool my_greater_equal(int& x, int & y ){    //return true if x>=y, false otherwise
    if (x >= y) return true;
    else return false;
}











