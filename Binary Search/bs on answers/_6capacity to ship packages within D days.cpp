#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int brute(const vector<int>& arr, int d){
    int n{static_cast<int>(arr.size())};
    int least = *max_element(arr.begin(),arr.end());
    int total{};
    for (int i{} ; i<n ; ++i) total += arr[i];
    for (int i{least} ; i<=total ; i++){
        int days{1};
        int maxload{i},load{};
        for (int j{} ; j<n ; j++){
            if (load+arr[j]>maxload){
                days++;
                if (days>d) break;
                load=arr[j];
            } else load+=arr[j];
        }
        if (days<=d) return i;
    }
    return -1;
}

int Ship_Within_Days(const vector<int>& arr, int d){
    int n{static_cast<int>(arr.size())};
    int least_load = *max_element(arr.begin(),arr.end());
    int max_load{};
    for (int i{} ; i<n ; ++i){
        max_load += arr[i];
    }
    while (least_load<=max_load){
        int load{least_load+(max_load-least_load)/2}; //mid
        int currentload{};
        int days{1};
        for (int i{} ; i<n ; ++i){
            if (currentload+arr[i]>load){
                days++;
                if (days>d) break;
                currentload=arr[i];
            } else currentload+=arr[i];
        }
        if (days<=d) max_load = load-1;
        else least_load = load+1;
    }
    return least_load;
}

int main(){
    vector weights{1,2,3,4,5,6,7,8,9,10};
    int Days{5};
    int leastDays{brute(weights,Days)};
    leastDays = Ship_Within_Days(weights,Days);
    cout << leastDays;
    return 0;
}