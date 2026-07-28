#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// o(n2), o(1)
pair<int,int> brute(int arr[], int n, int k){
    for (int i{} ; i<n ; ++i){
        for (int j{i+1} ; j<n ; ++j){
            if (i==j) continue;
            if (arr[i]+arr[j]==k) return make_pair(i,j);
        }
    }
    return make_pair(-1,-1);
}

/*
pair<int,int> better(int arr[], int n, int k){
    int max{};
    for (int i{} ; i<n ; ++i){
        if (max<arr[i]) max= arr[i];
    }
    int hash[max+1]{};
    for (int i{} ; i<n ; ++i){
        int complement = k - arr[i];
        if (complement >= 0 && complement <= max && hash[complement] != 0){
            return make_pair(hash[complement]-1, i);
        }
        hash[arr[i]] = i + 1;  // Store index+1 to distinguish from 0
    }
    return make_pair(-1,-1);
}
*/

pair<int,int> better(int arr[], int n, int k){
    unordered_map<int,int> mp;
    for (int i{} ; i<n ; ++i){
        if (mp.find(k-arr[i]) != mp.end()){
            return make_pair(mp[k-arr[i]],i);
        }
        mp[arr[i]]=i;
    }
    return make_pair(-1,-1);
}

pair<int,int> optimal(int arr[], int n, int k){
    int i{}, j{n-1}, sum{};
    pair<int,int>* sortarr = new pair<int,int>[n];
    // pair<int,int> sortarr[n]{};
    for (int it{} ; it<n ; ++it){
        sortarr[it]={arr[it],it};
    }
    sort(sortarr,sortarr+n);
    while (i<j){
        sum=sortarr[i].first+sortarr[j].first;
        if (sum<k) ++i;
        if (sum>k) --j;
        if (sum==k) return {sortarr[i].second,sortarr[j].second};
    }
    return {-1,-1};
}

int main() {
    int arr[]{2,6,5,8,11};
    // pair<int,int> result=brute(arr, size(arr), 14);
    // pair<int,int> result{better(arr, size(arr), 14)};
    pair<int,int> result{optimal(arr, size(arr), 14)};
    cout << result.first << ',' << result.second;
    return 0;
}
