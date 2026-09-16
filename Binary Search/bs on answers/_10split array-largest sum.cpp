#include <algorithm>
#include<iostream>
#include <numeric>
#include<vector>
using namespace std;

bool count_no_subarr(const vector<int>& arr, int given_subarray_sum, int k){
    int n{static_cast<int>(arr.size())};
    int cnt_subarrays{1}, subarray_sum{};

    for (int i{} ; i< n ; ++i){
        if (arr[i]+subarray_sum<=given_subarray_sum) subarray_sum+=arr[i];
        else {
            subarray_sum=arr[i];
            cnt_subarrays++;
            if (cnt_subarrays>k) return false;
        }
    }
    if (cnt_subarrays<=k) return true;
    return false;
}

int brute(const vector<int>& arr, int k){
    int n{static_cast<int>(arr.size())};
    int starting_subarray_sum{*max_element(arr.begin(),arr.end())};
    int maximum_subarray_sum{accumulate(arr.begin(),arr.end(),0)};

    for (int i{starting_subarray_sum} ; i<= maximum_subarray_sum ; ++i){
        if (count_no_subarr(arr,i,k)==true) return i;
    }
    return -1;
}

int optimal(const vector<int>& arr, int k){
    int n{static_cast<int>(arr.size())};
    int low{*max_element(arr.begin(),arr.end())};
    int high{accumulate(arr.begin(),arr.end(),0)};
    while (low<=high){
        int mid{low+(high-low)/2};
        if (count_no_subarr(arr,mid,k)==true) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    vector nums{7,2,5,10,8};
    int k{2};
    int min_max_subarraysums{brute(nums,k)};
    cout << min_max_subarraysums;
    min_max_subarraysums=optimal(nums,k);
    cout << '\n' << min_max_subarraysums;
    return 0;
}