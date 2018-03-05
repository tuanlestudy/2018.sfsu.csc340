//
//  main.cpp
//  2018sfsu.csc340.pseudo-coding
//
//  Created by Le Tuan on 3/4/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct TokenFreq {
    string word1;
    string word2;
    int freq;
};

void sentencesSplitter(string & aritcle, vector<TokenFreq> & tfVec);
int tokenizer(string sentences, vector<TokenFreq> tfVec, int indexVec);
void printVector(vector<TokenFreq>  tfVec);

//main

int main(int argc, const char * argv[]) {
    //string ostr = ostr2;
    string istr = "It's really a milestone in Chinese science fiction. This is the best place in the world.";

    vector<TokenFreq> tfVec;
    sentencesSplitter(istr, tfVec);
    printVector(tfVec);
    return 0;
}
//-----

void tokenizer(string sentences, vector<TokenFreq> & tfVec, int & indexVec) {
    int index_sentences = 0;
    int end_sentences = 0;
    string word;
    string word1temp;
    string word2temp;
    bool check = false;
    for (int j = 0; j < sentences.length(); j++) {
        if (isspace(sentences.at(j))) {
            end_sentences = j;
            word1temp = sentences.substr(index_sentences, end_sentences - index_sentences);
            index_sentences = j + 1;
            for (int k = j + 1; k < sentences.length(); k++) {
                if (isspace(sentences.at(k))) {
                    check = false;
                    end_sentences = k;
                    word2temp = sentences.substr(index_sentences, end_sentences - index_sentences);

                    if (word1temp != word2temp) {
                        if (indexVec == 0){
                            cout << "test" << endl;
                            try{
                                tfVec[indexVec].word1 = word1temp;
                            }catch(int e){
                                cout << e << endl;
                            }
                            cout << "test" << endl;
                            tfVec[indexVec].word2 = word2temp;
                            cout << "test" << endl;
                            tfVec[indexVec].freq = 1;
                            cout << "test" << endl;
                            tfVec.push_back(TokenFreq());
                            cout << "test" << endl;
                            indexVec++;
                        }else{
                            cout << "test" << endl;
                            for (int n = 0; n < int(tfVec.size()); n++) {
                                cout << "test2" << endl;
                                if (tfVec[n].word1 == word1temp && tfVec[n].word2 == word2temp) {
                                    tfVec[n].freq++;
                                    check = true;
                                    break;
                                    //skip
                                }
                                if (tfVec[n].word1 == word2temp && tfVec[n].word2 == word1temp) {
                                    tfVec[n].freq++;
                                    check = true;
                                    break;
                                }
                            }
                            if (check == false){
                                tfVec[indexVec].word1 = word1temp;
                                tfVec[indexVec].word2 = word2temp;
                                tfVec[indexVec].freq = 1;
                                tfVec.push_back(TokenFreq());
                                indexVec++;
                            }

                        }
                    }

                }
            }//end-for-k
        }
    }//end-for-j
    return;
}//end-void

void sentencesSplitter(string & article, vector<TokenFreq> & tfVec) {
    int index_sentences = 0;
    int end_sentences = 0;
    string sentences;
    int indexVec = 0;
    for (int i = 0; i < article.length(); i++) {
        if (article.at(i) == '.') {
            end_sentences = i;
            sentences = article.substr(index_sentences, end_sentences - index_sentences);
            sentences = sentences + " "; //set all sentences have the space in the end
            //cout << sentences << endl;
            indexVec = tokenizer(sentences, tfVec, indexVec);
            index_sentences = i + 2;
        }
    }
}

void printVector(vector<TokenFreq> & tfVec) {
    for (int i = 0; i < int(tfVec.size()); i++) {
        cout << "('" << tfVec[i].word1 << "', '" << tfVec[i].word2 << "') " << tfVec[i].freq << endl;
        //cout << tfVec[i].token<<endl;;
    }
    cout << endl;
}

