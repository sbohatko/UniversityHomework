#include <iostream>
#include <string>
using namespace std;

int Straight(string source, string phrase, int& check)
{
    int c = 0, match = 0;
    for(int i = 0; i < source.size() - phrase.size(); ++i)
    {
        match = 0;
        for(int j = 0; j < phrase.size(); ++j)
        {
            check++;
            if(source[i + j] == phrase[j]) match++;
            else break;
        }
        if (match == phrase.size()) c++;
    }
    return c;
}
int main() {
    string source, phrase;
    int check = 0;
    cout << "Enter text: ";
    getline(cin, source);
    cout << "Enter text to search: ";
    getline(cin, phrase);
    cout << "Number of phrases in the source string: " << Straight(source, phrase,check) << endl;
    cout << "Comparison: " << check;
    return 0;
}
