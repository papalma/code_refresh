#include <iostream>
#include <sstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cstring>

// #include "mydebug.h"

using namespace std;

char stringFilter(char c) 
{
    return islower(c) ? c : ' ';
}

int main()
{
    int noDoc;
    cin >> noDoc;
	int doc = 1;

    string line;
    getline(cin, line);
    while( noDoc-- ) {

		// this holds words and its id
		unordered_map<string,int> wordCatalog;
		vector<int> textLabeled;

        while( getline(cin, line) ) {
            if( line == "END" ) break;

            transform(line.begin(), line.end(), line.begin(), stringFilter);
            istringstream iss(line);
            string word;

			while( iss >> word ) {
				// insert do not overwrite values
				wordCatalog.insert({word, wordCatalog.size()});
				textLabeled.push_back(wordCatalog[word]);
			}	
        }

		// processing part
		// int noWords = wordCatalog.size();
		int i = 0, j = 0, totalWordsInRange = 0;
		int p = 0, q = textLabeled.size()-1;
		int wordInRange[100000];
		memset(wordInRange, 0, sizeof wordInRange);

		for(; j<textLabeled.size(); ++j) {

			int label = textLabeled[j];
			wordInRange[label]++;
			if (wordInRange[label] == 1) totalWordsInRange++;

			while( totalWordsInRange == wordCatalog.size() && i<=j ) {

				if( j-i < q-p) {
					p = i;
					q = j;
				}
				// println("i=", i, "j=",j);

				auto iLabel = textLabeled[i++];
				wordInRange[iLabel]--;
				if(wordInRange[iLabel] == 0) totalWordsInRange--;
			}
		}
		printf("Document %d: %d %d\n", doc++, p+1, q+1);
    }
    return 0;
}