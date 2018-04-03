//fileIOs_wordPairs_main.cpp
#include <stdio.h>
#include "fileIOs_wordPairs.h"
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

int main()
{
    string f = "SteveJobsSpeech.txt";
    vector<string> sentence;
    bool check = sentenceSplitter(f, sentence);
    map<pair<string, string>, int> mapPair;
    multimap<int, pair<string, string>>::iterator it;
    multimap<int, pair<string, string>> multimapPair;
    check = wordpairMapping(sentence, mapPair);
    cout << freqWordpairMmap(mapPair, multimapPair) << endl;
    cout << multimapPair.size() << endl;
    for (it = multimapPair.begin(); it != multimapPair.end(); it++)
    {
        cout << "< " << it->second.first << " , " << it->second.second << " > : " << it->first << endl;
    }
    printWordpairs(multimapPair, "wordpair.txt", 5, 5);
    return 0;
}
//fileIOs_wordPairs.h
#ifndef fileIOs_wordPairs_h
#define fileIOs_wordPairs_h
#include "fileIOs_wordPairs.cpp"
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <fstream>
#include <set>
#include <stdio.h>
bool sentenceSplitter(string &fname, vector<string> &sentences);
bool wordpairMapping(vector<string> &sentences, map<pair<string, string>, int> &wordpairFreq_map);
bool freqWordpairMmap(map<pair<string, string>, int> &wordpairFreq_map, multimap<int, pair<string, string>> &freqWordpair_mmap);
bool myfunction(int i, int j);
void printWordpairs(multimap<int, pair<string, string>> &freqWordpair_multimap, string outFname, int topCnt, int botCnt);
#endif

// fileIOs_wordPairs.cpp
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <set>
#include <vector>
#include <fstream>
#include <set>
#include <cstring>

using namespace std;

bool sentenceSplitter(string &fname, vector<string> &sentences)
{
    bool success = false;
    ifstream is(fname, std::ifstream::binary);
    if (is)
    {
        // get length of file:
        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);
        char *buffer = new char[length];
        // read data as a block:
        is.read(buffer, length);
        cout << length << endl;
        string line = buffer;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '.')
            {
                if (line[i + 1] == '"')
                {
                    sentences.push_back(line.substr(0, i));
                    line = line.substr(i + 2, line.length());
                    i = 0;
                    continue;
                }
                else
                {
                    sentences.push_back((line.substr(0, i)));
                    line = line.substr(i + 1, line.length());
                    i = 0;
                    continue;
                }
            }
            if (line[i] == '?')
            {
                if (line[i + 1] == '"')
                {
                    sentences.push_back(line.substr(0, i));
                    line = line.substr(i + 2, line.length());
                    i = 0;
                    continue;
                }
                else
                {
                    sentences.push_back((line.substr(0, i)));
                    line = line.substr(i + 1, line.length());
                    i = 0;
                    continue;
                }
            }
        } //for
        success = true;
        return success;
    } //if
    return success;
}

