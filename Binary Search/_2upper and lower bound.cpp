#include<iostream>
#include<vector>
using namespace std;

int bs_lb(vector<int>& arr, const int& n, const int& target){
    int low{0}, high{n-1};
    int ans{n};
    while(low<=high){
        int mid{(low+high)/2};
        if (arr[mid]>=target){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}
// lb= lower_bound (arr,arr+n,target)-arr
// lb= (vec.begin(),vec.end(),target)-vec.begin()

int bs_ub(vector<int>& arr, const int& n, const int& target){
    int low{}, high{n-1};
    int ans{n};
    while(low<=high){
        int mid{(low+high)/2};
        if (arr[mid]>target){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}

int main(){
    vector<int> vec{1,2,3,3,7,8,9,9,9,11};
    int target{7};
    int lowerbound{bs_lb(vec, vec.size(), target)};
    int upperbound{bs_ub(vec, vec.size(), target)};
    cout<< "lower bound of "<<target<<" is : "<< lowerbound;
    cout<< "\n upper bound of "<<target<<" is : "<<upperbound;
    return 0;
}