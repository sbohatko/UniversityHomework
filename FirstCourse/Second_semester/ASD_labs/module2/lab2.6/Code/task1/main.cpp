
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int KMP(string source, string phrase, int& check) {
    vector<int> shift;
    for(int i = 0; i < source.size() - phrase.size() + 1; i++)
        if(source[i] == phrase[0])
            shift.push_back(i); int c = 0, match = 0;
    for(int i : shift)
    {
        match = 0;
        for(int j = 0; j < phrase.size(); ++j) {
            check++;
            if(source[i + j] == phrase[j]) match++; else break;
        }
        if (match == phrase.size()) c++; }
    return c; }
int main() {
    string source, phrase;
    int check = 0;
    cout << "Enter text: ";
    getline(cin, source);
    cout << "Enter text to search: ";
    getline(cin, phrase);
    cout << "Number of phrases in the source string: "
         << KMP(source, phrase, check) << endl; cout << "Comparison: " << check; return 0;
}