bool wordpairMapping(vector<string> &sentences, map<pair<string, string>, int> &wordpairFreq_map)
{
    bool found = false;
    int count = 0;
    vector<string> vec;
    vector<string> vect;
    vector<string> tokens;
    for (unsigned int i = 0; i < sentences.size(); i++)
    {
        string str = sentences[i];
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        char *pch;
        pch = strtok(cstr, ".");
        while (pch != NULL)
        {
            tokens.push_back(pch);
            pch = strtok(NULL, ".");
        }
    }
    map<pair<string, string>, int>::iterator it;
    string tempo;
    string line = "";
    for (unsigned int i = 0; i < tokens.size(); i++)
    {
        line = tokens[i];
        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == '-')
            {
                line.erase(line.begin() + j);
            }
        }
        vect.push_back(line);
    }
    int temp = 0;
    for (unsigned int i = 0; i < vect.size(); i++)
    {
        vector<string> str;
        string line = vect[i];
        for (int i = 0; i < line.length(); i++)
        {
            if (!isspace(line[i]))
            {
                temp = i;
                while (!isspace(line[i]))
                    i++;
                string word = line.substr(temp, i - temp);
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                str.push_back(word);
            }
        }
        for (unsigned int i = 0; i < str.size(); i++)
        {
            for (int j = i + 1; j < str.size(); j++)
            {
                if ((str[j] < str[i]) && (str[i] != str[j]))
                {
                    tempo = str[i];
                    str[i] = str[j];
                    str[j] = tempo;
                }
            }
        }
        for (unsigned int i = 0; i < str.size(); i++)
        {
            for (unsigned int j = i + 1; j < str.size(); j++)
            {
                if (str[i] == str[j])
                {
                    str.erase(str.begin() + j);
                }
            }
        }
        for (unsigned int k = 0; k < str.size(); k++)
        {
            for (unsigned int l = k + 1; l < str.size(); l++)
            {
                if (str[k] != str[l])
                {
                    bool check = true;
                    pair<string, string> p;
                    p.first = str[k];
                    p.second = str[l];
                    if (!wordpairFreq_map.empty())
                    {
                        for (it = wordpairFreq_map.begin(); it != wordpairFreq_map.end(); it++)
                        {
                            if ((it->first.first == p.first && it->first.second == p.second) || (it->first.second == p.first && it->first.first == p.second))
                            {
                                it->second++;
                                check = false;
                                count++;
                            }
                        }
                        if (check)
                        {
                            wordpairFreq_map.insert(make_pair(make_pair(p.first, p.second), 1));
                            count++;
                        }
                    }
                    if (wordpairFreq_map.empty())
                    {
                        wordpairFreq_map.insert(make_pair(make_pair(p.first, p.second), 1));
                        count++;
                    }
                }
            }
        }
        found = true;
    }
    return found;
}

bool freqWordpairMmap(map<pair<string, string>, int> &wordpairFreq_map, multimap<int, pair<string, string>> &freqWordpair_mmap)
{
    map<pair<string, string>, int>::iterator it1;
    map<pair<string, string>, int>::iterator it3;
    map<pair<string, string>, int>::iterator it2;
    vector<int> freq;
    string temp1;
    string temp2;
    for (it1 = wordpairFreq_map.begin(); it1 != wordpairFreq_map.end(); it1++)
    {
        freq.push_back(it1->second);
    }
    sort(freq.begin(), freq.end());
    freq.erase(unique(freq.begin(), freq.end()), freq.end());
    for (unsigned int i = 0; i < freq.size(); i++)
    {
        for (it2 = wordpairFreq_map.begin(); it2 != wordpairFreq_map.end(); it2++)
        {
            if (it2->second == freq[i])
            {
                pair<string, string> pairs;
                pairs.first = it2->first.first;
                pairs.second = it2->first.second;
                freqWordpair_mmap.insert(make_pair(it2->second, pairs));
            }
        }
        it2 = wordpairFreq_map.begin();
    }
    return true;
}

void printWordpairs(multimap<int, pair<string, string>> &freqWordpair_multimap, string outFname, int topCnt, int botCnt)
{
    ofstream myfile;
    multimap<int, pair<string, string>>::iterator it;
    multimap<int, pair<string, string>>::reverse_iterator rit;
    int count = 0;
    myfile.open(outFname);
    if (myfile.is_open())
    {
        for (it = freqWordpair_multimap.begin(); it != freqWordpair_multimap.end(); it++)
        {
            if (count < topCnt)
            {
                myfile << "<" << it->second.first << ", " << it->second.second << ">: " << it->first << "\n";
                count++;
            }
        }
        count = 0;
        for (rit = freqWordpair_multimap.rbegin(); rit != freqWordpair_multimap.rend(); rit++)
        {
            if (count < botCnt)
            {
                myfile << "<" << rit->second.first << ", " << rit->second.second << ">: " << rit->first << "\n";
                count++;
            }
        }
    }
    else
    {
        cout << "cannot open file" << endl;
    }
    myfile.close();
}