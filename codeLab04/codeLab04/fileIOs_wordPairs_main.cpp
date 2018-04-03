//
//  main.cpp
//  codeLab04
//
//  Created by Le Tuan on 4/2/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include <iostream>
#include "fileIOs_wordPairs.h"
#include <utility>
#include <string>
#include <map>
#include <iterator>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    string fname = "SteveJobsSpeech2005.txt";
    vector<string> sentences;
    //printTest();
    bool check = sentenceSplitter(fname, sentences);
    if (check == true){
        map< pair<string,string>, int> mapPair;
        multimap<int, pair<string, string> > :: iterator it;
        multimap<int, pair<string, string> > multimapPair;
        check = wordpairMapping(sentences,mapPair );
        cout << freqWordpairMmap(mapPair, multimapPair ) << endl;
        cout << multimapPair.size() << endl;
        for(it = multimapPair.begin(); it != multimapPair.end(); it++){
            cout << "<" << it->second.first << ", " << it->second.second << ">: " << it->first << endl;
        }
        printWordpairs(multimapPair,"fileIOs_wordPairs.txt", 5, 5);
    }
    return 0;
}
