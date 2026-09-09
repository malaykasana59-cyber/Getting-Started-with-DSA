#include<iostream>
#include<vector>
using namespace std;

bool bs(const vector<int>& arr, int x){
    int low{}, high{static_cast<int>(arr.size())-1};
    while(low<=high){
        int mid{low+(high-low)/2};
        if (arr[mid]==x) return 1;
        if (arr[low]==arr[mid] && arr[mid]==arr[high]) {low++;high--;}
        else if (arr[mid]<x){
            if (arr[low]<=arr[mid] && x>=arr[low]) high=mid-1;
            else low=mid+1;
        }
        else {
            if (arr[mid]<=arr[high] && x<=arr[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return 0;
}

int main(){
    vector vec{7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target{3};
    bool isPresent{bs(vec, target)};
    if (isPresent==true) cout<< "present";
    else cout << "not present";
    return 0;
}