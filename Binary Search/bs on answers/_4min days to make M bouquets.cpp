#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool possible(const vector<int>& arr, int day, int M, int K){
    int cnt{};
    int no_of_booqes{};
    for (int i{} ; i<static_cast<int>(arr.size()) ; i++){
        if (arr[i]<=day) cnt++;
        else{
            no_of_booqes += (cnt/K);
            cnt=0;
        }
    }
    no_of_booqes += (cnt/K);
    if (no_of_booqes>=M) return true;
    return false;
}

int brute(const vector<int>& arr, int M, int K){
    int n{static_cast<int>(arr.size())};
    if (M*K>n) return -1;
    int MaxDay{};
    for (int i{} ; i<n ; i++) if (arr[i]>MaxDay) MaxDay=arr[i];
    if (M*K==n) return MaxDay;
    int MinDay{*min_element(arr.begin(),arr.end())};
    for (int i{MinDay} ; i<MaxDay ; i++){
        if (possible(arr,i,M,K)==true) return i;
    }
    return -1;
}

int optimal(const vector<int>& arr, int M, int K){
    int n{static_cast<int>(arr.size())};
    if (M*K>n) return -1;
    // int MaxDay{*max_element(arr.begin(),arr.end())};
    // int MinDay{*min_element(arr.begin(),arr.end())};
    int MaxDay{}, MinDay{};
    for (int i{} ; i<n ; i++){
        MaxDay=max(MaxDay,arr[i]);
        MinDay=min(MinDay,arr[i]);
    }

    if (M*K==n) return MaxDay;
    while (MinDay<=MaxDay){
        int day{MinDay+(MaxDay-MinDay)/2};
        if (possible(arr,day,M,K)==true) {
            MaxDay=day-1;
        } else {
            MinDay=day+1;
        }
    }
    return MinDay;
}

int main(){
    vector BloomDay{1,10,3,10,2};
    int m{3};
    int k{1};
    int minDay{brute(BloomDay,m,k)};
    cout << minDay;
    return 0;
}