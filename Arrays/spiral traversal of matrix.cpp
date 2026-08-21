#include <iostream>
using namespace std;

int main() {
    int m = 4, n = 4;
    int* arr = new int[m*n]{ 
        1,   2,  3, 4,
        5,   6,  7, 8,
        9,  10, 11, 12,
        13, 14, 15, 16
    };
    int top = 0, bottom = m-1, left = 0, right = n-1;
    while (top<=bottom && left<=right){
        for (int i{left} ; i<=right ; ++i){
            cout << arr[top*n+i] << ' ';
        }
        ++top;
        for (int i{top} ; i<=bottom ; ++i){
            cout << arr[i*n+right] << ' ';
        }
        --right;
        if (top<=bottom){
            for (int i{right} ; i>=left ; --i){
                cout << arr[bottom*n+i] << ' ';
            }
            --bottom;
        }
        if (left<=right){
            for (int i{bottom} ; i>=top ; --i){
                cout << arr[i*n+left] << ' ';
            }
            ++left;
        }
    }
    delete[] arr;
    return 0;
}
