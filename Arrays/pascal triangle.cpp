#include <iostream>
using namespace std;

// given r and c, tell the element at that place
// FORMULA --> (r-1) C (c-1)
// o(r) o(1)

void printelement(int r, int c){
    int el{1};
    if (c-1<=r-c){
        for (int i{1} ; i<c ; ++i){
            el=(el*(r-i))/i;
        }
    } else {
        for (int i{1} ; i<=(r-c) ; ++i){
            el=(el*(r-i))/i;
        }
    }
    cout << el << '\n';
}

// print the nth row of pascal triangle
// o(n) o(n)

int* pascalrow(int n){
    int* arr= new int[n]{};
    int el{1};
    arr[0]=el;
    for (int i{1} ; i<n ; ++i){
        el=(el*(n-i))/i;
        arr[i]=el;
    }
    return arr;
}
// computes only half of the row and mirrors values. o(n/2) o(n)
int* pascalrow_optimized(int n){
    int* arr= new int[n]{};
    arr[0]=1;
    arr[n-1]=1;
    long long el{1};
    int half{(n-1)/2};
    for (int i{1} ; i<=half ; ++i){
        el=(el*(n-i))/i;
        arr[i]=el;
        arr[n-1-i]=arr[i];
    }
    return arr;
}

// print the entire pascal triangle upto n rows
// o(n^2) o(n^2)

void pascaltriangle(int n){
    int** arr= new int*[n]{};
    for (int i{} ; i<n ; ++i){
        arr[i]=new int[i+1]{};
        arr[i][0]=1;
        arr[i][i]=1;
        for (int j{1} ; j<i ; ++j){
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    // Print the triangle
    for (int i{} ; i<n ; ++i){
        for (int j{} ; j<=i ; ++j){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    // Deallocate memory
    for (int i{} ; i<n ; ++i){
        delete[] arr[i];
    }
    delete[] arr;
}

void pascaltriangle1(int n){
    int** arr= new int*[n]{};
    for (int i{} ; i<n ; ++i){
        arr[i]=pascalrow_optimized(i+1);
    }
    // Print the triangle
    for (int i{} ; i<n ; ++i){
        for (int j{} ; j<=i ; ++j){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    // Deallocate memory
    for (int i{} ; i<n ; ++i){
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int n{6};
    printelement(5,3);
    cout << '\n';
    int *row{pascalrow(5)};
    for (int i{} ; i<5 ; ++i) cout << row[i] << ' ';
    cout << '\n';
    pascaltriangle1(n);
    return 0;
}

