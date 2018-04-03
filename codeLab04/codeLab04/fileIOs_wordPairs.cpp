//
//  fileIOs_wordPairs.cpp
//  codeLab04
//
//  Created by Le Tuan on 4/2/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include "fileIOs_wordPairs.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>


using namespace std;
// Header file contents
bool sentenceSplitter( string& fname, vector<string>& sentences){
    string lines;
    string stringLine;
    ifstream inputFile;
    inputFile.open("SteveJobsSpeech2005.txt");
    if (!inputFile) {
        cerr << "Unable to open file SteveJobsSpeech2005.txt" << endl;
        //exit(1);   // call system to stop
        return false;
    }
    while(inputFile >> lines){
        stringLine += lines + " ";
    }
    //cout << stringLine << endl;
    inputFile.close();
    
    string sentence;
    int beg = 0, end = 0;
    for (int i = 0; i < stringLine.length(); i++){
        if(stringLine[i] == '.' || stringLine[i] == '?'){
            end = i - beg;
            sentence = stringLine.substr(beg,end);
            sentences.push_back(sentence);
            while (!isspace(stringLine[i])){
                i++;
            }
            beg = i + 1;
        }
    }
    
    return true;
}
bool wordpairMapping( vector<string>& sentences, map< pair<string,string>, int>&wordpairFreq_map);
bool freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string,string> > &freqWordpair_mmap );
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt);

void printTest(){
    cout << "HI" << endl;
}
