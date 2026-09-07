#include<iostream>
#include<vector>
using namespace std;

int bs_insert(vector<int>& arr, int target){
    int low{}, high{static_cast<int>(arr.size())-1};
    while(low<=high){
        int mid{(low+high)/2};
        if (target==arr[mid]) return mid;
        else if (target>arr[mid]) low=mid+1;
        else high=mid-1;
    }
    arr.insert(arr.begin()+low,target);
    return low;
}

int main(){
    vector vec{1,2,4,7};
    int target{6};
    int position{bs_insert(vec, target)};
    cout<< "searched element at "<<position;
    return 0;
}