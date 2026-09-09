#include<iostream>
#include<vector>
using namespace std;

int brute(const vector<int>& arr){
    int low{}, high{static_cast<int>(arr.size())-1};
    if (arr.empty()) return -1;
    else if (high==0) return arr[high];
    else if (arr[low]!=arr[low+1]) return arr[low];
    else if (arr[high]!=arr[high-1]) return arr[high];
    else {
        low++;high--;
        while (low<=high){
            int mid{low+(high-low)/2};
            if (arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
            else if ((arr[mid]==arr[mid-1] && mid%2==1)||(arr[mid]==arr[mid+1] && mid%2==0)) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

int main(){
    vector vec{1,1,2,2,3,3,4,5,5,6,6};
    int el{brute(vec)};
    cout<< el;
    return 0;
}