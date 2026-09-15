#include<iostream>
#include<vector>
using namespace std;

int brute(const vector<int>& arr, int k){
    int n{static_cast<int>(arr.size())};
    for (int i{} ; i<n ; ++i){
        if (arr[i]<=k) k++;
        else break;
    }
    return k;
}

int optimal(const vector<int>& arr, int k){
    int n{static_cast<int>(arr.size())};
    int low{}, high{n-1};
    int miss_cnt{};
    while (low<=high){
        int mid{low+(high-low)/2};
        miss_cnt= arr[mid]-mid-1;
        if (miss_cnt<k) low=mid+1;
        else if (miss_cnt>=k) high=mid-1;
    }
    return low+k; // high+1+k
}

int main(){
    vector nums{2,3,4,7,11};
    int k{5};
    int missnum(brute(nums,k));
    missnum=optimal(nums,k);
    cout << missnum;
    return 0;
}