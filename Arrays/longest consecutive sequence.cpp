#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

bool ls(int arr[], int n, int el){
    for (int i{} ; i<n ; ++i){
        if (el==arr[i]) return true;
    }
    return false;
}

void brute(int arr[], int n){
    int longest{1};
    for (int i{} ; i<n ; ++i){
        int el{arr[i]}, cnt{1};
        while (ls(arr,n,el+1)==true){
            ++el;
            ++cnt;
        }
        if (cnt>longest) longest = cnt;
    }
    cout << longest;
}

void better(int arr[], int n){
    sort(arr,arr+n);
    int longest{1}, cnt{}, last_smaller{INT_MIN};
    for (int i{} ; i<n ; ++i){
        if (arr[i] - 1 == last_smaller){
            ++cnt;
            last_smaller = arr[i];
        }
        else if (arr[i] != last_smaller){
            cnt = 1;
            last_smaller = arr[i];
        }
        if (longest < cnt) longest = cnt;
    }
    cout << longest;
}

void optimal(int arr[], int n){
    int longest{1};
    unordered_set<int> st{arr[0]};
    for (int i{1} ; i<n ; ++i) st.insert(arr[i]);
    for (int it : st){
        if (st.find(it-1) == st.end()){
            int cnt{1}, x{it};
            while (st.find(x+1) != st.end()){
                ++cnt;
                ++x;
            }
            if (longest<cnt) longest = cnt;
        } 
    }
    cout << longest;
}

int main() {
    int arr[]{102,4,100,1,101,3,2,1,1};
    brute(arr, size(arr));
    better(arr, size(arr));
    optimal(arr, size(arr));
    return 0;
}
