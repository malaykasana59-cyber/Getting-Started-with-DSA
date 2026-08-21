#include <iostream>
#include <algorithm>
using namespace std;

// brute o(n2) o(n2)

// int main() {
//     int m=3, n=3;
//     int arr[m * n]{
//         1, 2, 3,
//         4, 5, 6,
//         7, 8, 9
//     };
//     int temp[m*n]{};
//     for (int i{} ; i<m ; ++i){
//         for (int j{} ; j<n ; ++j){
//             temp[i*n+j]=arr[(m-j-1)*n+i];
//         }
//     }
//     for (int i{} ; i<m*n ; ++i){
//         if (i%3==0) cout << '\n';
//         cout << temp[i] << ' ';
//     }
//     return 0;
// }

// optimal o(n2) o(1)
// transpose and reverse the matrix

int main(){
    int m=3, n=3;
    int* arr= new int [m * n]{
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    for (int i{} ; i<m ; ++i){
        for (int j{i+1} ; j<n ; ++j){
            swap(arr[i*n+j],arr[j*m+i]);
        }
    }
    for (int i{} ; i<m ; ++i){
        // reverse(arr+i*n,arr+i*n+n);
        int start{i*n};
        int end{i*n+n-1};
        while (start<end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    for (int i{} ; i<m*n ; ++i){
        if (i%3==0) cout << '\n';
        cout << arr[i] << ' ';
    }
    delete[] arr;
    return 0;
}
