#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool CanWePlace(const vector<int>& arr, int dist, int k){
    int n{static_cast<int>(arr.size())};
    int cnt_cows{1}, last_cow_at{arr[0]};
    for (int i{1} ; i<=n-1 ; i++){
        if (arr[i]-last_cow_at >= dist) {
            cnt_cows++;
            last_cow_at=arr[i];
        }
        if (cnt_cows==k) return true;
    }
    return false;
}

int brute(vector<int>& arr, int k){
    sort(arr.begin(),arr.end());
    int n{static_cast<int>(arr.size())};
    int Max{arr[n-1]}, Min{arr[0]};
    for (int i{1} ; i<=Max-Min ; ++i){
        if (CanWePlace(arr,i,k)==false) return i-1;
    }
    return -1;
}

int optimal(vector<int>& arr, int k){
    sort(arr.begin(),arr.end());
    int n{static_cast<int>(arr.size())};
    int Max{arr[n-1]}, Min{arr[0]};
    int low{1}, high{Max-Min};
    while (low<=high){
        int mid{low+(high-low)/2};
    int ans{-1};
        if (CanWePlace(arr,mid,k)==true){
            low=mid+1;
        } else high=mid-1;
    }
    return high;
}

int main(){
    vector position_of_stalls{0,3,4,7,10,9};
    int no_of_cows{4};
    int max_min_distance{brute(position_of_stalls,no_of_cows)};
    max_min_distance = optimal(position_of_stalls,no_of_cows);
    cout << max_min_distance;
    return 0;
}