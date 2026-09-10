#include<iostream>
#include<vector>
using namespace std;

// element greater than both of its neighbors

void brute(const vector<int>& arr, int n){
    for (int i{} ; i<n ; i++){
        bool left{(i==0)||(arr[i]>=arr[i-1])};
        bool right{(i==n-1)||(arr[i]>=arr[i+1])};
        if (left && right){
            cout<<i;
            return;
        }
    }
    return;
}

int bs_peak(const vector<int>& arr, int n){
    int low{1}, high{n-2};
    if (arr[0]>arr[1]) return arr[0];
    if (arr[n-1]>arr[n-2]) return arr[n-1];
    while(low<=high){
        int mid{low+(high-low)/2};
        if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if (arr[mid]>arr[mid-1]) low=mid+1;
        else if (arr[mid]>arr[mid+1]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main(){
    vector vec{1,2,3,4,5,6,7,8,5,1};
    brute(vec, static_cast<int>(vec.size()));
    int el{bs_peak(vec, static_cast<int>(vec.size()))};
    cout << el;
    return 0;
}