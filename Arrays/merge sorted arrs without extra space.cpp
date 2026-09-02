#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// this function takes extra space of o(n1+n2)
vector<int>  merge(vector<int>& arr1, vector<int>& arr2){
    int n1{static_cast<int>(arr1.size())};
    int n2{static_cast<int>(arr2.size())};
    vector<int> merged_arr{};
    int left{},right{};
    while (left<n1 && right<n2){
        if (arr1[left]<=arr2[right]){
            merged_arr.emplace_back(arr1[left++]);
        } else {
            merged_arr.emplace_back(arr2[right++]);
        }
    }
    while (left<n1){
        merged_arr.emplace_back(arr1[left++]);
    }
    while (right<n2){
        merged_arr.emplace_back(arr2[right++]);
    }
    return merged_arr;
}

// o(min(n1,n2))+o(n1 log n1)+o(n2 log n2), o(1)
void merge_no_space_brute(vector<int>& arr1, vector<int>& arr2){
    int n1{static_cast<int>(arr1.size())};
    int n2{static_cast<int>(arr2.size())};
    int i{n1-1},j{0};
    while (i>=0 && j<n2){
        if (arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        } else {
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

// o(n1+n2 log n1+n2), o(1)
void self_optimal(vector<int>& arr1, vector<int>& arr2){
    int n1{static_cast<int>(arr1.size())};
    int n2{static_cast<int>(arr2.size())};
    int gap{(n1+n2+1)/2};
    while (gap>0){
        int index{};
        while (index<n1+n2-gap){
            int left{index};
            int right{index+gap};
            if (left<n1){
                if (right<n1){
                    if (arr1[left]>arr1[right]){
                        swap(arr1[left],arr1[right]);
                    }
                } else {
                    right=right-n1;
                    if (arr1[left]>arr2[right]){
                        swap(arr1[left],arr2[right]);
                    }
                }
            } else {
                left=left-n1;
                right=right-n1;
                if (arr2[left]>arr2[right]){
                    swap(arr2[left],arr2[right]);
                }
            }
            index++;
        }
        if (gap==1) break;
        gap=(gap+1)/2;
    }
    return;
}

// this works only if arr1 has extra enough capacity than its size
// o(n1+n2), o(1)
void merge_no_space_optimal(vector<int>& arr1, vector<int>& arr2){
    int n1{static_cast<int>(arr1.size())};
    int n2{static_cast<int>(arr2.size())};

    return;
}

int main(){
    vector<int> nums1{-5, -2, 0, 0, 0, 4, 5};
    vector<int> nums2{-3, 1, 8};
    // vector<int> merged_arr{merge(nums1,nums2)};
    // for (auto it : merged_arr){
    //     cout<<it<<' ';
    // }

    // merge_no_space_brute(nums1, nums2);
    // merge_no_space_optimal(nums1, nums2);
    self_optimal(nums1, nums2);
    for (auto it : nums1){
        cout << it << ' ';
    }
    for (auto it : nums2){
        cout << it << ' ';
    }
    return 0;
}