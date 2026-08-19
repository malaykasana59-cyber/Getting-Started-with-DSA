#include <iostream>
#include <unordered_map>
using namespace std;

// O(n3), O(1)
int brute1(int arr[], int n, int k){
    int len{};
    for (int start{} ; start<n ; ++start){
        for (int end{start} ; end<n ; ++end){
            int sum{};
            for (int h{start} ; h<=end ; ++h){
                sum += arr[h];
            }
            if (sum==k){
                if (end-start+1>len){
                    len=end-start+1;
                }
            }
        }
    }
    return len;
}

// o(n2), o(1)
int brute2(int arr[], int n, int k){
    int len{};
    for (int start{} ; start<n ; ++start){
        int sum{};
        for (int end{start} ; end<n ; ++end){
            sum += arr[end];
            if (sum==k){
                if (len<end-start+1) len=end-start+1;
            }
        }
    }
    return len;
}

// O(n), O(n)
// O(nlogn) if we use map instead of unordered_map
int better(int arr[], int n, int k){
    // Stores first index where a prefix sum appears.
    unordered_map<int,int> presumMap;
    int len{}, presum{};
    for (int i{} ; i<n ; ++i){
        // Prefix sum from index 0 to i.
        presum += arr[i];

        // If prefix itself is k, subarray (0..i) is valid.
        if (presum==k) len=i+1;

        // Need an older prefix = (current prefix - k).
        int rem{presum-k};
        if (presumMap.find(rem) != presumMap.end()){
            // Subarray length is current index - index of needed prefix.
            if (len < i-presumMap[rem]) len = i-presumMap[rem];
        }
        // Keep first occurrence only to maximize subarray length.
        if (presumMap.find(presum) == presumMap.end()) presumMap[presum]=i;
    }
    return len;
}

// the above methods work for both +ve and -ve numbers 
// but if we have only +ve numbers then we can use the below method which is more efficient than the above methods.

// O(n), O(1)
int optimal(int arr[], int n, int k){
    int i{}, j{}, len{}, sum{};
    while (j<n){
        while (i<=j && sum>k){
            sum -= arr[i];
            ++i;
        }
        sum += arr[j];
        if (sum==k){
            if (len<j-i+1) len= j-i+1;
        }
        ++j;
    }
    return len;
}

int main() {
    int arr[]{10, 5, 2, 7, 1, 9};
    int k{15};
    int len{brute1(arr, size(arr), k)};
    // int len{brute2(arr, size(arr), k)};
    // int len{better(arr, size(arr), k)};
    // int len{optimal(arr, size(arr), k)};
    cout << len;
    return 0;
}
