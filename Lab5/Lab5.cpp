// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// using reference params &
char getEncodedChar(char inputChar, const vector<char>& codeTable) {
    if (inputChar >= 65 && inputChar <= 90) {  // is a capital letter
        return codeTable[inputChar - 65];
    }
    else if (inputChar >= 97 && inputChar <= 122) {  // is lower case letter
        char upperCaseLetter = inputChar - 32;  // converts the character to upper case character
        char upperCaseCode = codeTable[upperCaseLetter - 65];  // get upper case code
        return upperCaseCode + 32;  // convert code back to lower case
    }
    else {  // is not letter
        return inputChar;
    }
}

// encodes the string 
string encodeText(const string& inputText, const vector<char>& codeTable) {
    string encodedText;
    for (char c : inputText) {
        encodedText.push_back(getEncodedChar(c, codeTable));
    }
    return encodedText;
}

int main() {
	string text;

	vector<char> codeTable = { 'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E' };
    
    cout << "Input text to cypher: ";
    getline(cin, text);

    string encodedText = encodeText(text, codeTable);
    cout << "Encoded message: " << '"' << encodedText << '"' << endl;
}
