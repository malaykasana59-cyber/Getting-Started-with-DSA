#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int brute(vector<int> arr, int n){
    int maxlen{};
    for (int i{} ; i<n ; ++i){
        int sum{};
        int len{};
        for (int j{i} ; j<n ; ++j){
            sum+=arr[j];
            if (sum==0){
                len=j-i+1;
                if (len>maxlen) maxlen=len;
            }
        }
    }
    return maxlen;
}

int better(vector<int> arr, int n){
    unordered_map<int,int> presumMap;
    int presum{}, len{};
    for (int i{} ; i<n ; ++i){
        presum+=arr[i];
        if (presum==0) len=i+1;
        if (presumMap.find(presum)!=presumMap.end()){
            if (len<i-presumMap[presum]) len = i-presumMap[presum];
        }
        if (presumMap.find(presum) == presumMap.end()) presumMap[presum]=i;
    }
    return len;
}

int main(){
    vector<int> arr{9, -3, 3, -1, 6, -5};
    // int len{brute(arr, arr.size())};
    int len{better(arr, arr.size())};
    cout<<len;
    return 0;
}