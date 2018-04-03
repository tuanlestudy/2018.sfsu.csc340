//
//  main.cpp
//  codeLab04
//
//  Created by Le Tuan on 4/2/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include <iostream>
#include "fileIOs_wordPairs.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {

    string fname = "SteveJobsSpeech2005.txt";
    vector<string> sentences;
    printTest();
    bool check = sentenceSplitter(fname, sentences);
    
    return 0;
}
