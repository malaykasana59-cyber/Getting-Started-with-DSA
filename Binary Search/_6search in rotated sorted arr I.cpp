#include<iostream>
#include<vector>
using namespace std;

int bs_striver(const vector<int>& arr, int x){
    int low{}, high{static_cast<int>(arr.size())-1};
    while(low<=high){
        int mid{low+(high-low)/2};
        if (x==arr[mid]) return mid;
        else if (x<arr[mid]){
            if (arr[low]<=arr[mid] && x>=arr[low]) high=mid-1;
            else low=mid+1;
        } else {
            if (arr[mid]<=arr[high] && x<=arr[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

int bs(const vector<int>& arr, int x){
    int low{}, high{static_cast<int>(arr.size())-1};
    while (low<=high){
        int mid{low+(high-low)/2};
        if (x==arr[mid]) return mid;
        else if (x<arr[mid]){
            if (mid-1>=low && x<=arr[mid-1] && x>=arr[low]) high=mid-1;
            else low=mid+1;
        }
        else {
            if (mid+1<=high && x<=arr[high] && x>=arr[mid+1]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

int main(){
    vector vec{4, 5, 6, 7, 0, 1, 2};
    int target{0};
    int index{bs(vec, target)};
    cout<< index;
    return 0;
}