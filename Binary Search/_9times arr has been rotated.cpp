#include<iostream>
#include<vector>
using namespace std;

// find index of minimum value
// this can also be found by finding minimum value and returning its index 

int optimal(const vector<int>& arr){
    int low{}, high{static_cast<int>(arr.size())-1};
    while (low<=high){
        if (low==high) return low;
        int mid{low+(high-low)/2};
        if (arr[mid]<=arr[high]) high=mid;
        else low=mid+1;
    }
    return 0;
}

int main(){
    vector vec{3,4,5,1,2};
    // vector vec{4,5,6,7,0,1,2,3};
    int times{optimal(vec)};
    cout << times;
    return 0;
}