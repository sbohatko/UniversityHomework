#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    const int N = n;
  int matrix[N][N];
  for (int x = 0; x < N; x++) 
    for (int y = 0; y < N; y++) {
        if (x >= y) matrix[x][y] = 1;
        else matrix[x][y] = 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cout << matrix[i][j] << " ";
    cout << endl;
  }
  return 0;
}