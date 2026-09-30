#include <climits>
#include<iostream>
#include<vector>
using namespace std;

int bs_ub(const vector<int>& arr, int low, int high, int target){
    int ans{high+1};
    while(low<=high){
        int mid{(low+high)/2};
        if (arr[mid]>target){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}

int black_box(const vector<vector<int>>& arr, int target, int m, int n){
    int cnt{};
    for(int i{} ; i<m ; ++i)
        cnt += bs_ub(arr[i],0,n-1,target);
    return cnt;
}

int bs(const vector<vector<int>>& arr){
    int m{static_cast<int>(arr.size())};
    int n{static_cast<int>(arr[0].size())};
    int required {(m*n)/2};
    int low{INT_MAX}, high{INT_MIN};
    for (int i{} ; i<m ; ++i){
        low=min(arr[i][0],low);
        high=max(arr[i][n-1],high);
    }
    while (low<=high){
        int mid{low+(high-low)/2};
        int no_of_el{black_box(arr,mid,m,n)};
        if (no_of_el<=required) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main(){
    vector<vector<int>> mat{ // row wise sorted matrix
        {1, 4, 7, 11, 15}, 
        {2, 5, 8, 12, 19}, 
        {3, 6, 9, 16, 22}, 
        {10, 13, 14, 17, 24}, 
        {18, 21, 23, 26, 30}
    };
    cout << bs(mat);
    return 0;
}