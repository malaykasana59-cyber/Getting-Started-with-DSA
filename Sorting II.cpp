#include <iostream>
#include <vector>
using namespace std;

// Merge Sort.
// TC -> O(n log n)
// SC -> O(n)
void merge(std::vector<int> &arr, int low, int mid, int high){
    std::vector<int> temp;
    int left{low};
    int right{mid+1};
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.emplace_back(arr[left]);
            ++left;
        }
        else{
            temp.emplace_back(arr[right]);
            ++right;
        }
    }
    while (left<=mid){
        temp.emplace_back(arr[left]);
        ++left;
    }
    while (right<=high){
        temp.emplace_back(arr[right]);
        ++right;
    }
    for (int i{0} ; i<temp.size() ; ++i){
        arr[low+i]=temp[i];
    }
    return;
}

void divide(std::vector<int> &arr , int low , int high){
    if (low>=high) return;
    int mid{(low+high)/2};
    divide(arr,low,mid);
    divide(arr,mid+1,high);
    merge(arr,low,mid,high);
    return;
}

// Quick Sort.
// TC -> O(n log n) on average , O(n^2) in worst case
// SC -> O(log n)

int partition(vector<int> &arr, int low, int high){
    int pivot{arr[low]};
    int i{low};
    int j{high};
    while(i<j){
        while (arr[i] <= pivot && i<=high-1) ++i;
        while (arr[j] > pivot && j>=low+1) --j;
        if (i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qS(vector<int> &arr, int low, int high){
    if(low<high){
        int pindex{partition(arr, low, high)};
        qS(arr, low, pindex-1);
        qS(arr, pindex+1, high);
        return;
    }
}

// Recursive Bubble Sort
// TC -> O(n^2)
// SC -> O(n)
void r_bs(vector<int> &arr, int n){
    if (n==0) return;
    int didswap{0};
    for (int i{0};i<n;++i){
        if (arr[i]>arr[i+1]){ 
            swap(arr[i],arr[i+1]);
            didswap=1;
        }
    }
    if (didswap==0) return;
    r_bs(arr,n-1);
    return;
}

// Recursive Insertion Sort
// TC -> O(n^2)
// SC -> O(n)
void r_is(vector<int> &arr, int n, int i){
    int j{i};
    while(j>0 && arr[j]<arr[j-1]){
        swap(arr[j],arr[j-1]);
        --j;
    }
    if (i==n-1) return;
    r_is(arr,n,i+1);
    return;
}

int main(){
    std::cout<<"This is starting.\n";
    std::vector<int> arr{1,10,20,50,1,10,9,100,200};
    int low{0};
    int high{static_cast<int>(arr.size()-1)};
    // divide(arr,low,high);
    // qS(arr,low,high);
    // r_bs(arr,high-1);
    // r_is(arr,high-1,1);
    for (int i{low} ; i<=high ; ++i){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<"\nThis is end.";
    return 0;
}
