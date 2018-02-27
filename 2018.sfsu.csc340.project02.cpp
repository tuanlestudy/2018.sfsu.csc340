//
//  main.cpp
//  2018sfsu.csc340.project02
//
//  Created by Le Tuan on 2/21/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

void matrixInit( vector< vector<int> >& matrix, int numRows, int numCols);

struct TokenFreq{
    string token;
    int freq;
};

string spaces(string& istr, string& newstr);
void printVector(vector<TokenFreq> & tfVec);
void getTokenFreqVec( string& istr, vector<TokenFreq> & tfVecVec);

void selectionSort( vector<TokenFreq> & tokFreqVector );   //This function receives a vector of TokenFreq objects by reference and applies the selections sort algorithm to sort this vector in increasing order of token frequencies.

void insertionSort( vector<TokenFreq> & tokFreqVector );


//main
int main(int argc, const char * argv[]) {
    
    vector<vector<int> > matrix;
    matrixInit(matrix, 3, 4);
    
    string ostr1 = "And no, I'm not a walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
    string ostr2 = "  ";
    string ostr3 = "No one wants to die. Even people who want to go to heaven don’t want to die to get there. And yet death is the destination we all share. No one has ever escaped it. And that is as it should be, because Death is very likely the single best invention of Life. It is Life’s change agent. It clears out the old to make way for the new. Right now the new is you, but someday not too long from now, you will gradually become the old and be cleared away. Sorry to be so dramatic, but it is quite true. Your time is limited, so don’t waste it living someone else’s life. Don’t be trapped by dogma — which is living with the results of other people’s thinking. Don’t let    the noise of others’ opinions drown out your own inner voice. And most important, have the courage to follow your heart and intuition. They somehow already know what you truly want to become. Everything else is secondary. When I was young, there was an amazing publication called The Whole Earth Catalog, which was one of the bibles of my generation. It was created by a fellow named Stewart Brand not far from here in Menlo Park, and he brought it to life with his poetic touch. This was in the late 1960s, before personal computers and desktop publishing, so it was all made with typewriters, scissors and Polaroid cameras. It was sort of like Google in paperback form, 35 years before Google came along: It was idealistic, and overflowing with neat tools and great notions.Stewart and his team put out several issues of The Whole Earth Catalog, and then when it had run its course,     they put out a final issue. It was the mid-1970s, and I was your age. On the back cover of their final issue was a photograph of an early morning country road, the kind you might find yourself hitchhiking on if you were so adventurous. Beneath it were the words: “Stay Hungry. Stay   Foolish.” It was their farewell message as they signed off. Stay Hungry. Stay Foolish. And I have always wished that for myself. And now, as you graduate to begin anew, I wish that for you.Stay Hungry. Stay Foolish.";
    //string ostr = ostr2;
    string istr;
    
    cout << "Enter the text: ";
    getline(cin, istr);

    vector<TokenFreq> tfVec;
    getTokenFreqVec(istr, tfVec);
    selectionSort(tfVec);
    insertionSort(tfVec);
    
    /*
    //error symbol '-'
    for (int i = 0; i < ostr2.length(); i++){
        if (ostr2[i] == '\342') i++;
        if (ostr2[i] == '\200') i++;
        if (ostr2[i] == '\224') i++;
        
        cout << i << "||" << ostr2.at(i) << endl;
    }*/
    
    return 0;
}
//-----

void selectionSort( vector<TokenFreq> & tokFreqVector ){
    TokenFreq temp;
    int min;
    
    for( int i = 0; i < int(tokFreqVector.size()-1); i++){
        min = i;
        for (int j = i+1; j <int(tokFreqVector.size()); j++){
            if (tokFreqVector[j].freq < tokFreqVector[min].freq)
                min = j;
        }
        if(min!=i)
        {
            temp = tokFreqVector[i];
            tokFreqVector[i] = tokFreqVector[min];
            tokFreqVector[min] = temp;
        }
    }
    cout<<"-----selectionSort------------------"<<endl;
    printVector(tokFreqVector);
}

