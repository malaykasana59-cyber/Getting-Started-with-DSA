#include <iostream>
using namespace std;

// in n/3 times in an array of size n, there can be at most 2 such elements.
// So we can use a hash table to count the frequency of each element and return those whose frequency is greater than n/3.
// The time complexity of this approach is O(n) and the space complexity is O(max(arr)).

int* brute(int arr[], int n){
    int size{0};
    int *res = new int[2]{-1, -1};
    for (int i{} ; i<n ; ++i){
        int cnt{};
        for (int j{} ; j<n ; ++j){
            if (arr[j]==arr[i]) ++cnt;
        }
        if (cnt > n/3 && arr[i] != res[0] && arr[i] != res[1]){
            res[size++] = arr[i];
            if (size == 2) break;
        }
    }
    return res;
}

int* better(int arr[], int n){
    int size{};
    int* res = new int[2]{-1, -1};
    int max{};
    for (int i{} ; i<n ; ++i){
        if (arr[i] > max) max = arr[i];
    }
    int* hash = new int [max+1]{};
    for (int i{} ; i<n ; ++i){
        ++hash[arr[i]];
    }
    for (int i{} ; i<=max ; ++i){
        if (hash[i] > n/3 && i != res[0] && i != res[1]){
            res[size++] = i;
            if (size == 2) break;
        }
    }
    delete[] hash;
    return res;
}

int* optimal(int arr[], int n){
    int size{};
    int* res = new int[2]{-1, -1};
    int cnt1{}, cnt2{};
    int el1{}, el2{};
    for (int i{} ; i<n ; ++i){
       if (cnt1==0 && arr[i] != el2){
        cnt1=1;
        el1=arr[i];
       }
       else if (cnt2==0 && arr[i] != el1){
        cnt2=1;
        el2=arr[i];
       }
       else if (el1==arr[i]) cnt1++;
       else if (el2==arr[i]) cnt2++;
       else --cnt1, --cnt2;
    }
    cnt1 = 0, cnt2 = 0;
    for (int i{} ; i<n ; ++i){
        if (el1 == arr[i]) ++cnt1;
        if (el2 == arr[i]) ++cnt2;
    }
    if (cnt1 > n/3) res[size++]=el1;
    if (cnt2 > n/3) res[size++]=el2;
    return res;
}

int main() {
    int arr[]{1,1,2,1,4,3,1,5,1,6,1};
    // int* res{brute(arr, size(arr))};
    // int* res{better(arr, size(arr))};
    int* res{optimal(arr, size(arr))};
    if (res[0] != -1) cout << res[0] << " ";
    if (res[1] != -1) cout << res[1];
    return 0;
}
