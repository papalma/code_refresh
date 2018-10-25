#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

// no case sensitive
// punctuation marks should not be considered
// words max len is 20 chars, no more that 100000 words in each text

string markEndText = "****END_OF_TEXT****";
string markEndInput = "****END_OF_INPUT****";

unordered_map<string, int> wordFreqTable;
int wordCounter;

double Et() {
    double sum = 0.0;
    double l10wc = log10(wordCounter);

    for(auto k : wordFreqTable) {
        sum += k.second*(l10wc -log10(k.second));
    }
    return sum/wordCounter;
}

char myTransform(char c) {
    if(c == '-' || c=='\'') {
        return c;
    }
    if(isalnum(c)) {
        return tolower(c);
    }
    return ' ';
}

void produceResults()
{
    double et = Et();
    auto erel = et*100/log10(wordCounter);
    printf("%d %.1lf %.0lf\n",wordCounter,et,erel);

    wordFreqTable.clear();
    wordCounter = 0;
}

void readData(string line) {
    transform(begin(line), end(line), begin(line), myTransform);
    for(int i=1; i<line.length(); i++) {
        if(line[i] == '.' && isalpha(line[i-1])) {
            line[i] = ' ';
        }
    }
    istringstream is(line);
    string token;
    while(is >> token) {
        wordCounter++;
        wordFreqTable[token]++;
    }
}

int main() {
    string line;
    while(getline(cin, line)) {
        if( line == markEndText ) {
            produceResults();
            continue;
        }
        else if( line == markEndInput) {
            break;
        }
        readData(line);
    }
    return 0;
}