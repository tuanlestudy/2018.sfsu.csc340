//
//  fileIOs_wordPairs.h
//  codeLab04
//
//  Created by Le Tuan on 4/2/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#ifndef fileIOs_wordPairs_h
#define fileIOs_wordPairs_h

#include <iostream>
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
// Header file contents
bool sentenceSplitter( string& fname, vector<string>& sentences);
bool wordpairMapping( vector<string>& sentences, map< pair<string,string>, int>&wordpairFreq_map);
bool freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string,string> > &freqWordpair_mmap );
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt);

void printTest();

#endif /* fileIOs_wordPairs_h */
