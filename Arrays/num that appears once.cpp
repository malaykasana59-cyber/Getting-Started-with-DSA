#include <iostream>
#include <unordered_map>
using namespace std;

// o(n2), o(1)
// most brute method is that run a loop to select an element in the array
// run another loop to count the occurances of that element
// if occurance==1  return that element

// o(n), o(n)
int brute(int arr[], int n){
    unordered_map<int,int> mpp;
    for (int i{} ; i<n ; ++i){
        ++mpp[arr[i]];
    }
    for (auto it : mpp){
        if (it.second==1) return it.first;
    }
    return -1;
}

// For small, dense, non-negative ranges: array hashing is faster.
// For large, sparse, or negative ranges: unordered_map is better due to space efficiency.

// o(n), o(max element +1)
int better(int arr[], int n){
    int max{};
    for (int i{} ; i<n ; ++i){
        if (arr[i]>max) max=arr[i];
    }
    int* hash=new int[max+1]{};
    for (int i{} ; i<n ; ++i){
        ++hash[arr[i]];
    }
    for (int i{} ; i<=max+1 ; ++i){
        if (hash[i]==1) return i;
    }
    return -1;
}

// O(n), O(1)
int optimal(int arr[], int n){
    int Xor{};
    for (int i{} ; i<n ; ++i){
        Xor ^= arr[i];
    }
    return Xor;
}

int main() {
    int arr[]{1,2,3,2,1,4,4};
    // int num{brute(arr,size(arr))};
    // int num{better(arr,size(arr))};
    int num{optimal(arr,size(arr))};
    cout << num;
    return 0;
}
