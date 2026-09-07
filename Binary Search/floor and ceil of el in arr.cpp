#include<iostream>
#include <utility>
#include<vector>
using namespace std;

pair<int, int> findfloorceil(const vector<int>& arr, float target){
    int low{}, high{static_cast<int>(arr.size())-1};
    int floor{-1},ceil{-1};
    while(low<=high){
        int mid{(low+high)/2};
        if (target==arr[mid]){
            return {target,target};
        }
        else if (target<arr[mid]){
            high=mid-1;
            ceil=arr[mid];
        }
        else {
            low=mid+1;
            floor=arr[mid];
        }
    }
    return {floor,ceil};
}

int main(){
    vector vec{3, 4, 4, 7, 8, 10};
    float target{3.5};
    pair<int,int> floor{findfloorceil(vec, target)};
    cout<<"floor of "<<target<<" is "<<floor.first<<"\nceil is "<<floor.second;
    return 0;
}