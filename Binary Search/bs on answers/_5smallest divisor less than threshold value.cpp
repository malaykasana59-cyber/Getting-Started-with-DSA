#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int quo(const vector<int>& arr, int limit, int num){
    int sum{};
    for (int i{} ; i<static_cast<int>(arr.size()) ; i++){
        sum += (arr[i]+num-1)/num;
        if (sum>limit) break;
    }
    return sum;
}

int brute(const vector<int>& arr, int limit){
    int n{static_cast<int>(arr.size())};

    int total{};
    for (int i{} ; i<n ; i++) total+=arr[i];
    int least{(total+limit-1)/limit};
    if (least<1) least=1;

    for (int i{least} ; i<=*max_element(arr.begin(),arr.end()) ; i++){
        int sumofquo{quo(arr,limit,i)};
        if (sumofquo<=limit) return i;
    }
    
    return -1;
}

int optimal(const vector<int>& arr, int limit){
    int n{static_cast<int>(arr.size())};
    int high{};
    int total{};
    for (int i{} ; i<n ; ++i){
        total += arr[i];
        high=max(high,arr[i]);
    }

    int low{(total+limit-1)/limit};
    if (low<1) low=1;

    while (low<=high){
        int mid{low+(high-low)/2};
        int sumofquo{quo(arr,limit,mid)};
        if (sumofquo<=limit) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    vector nums{1,2,5,9};
    int threshold{6};
    int div{brute(nums,threshold)};
    div = optimal(nums,threshold);
    cout << div;
    return 0;
}