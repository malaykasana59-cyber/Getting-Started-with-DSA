#include <algorithm>
#include<iostream>
#include <numeric>
#include<vector>
using namespace std;

// to complete in shortest time -- min(maximum efforts in each configuration)

bool cnt_painters(const vector<int>& arr, int given_sum_of_boards, int k){
    int n{static_cast<int>(arr.size())};
    int no_of_painters{1}, sum_of_boards{};
    for (int i{} ; i<n ; ++i){
        if (arr[i]+sum_of_boards<=given_sum_of_boards) sum_of_boards+=arr[i];
        else {
            sum_of_boards=arr[i];
            no_of_painters++;
            if (no_of_painters>k) return false;
        }
    }
    return no_of_painters<=k;
}

int brute(const vector<int>& arr, int k){
    int n{static_cast<int>(arr.size())};
    int min_board_size{*max_element(arr.begin(),arr.end())};
    int max_board_size{accumulate(arr.begin(),arr.end(),0)};

    for (int i{min_board_size} ; i<=max_board_size ; ++i){
        if (cnt_painters(arr,i,k)==true) return i;
    }
    return -1;
}

int optimal(const vector<int>& arr, int k){
    int low{*max_element(arr.begin(),arr.end())};
    int high{accumulate(arr.begin(),arr.end(),0)};
    while (low<=high){
        int mid{low+(high-low)/2};
        if (cnt_painters(arr,mid,k)==true) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    vector boards{10,20,30,40};
    int no_of_painters{2};
    int min_max_effort{brute(boards,no_of_painters)};
    cout<< min_max_effort<<'\n';
    min_max_effort=optimal(boards,no_of_painters);
    cout << min_max_effort;
    return 0;
}