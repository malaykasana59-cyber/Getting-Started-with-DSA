#include<iostream>
#include<vector>
using namespace std;

int brute(vector<int>& arr, int n){
    int cnt{};
    for (int i{} ; i<n ; ++i){
        for (int j{i+1} ; j<n ; ++j){
            if (arr[i]>arr[j]) cnt++;
        }
    }
    return cnt;
}

int merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int cnt{};
    int left{low}, right{mid+1};
    while (left<=mid && right<=high){
        if (arr[left]<=arr[right]) temp.emplace_back(arr[left++]);
        else {
            temp.emplace_back(arr[right++]);
            cnt += (mid-left+1);
        }
    }
    while (left<=mid) temp.emplace_back(arr[left++]);
    while (right<=high) temp.emplace_back(arr[right++]);
    for (int i{} ; i<=high-low ; ++i){
        arr[low+i]=temp[i];
    }
    return cnt;
}

int divide(vector<int>& arr, int low, int high){
    int cnt{};
    if (low>=high) return cnt;
    int mid{(low+high)/2};
    cnt += divide(arr,low,mid);
    cnt += divide(arr,mid+1,high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

int main(){
    vector<int> vec{5,3,2,4,1};
    // int cnt{brute(vec,vec.size())};
    int cnt{divide(vec,0,vec.size()-1)};
    cout<< cnt;
    return 0;
}