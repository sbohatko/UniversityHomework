#include <iostream>
#include <string>
#include <vector>
using namespace std;

int M(string source, string phrase, int& check)
{
vector<int> shift;
for(int i = phrase.size() - 1; i < source.size(); i++)
if(source[i] == phrase[phrase.size() - 1])
    shift.push_back(i);
int c = 0, match = 0; int i = 0;
for(int k : shift){
if(i > k) continue;
i = k;
match = 0;
 
for(int j = phrase.size() - 1; j >= 0; --j) {
check++;
if(source[i - (phrase.size() - 1 - j)] == phrase[j]) match++;
else if ((source[i - (phrase.size() - 1 - j)] != phrase[j]) && j ==
phrase.size() - 1)
    break;
else
{
i = i + j;
j = phrase.size();
continue; }
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
cout << "Number of phrases in the source string: " << M(source, phrase, check) << endl;
cout << "Comparison: " << check;
return 0;
}