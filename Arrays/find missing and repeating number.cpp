#include<iostream>
#include<vector>
// #include<algorithm>
using namespace std;

vector<int> brute(vector<int>& arr, int n){
    vector<int> res(2,0);
    for (int i{1} ; i<=n ; ++i){
        int cnt{};
        for (int j{} ; j<n ; ++j){
            if (arr[j]==i){
                cnt++;
                if (cnt==2) res[0]=arr[j];
            }
        }
        if (cnt==0) res[1]=i;
    }
    return res;
}

vector<int> better(vector<int>& arr, int n){
    vector<int> res(2,0);
    int* hash = new int[n+1]{};
    // hash[0]=1;
    int cnt{};
    for (int i{} ; i<n ; ++i){
        hash[arr[i]]++;
    }
    for (int i{1} ; i<=n ; ++i){
        if (hash[i]==0) res[1]=i;
        if (hash[i]==2) res[0]=i;
    }
    delete[] hash;
    return res;
}

vector<int> optimal_1(vector<int>& arr, int n){
    int actualsum{(n*(n+1))/2},actualsquaresum{(n*(n+1)*(2*n+1))/6};
    int calculatedsum{},calculatedsquaresum{};
    int y{},x{}; // x-repeating num , y-missing num
    for (int i{} ; i<n ; ++i){
        calculatedsum+=arr[i];
        calculatedsquaresum+=arr[i]*arr[i];
    }
    int y_minus_x = actualsum-calculatedsum;
    int y2_minus_x2 = actualsquaresum-calculatedsquaresum;
    int y_plus_x = y2_minus_x2 / y_minus_x;
    y = (y_plus_x + y_minus_x)/2;
    x = y - y_minus_x;
    return {x,y};
}

vector<int> optimal_2(vector<int>& arr, int n){
    int Xor{};
    for (int i{} ; i<n ; ++i){
        Xor = Xor^arr[i]^(i+1);
    }
    int bitno{};
    while (true){
        if ((Xor & (1<<bitno))!= 0){
            break;
        }
        bitno++;
    }
    int zero{},one{};
    for (int i{} ; i<n ; ++i){
        if ((arr[i] & (1<<bitno))!= 0) one=one^arr[i];
        else zero=zero^arr[i];
    }
    for (int i{1} ; i<=n ; ++i){
        if ((i & (1<<bitno))!= 0) one ^= i;
        else zero ^= i;
    }
    int cnt{};
    for (int i{} ; i<n ; ++i){
        if (arr[i]==zero) cnt++;
    }
    if (cnt==2) return {zero,one};
    return {one,zero};
}

int main(){
    vector<int> vec{3, 5, 4, 1, 1};

    // vector<int> res{brute(vec,vec.size())};
    // vector<int> res{better(vec,vec.size())};
    vector<int> res{optimal_1(vec,vec.size())};
    // vector<int> res{optimal_2(vec,vec.size())};

    cout << "Repeating number: "<<res[0]<<"\nMissing number: "<<res[1];
    return 0;
}