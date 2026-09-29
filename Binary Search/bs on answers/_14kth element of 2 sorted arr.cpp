#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// merge sort concept
/*
void merge(vector<int>& t1, vector<int>& t2, int s1, int s2){
    vector<int> temp;
    int left{}, right{};
    while(left<s1 && right<s2){
        if (t1[left]<=t2[right]) temp.emplace_back(t1[left++]);
        else temp.emplace_back(t2[right++]);
    }
    while(left<s1) temp.emplace_back(t1[left++]);
    while(right<s2) temp.emplace_back(t2[right++]);
    for (int i{} ; i<s1 ; ++i) t1[i]=temp[i];
    for (int i{s1} ; i<s1+s2 ; ++i) t2[i-s1]=temp[i];
    return;
}
*/

// shell sort (gap algorithm)
void merge(vector<int>& t1, vector<int>& t2, int s1, int s2){
    int gap{(s1+s2+1)/2};
    while(gap>0){
        int index{};
        while(index<s1+s2-gap){
            int left{index}, right{index+gap};
            if (left<s1){
                if (right<s1){
                    if (t1[left]>t2[right]) swap(t1[left],t2[right]);
                } else {
                    if (t1[left]>t2[right-s1]) swap(t1[left],t2[right-s1]);
                }
            } else {
                left = left-s1;
                right = right-s1;
                if (t2[left]>t2[right]) swap(t2[left],t2[right]);
            }
            index++;
        }
        if (gap==1) return;
        gap=(gap+1)/2;
    }
}

int brute(vector<int>& t1, vector<int>& t2, int k){
    int n1{static_cast<int>(t1.size())};
    int n2{static_cast<int>(t2.size())};
    merge(t1,t2,n1,n2);
    if (k-1<n1) return t1[k-1];
    else return t2[k-1-n1];
}

int better(const vector<int>& arr1, const vector<int>& arr2, int k){
    int n1{static_cast<int>(arr1.size())}, n2{static_cast<int>(arr2.size())};
    int index{}, left{}, right{};
    while(left<n1 && right<n2){
        if (arr1[left]<=arr2[right]){
            index++;
            if (index==k) return arr1[left];
            left++;
        } else {
            index++;
            if (index==k) return arr2[right];
        }
    }
    while (left<n1){
        index++;
        if (index==k) return arr1[left];
        left++;
    }
    while (right<n2){
        index++;
        if (index==k) return arr2[right];
        right++;
    }
    return -1;
}

int optimal(const vector<int>& arr1, const vector<int>& arr2, int k){
    int m{static_cast<int>(arr1.size())}, n{static_cast<int>(arr2.size())};
    if (m>n) return optimal(arr2,arr1,k);

    int low{max(0,k-n)}, high{min(k,m)};
    int lefthalf{k};
    while (low<=high) {
        int mid1 {low+(high-low)/2};
        int mid2 {lefthalf-mid1};
        int l1=(mid1>0) ? arr1[mid1-1] : INT_MIN;
        int r1=(mid1<m) ? arr1[mid1] : INT_MAX;
        int l2=(mid2>0) ? arr2[mid2-1] : INT_MIN;
        int r2=(mid2<n) ? arr2[mid2] : INT_MAX;

        if (l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if (l1>r2) high=mid1-1;
        else low=mid1+1;
    }
    return -1;
}

int main(){
    vector arr1{2, 3, 6, 7, 9};
    vector arr2{1, 4, 8, 10};
    int k{5};
    // brute(arr1, arr2, k);
    cout << brute(arr1,arr2,k)<<'\n';
    cout << better(arr1,arr2,k)<<'\n';
}