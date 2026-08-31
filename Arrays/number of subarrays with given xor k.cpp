#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int brute(vector<int> arr, int n, int k){
    int res{};
    for (int i{} ; i<n ; ++i){
        int temp{};
        for (int j{i} ; j<n ; ++j){
            temp^=arr[j];
            if (temp==k) res++;
        }
    }
    return res;
}

int optimal(vector<int> arr, int n, int k){
    int res{};
    unordered_map<int,int> prexorMap;
    int prexor{};
    prexorMap[prexor]++;
    for (int i{} ; i<n ; ++i){
        prexor ^= arr[i];
        // if (prexor==k) res++;
        int remxor{prexor^k};
        res += prexorMap[remxor];
        prexorMap[prexor]++;
    }
    return res;
}

int main(){
    vector<int> arr{4, 2, 2, 6, 4};
    int Xor{6};
    // int num{brute(arr, arr.size(), Xor)};
    int num{optimal(arr, arr.size(), Xor)};
    cout<< num;
    return 0;
}