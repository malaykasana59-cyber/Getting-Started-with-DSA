#include<iostream>
#include<vector>
using namespace std;

// to complete in shortest time -- min(maximum efforts in each configuration)

int brute(const vector<int>& arr, int){
    int n{static_cast<int>(arr.size())};
    
}

int main(){
    vector boards{10,20,30,40};
    int no_of_painters{2};
    int min_max_effort{brute(boards,no_of_painters)};
    cout<< min_max_effort;
    return 0;
}