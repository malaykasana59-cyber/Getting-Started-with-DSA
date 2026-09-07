#include<iostream>
#include<vector>
using namespace std;

// o(log.2 n) 

int bs_iterative(vector<int>& arr, int n, const int& target){
    int low{0}, high{n-1};
    while(low<=high){
        int mid{(low+high)/2};
        if (arr[mid]==target) return mid;
        else if(arr[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int bs_recursive(vector<int>& arr, int low, int high, int target){
    if (low>high) return -1;
    int mid{(low+high)/2};
    if (target==arr[mid]) return mid;
    else if (target<arr[mid]) return bs_recursive(arr, low, mid-1, target);
    else return bs_recursive(arr, mid+1, high, target);
}

// for overflow case 
//     we can take mid = low + (high-low)/2

int main(){
    vector<int> vec{3, 4, 6, 7, 9, 12, 16, 17};
    int target{6};
    // int index{bs_iterative(vec, vec.size(), target)};
    int index{bs_recursive(vec, 0, vec.size()-1, target)};
    cout<< index;
    return 0;
}