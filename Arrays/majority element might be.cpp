#include <iostream>
using namespace std;

int brute(int arr[], int n){
    for (int i{} ; i<n ; ++i){
        int cnt{};
        for (int j{} ; j<n ; ++j){
            if (arr[j]==arr[i]) ++cnt;
        }
        if (cnt>n/2) return arr[i];
    }
    return -1;
}

int better(int arr[], int n){
    int max_el{};
    for (int i{} ; i<n ; ++i){
        if (arr[i]>max_el) max_el=arr[i];
    }
    int* hash = new int [max_el+1]{};
    for (int i{} ; i<n ; ++i){
        ++hash[arr[i]];
    }
    for (int i{} ; i<max_el+1 ; ++i){
        if (hash[i]>n/2) return i;
    }
    return -1;
}

// Moore's voting algo
int optimal(int arr[], int n){
    int cnt{};
    int el{};
    for (int i{} ; i<n ; ++i){
        if (cnt==0){
            el=arr[i];
            cnt=1;
        }
        else if (arr[i]==el){
            ++cnt;
        }
        else --cnt;
    }
    cnt=0;
    for (int i{} ; i<n ; ++i){
        if (arr[i]==el) ++cnt;
    }
    if (cnt>n/2) return el;
    return -1;
}

int main() {
    int arr[]{1,1,2,1,4,3,1,5,1,6,1};
    // int el{brute(arr, size(arr))};
    // int el{better(arr, size(arr))};
    int el{optimal(arr, size(arr))};
    cout << el;
    return 0;
}
