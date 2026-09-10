#include <cmath>
#include<iostream>
using namespace std;

int brute(int m, int n){
    for (int i{1} ; i<=m ; i++){
        // int temp{i};
        // for (int j{} ; j<n-1 ; j++){
        //     temp = temp*i;
        // }
        // if (temp==m) return i;
        if (pow(i,n)==m) return i;
    }
    return -1;
}

int optimal(int m, int n){
    if (m == 0) return 0;
    if (n <= 0) return -1;
    int low{1}, high{m};
    while(low<=high){
        int mid{low+(high-low)/2};
        int num{1};
        for (int i{} ; i<n ; i++){
            if (num>m/mid){
                num=m+1;
                break;
            }
            num *= mid;
        }
        if (num==m) return mid;
        else if (num<m) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    int num{27}, power{3};
    // int nthRoot{brute(num,power)};
    int nthRoot{optimal(num,power)};
    cout << nthRoot;
    return 0;
}