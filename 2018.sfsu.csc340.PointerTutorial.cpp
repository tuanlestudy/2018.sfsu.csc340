#include <iostream>
#include <string>

using namespace std;

struct WordFreq{
    string word;
    int freq;
};

const int MAX_CAPACITY = 100;

void push_back(WordFreq* &p_WF, int& capacity, int& size, const WordFreq& wf1);

int main(int argc, const char * argv[]) {
    //q1. please declare an int pointer p_int, an int i1, double d1.
    int *p_int = nullptr, i1=0;//NULL
    double d1 = 0.0;
    
    //declare a WordPreq pointer p_WF and WordFreq object wf1: "hello"/10
    WordFreq *p_WF = nullptr;
    int capacity=0, size=0;
    WordFreq wf1={"hello",10};
    
    //initilize p_WF to a capacity of 20, each obj: ("",0)
    try{
        p_WF = new WordFreq[20];
    }
    catch(std::bad_alloc& ba)
    {
        std::cerr <<"bad_alloc caught when allocating memory to p_WF in main(): " << ba.what() << '\n';
        exit(-1);
    }
    capacity = 20;
    for(int i = 0; i < capacity; i++){
        p_WF[i].word = "";
        (p_WF+i)->freq = 0; //should check again
    }
    
    push_back(p_WF, capacity, size, wf1);
    
    delete [] p_WF;
    
    
    p_WF = &wf1;
    
    //print out wf1's values using p_WF
    cout << (*p_WF).word << (*p_WF).freq << endl;
    cout << p_WF->word << p_WF->freq << endl;
    
    //declare a fixed array of 100 integer arrayInt
    int arrayInt[MAX_CAPACITY];
    int array_size = 0;
    
    //make arrayInt the pointee of p_int
    p_int = arrayInt;
    p_int = &arrayInt[0];
    
    
    //make &arrayInt[20] the pointee of p_int without using &
    p_int += 20;
    
    //q2. make i1 a pointee of p_int
    p_int = &i1;
    
    //q3. change i1's value to 100 using p_int
    *p_int = 100;
    
    //q4. can you make d1 & pointee of p_int? No
    
    return 0;
}

void push_back(WordFreq* &p_WF, int& capacity, int& size, const WordFreq& wf1){
    //Step 1: Check if p_WF has reached its capacity
    if (size == capacity){
        WordFreq *tmpArr=new WordFreq[capacity*2];
        //a. allocate a new space with larger capacity
        
        //e.
        p_WF = tmpArr; capacity *=2; size++;
        
    }
    
    
    
    
    
    
    
    
    
    
    
}
