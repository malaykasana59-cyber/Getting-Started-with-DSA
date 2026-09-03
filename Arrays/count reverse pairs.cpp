// Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j]
#include<iostream>
#include<vector>
using namespace std;

int brute(vector<int>& arr, int n){
    int cnt{};
    for (int i{} ; i<n ; ++i){
        for (int j{i+1} ; j<n ; ++j){
            if (arr[i]>2*arr[j]) cnt++;
        }
    }
    return cnt;
}

void merge(vector<int>& arr, int low , int mid, int high){
    vector<int> temp;
    int left{low}, right{mid+1};
    while(left<=mid && right<=high){
        if (arr[left]<arr[right]) temp.emplace_back(arr[left++]);
        else temp.emplace_back(arr[right++]);
    }
    while(left<=mid) temp.emplace_back(arr[left++]);
    while(right<=high) temp.emplace_back(arr[right++]);
    for (int i{} ; i<=high-low ; i++) arr[low+i]=temp[i];
    return;
}

int countpairs(vector<int>& arr, int low, int mid, int high){
    int cnt{};
    int right{mid+1};
    for (int i{low} ; i<=mid ; ++i){
        while (right<=high && arr[i]>2*arr[right]){
            right++;
        }
        cnt += right-(mid+1);
    }
    return cnt;
}

int divide(vector<int>& arr, int low, int high){
    int cnt{};
    if (low>=high) return cnt;
    int mid{(low+high)/2};
    cnt += divide(arr,low,mid);
    cnt += divide(arr, mid+1, high);
    cnt += countpairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int optimal(vector<int>& arr, int n){
    return divide(arr, 0, n-1);
}

int main(){
    vector<int> vec{1,3,2,3,1};
    // int cnt{brute(vec,vec.size())};
    int cnt{optimal(vec,vec.size())};

    cout<<cnt;
    return 0;
}