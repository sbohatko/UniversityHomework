#include <iostream>
using namespace std;

int main(){
    const int rows = 3;
    const int collums = 3;

    int matrix[rows][collums] = { {1,0,9}, {1,2,9}, {2,3,9} };
    /*
    [1,0,2]
    [1,2,3]
    [2,3,0]

    1 - без нулів
    2 - с нулями
    */
    
    int non_zero_collums = 3;
    for(int col = 0; col < collums; col++){
        for(int elem = 0; elem < collums; elem++){
            if(matrix[col][elem] == 0){
                non_zero_collums--;
                break;
            }
        }
    }

    cout << "non-zero collums: " << non_zero_collums << endl;
    cout << "collums with zero: " << collums - non_zero_collums << endl;
}