void insertionSort( vector<TokenFreq> & tokFreqVector ){
    TokenFreq temp;
    int max;
    
    for( int i = 0; i < int(tokFreqVector.size()-1); i++){
        max = i;
        for (int j = i+1; j < int(tokFreqVector.size()); j++){
            if (tokFreqVector[j].freq > tokFreqVector[max].freq)
                max = j;
        }
        if(max!=i)
        {
            temp = tokFreqVector[i];
            tokFreqVector[i] = tokFreqVector[max];
            tokFreqVector[max] = temp;
        }
    }
    cout<<"-----insertionsort------------------"<<endl;
    printVector(tokFreqVector);
}




string spaces(string& istr, string & newstr){
    int j;
    //Check double space and create new string with lowercase
    for (int i = 0; i < int(istr.length()); ++i){
        istr[i] = tolower(istr[i]);
        if (isspace(istr[i])){
            //check double space again
            j = i+1;
            while(true){
                if (istr[j] == '\342') istr[j]=' ';
                if (istr[j] == '\200') istr[j]=' ';
                if (istr[j] == '\224') istr[j]=' ';
                if(isspace(istr[j]))    j++;
                else break;
            }
            i=j-1;
            newstr = newstr + istr[i];
        }else
            newstr = newstr + istr[i];
    }
    //cout << istr << endl;
    //cout << str1 << endl;
    //cout << istr.length() << endl;
    //cout << str1.length() << endl;
    return newstr;
}
void getTokenFreqVec( string& istr, vector<TokenFreq> & tfVec){
    string newstr;
    int curr_beg = 0;
    int curr_end = 0;
    string word;
    bool check = false;
    int index=0;
    
    //call func spaces to get new string
    newstr = spaces(istr, newstr);
    //cout << newstr << endl;
    //cout << endl;
    //cout << newstr << "||" << endl;
    string tempstr = newstr;
    
        if(newstr != " "){
            tfVec.push_back(TokenFreq());
        }
    for (int i = 0; i < int(newstr.length()); ++i){
        if(isspace(newstr[i])){
            check = false;
            
            curr_end = i;
            //if(tempstr[curr_beg]=='-') curr_end=curr_beg+1;
            word = tempstr.substr(curr_beg, curr_end - curr_beg);
            //cout << word << "||"<<curr_beg << "^"<<curr_end<< endl;
            curr_beg = i + 1;
            
            //if(int(word.length()) <= 2) cout<<word<< endl;
            
            for (int j = 0; j < int(tfVec.size()); j++){
                if (tfVec[j].token == word){
                    tfVec[j].freq++;
                    //cout<<"test: "<<tfVec[j].token<<" "<<tfVec[j].freq<< endl;
                    check = true;
                    
                    break;
                }
            }//end-for;
            if (check == false && i!=(int(newstr.length())-1)){
                //cout <<"**"<< word <<"**"<<word.length()<< endl;
                tfVec[index].token=word;
                tfVec[index].freq=1;
                index++;
                tfVec.push_back(TokenFreq());
            }
            word = "";
            //add last value
        }
    }//end-for
    
    //chang the last value if no space in the end sentence
    if(!isspace(newstr[int(newstr.length())-1])){
        word = tempstr.substr(curr_beg, curr_end - (int(newstr.length())-1));
        tfVec[index].token=word;
        tfVec[index].freq=1;
        //tfVec.push_back(TokenFreq());
    }
    
    printVector(tfVec);

}

void printVector(vector<TokenFreq> & tfVec){
    
    cout << "size= {" << tfVec.size() << endl;
    for (int i = 0; i < int(tfVec.size()); i++){
        cout << "  [" << i << "] = (token = \""<< tfVec[i].token <<"\", freq = " << tfVec[i].freq << ")" << endl;
        //cout << tfVec[i].token<<endl;;
    }
    cout << endl;
}

void matrixInit( vector< vector<int> >& matrix, int numRows, int numCols){
    int i;
    int j;
    matrix.resize(numRows, vector<int>(numCols) );
    for(i = 0; i< numRows; i++ ){
        for(j = 0; j < numCols; j++ )
            matrix[i][j] = i*j;
    }
    
    cout << "size of matrix is: " << numRows << "x" << numCols << endl;
    for (i = 0; i < numRows; i++){
        for (j = 0; j < numCols; j++){
            cout<< "matrix[" << i << "][" << i << "]=" << matrix[i][j] << endl;
        }
    }
    cout << endl;
}
