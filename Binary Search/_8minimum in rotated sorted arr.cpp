#include<iostream>
#include<vector>
using namespace std;

int bs_diff(const vector<int>& arr){
    int low{}, high{static_cast<int>(arr.size())-1};
    int minimum=2147483647; //INT_MAX
    while (low<=high){
        if (low==high) return arr[low];
        int mid{low+(high-low)/2};
        if (arr[mid]<=arr[high]) high=mid;
        else low=mid+1;
    }
    return -1;
}

int bs_min(const vector<int>& arr){
    int low{}, high{static_cast<int>(arr.size())-1};
    int minimum=2147483647; //INT_MAX
    while (low<=high){
        int mid{low+(high-low)/2};
        minimum=min(minimum,arr[mid]);
        if (arr[low]<arr[mid]) {
            minimum=min(minimum,arr[low]);
            low=mid+1;
        } else if (arr[low]>arr[mid]) {
            high=mid-1;
        } else {
            // this is to check for duplicates if stated in problem
            minimum=min(minimum,arr[high]);
            low++;high--;
        }
    }
    return minimum;
}

int main(){
    // vector vec{2,1};
    vector vec{4,5,6,7,0,1,2,3};
    // int minimum{bs_min(vec)};
    int minimum{bs_diff(vec)};
    cout<< minimum;
    return 0;
}