#ifndef fileOs_wordPairs_h
#define fileOs_wordPairs_h

#include <vector>
#include <map>

using namespace std;
// Header file contents
bool sentenceSplitter( string& fname, vector<string>& sentences);
/*
period: .,
question mark: ?
period + double quotation mark: ." 
question mark + double quotation mark: ?"
*/
bool wordpairMapping( vector<string>& sentences, map< pair<string,string>, int>&wordpairFreq_map);
bool freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string,string> > &freqWordpair_mmap );
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt);


#endif