#include<iostream>
using namespace std;

int brute(int n){
    if (n>=1 && n<4) return 1;
    else if (n>=4 && n<9) return 2;
    else if (n<=9 && n<16) return 3;
    else if (n<=16 && n<25) return 4;
    // and so on
    else {
        int sqrt{1};
        for (int i{5} ; i*i<=n ; i++){
            if (i*i<=n) sqrt=i;
        }
        return sqrt;
    } 
}

int optimal(int n){
    if (n<2) return n;
    int low{1}, high{n/2};
    int sqrt{1};
    while (low<=high){
        int mid{low+(high-low)/2};
        if (mid*mid==n) return mid;
        else if (mid*mid<n) {
            sqrt=mid;
            low=mid+1;
        } else high=mid-1;
    }
    return sqrt;
}

int main(){
    int num{28};
    // int sqrt{brute(num)};
    int sqrt{optimal(num)};
    cout << sqrt;
    return 0;
}