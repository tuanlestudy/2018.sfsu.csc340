//
//  main.cpp
//  CSC340-CodingLab01
//
//  Created by Le Tuan on 2/16/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

char PrintMenu(){
    char choice;
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cout << endl;
    
    return choice;
}

int GetNumOfNonWSCharacters(const string myString){
    int result = 0;
    char nextChar;
    // checks each character in the string
    for (int i=0; i<int(myString.length()); i++)
    {
        nextChar = myString.at(i); // gets a character
        if (!isspace(nextChar))   result++;
    }
    return result;
}

int GetNumOfWords(const string myString){
    string newString = myString;
    string editedString;
    char nextChar;
    char temp;
    int j;
    // checks each character in the string
    for (int i=0; i<int(newString.length()); i++)
    {
        nextChar = newString.at(i); // gets a character
        editedString = editedString + nextChar;
        if (isspace(nextChar)){
            j=i;
            while(true){
                temp= newString.at(j);
                if (isspace(temp))  j++;
                else{
                    i = j - 1;
                    break;
                }
            }
        }
    }
    //cout << editedString<< endl;
    int result=0;
    int i;
    // checks each character in the string
    for (i=0; i<int(editedString.length()); i++)
    {
        nextChar = editedString.at(i); // gets a character
        if (isspace(nextChar))
        {
            result++;
        }
    }
    if (!isspace(editedString.at(i-1))) result++;
    return result;
}

int FindText(string phrase, string myString){
    int result = 0;
    int i=0;
    
    //phrase = "some water";
    //myString = "I want some water. I had some water earlier, but now he has some water.";
    //cout <<phrase.length() << "    "<<myString.length()<< endl;
        for(i=0;i<int(myString.length());i++){
            //cout << myString.at(i) << endl;
            int j = 0;
            if(phrase.at(0)==myString.at(i)){
                //cout <<phrase.at(j) << "    "<<myString.at(i)<< endl;
                for(j=1;j<int(phrase.length());j++){
                    //cout <<j<<" "<<phrase.at(j) << "    "<<myString.at(i+j)<< endl;
                    if(phrase.at(j)!=myString.at(i+j)) {
                        break;
                    }
                    if ((j)==(int(phrase.length())-1)) result++;
                }
            }
        }
    return result;
}

string ReplaceExclamation(string myString){
    string newString = myString;
    char nextChar;
    // checks each character in the string
    for (int i=0; i<int(newString.length()); i++)
    {
        nextChar = newString.at(i); // gets a character
        if (nextChar == '!') newString.at(i)='.';
    }
    return newString;
}

string ShortenSpace(string myString){
    string newString = myString;
    string editedString;
    char nextChar;
    char temp;
    int j;
    // checks each character in the string
    for (int i=0; i<int(newString.length()); i++)
    {
        nextChar = newString.at(i); // gets a character
        editedString = editedString + nextChar;
        if (isspace(nextChar)){
            j=i;
            while(true){
                temp= newString.at(j);
                if (isspace(temp))  j++;
                else{
                    i = j - 1;
                    break;
                }
            }
        }
    }
    return editedString;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string phrase;
    string str;
    char choice;
    cout << "Enter a sample text: " << endl;
    getline(cin, str);
    //str = "We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!";
    cout << "You entered: " << str << endl << endl;;
    
    /*GetNumOfNonWSCharacters(str);
    GetNumOfWords(str);
    FindText(str);
    ReplaceExclamation(str);
    ShortenSpace(str);*/
    while (true){
        choice = PrintMenu();
        if (choice == 'c')  {
            int result = GetNumOfNonWSCharacters(str);
            cout << "Number of non-whitespace characters: " << result << endl;}
        else if (choice == 'w'){
            int result = GetNumOfWords(str);
            cout << "Number of words: " << result << endl;}
        else if (choice == 'f'){
            cin.ignore();
            cout <<"Enter a word or phrase to be found:" << endl;
            getline(cin,phrase);
            int result = FindText(phrase, str);
            cout << "\"" << phrase << "\" instances: " << result << endl;
        }
        else if (choice == 'r'){
            string newString = ReplaceExclamation(str);
            cout << "Edited text: " << newString << endl;
        }
        else if (choice == 's'){
            string editedString = ShortenSpace(str);
            cout << "Edited text: " << editedString << endl;
        }
        else if (choice == 'q'){  break;}
    }
    return 0;
}


