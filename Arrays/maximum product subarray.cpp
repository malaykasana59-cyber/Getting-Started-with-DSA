#include <climits>
#include<iostream>
#include<vector>
using namespace std;

int brute(vector<int>& arr, int n){
    int product{INT_MIN};
    for (int i{} ; i<n ; i++){
        int prod{1};
        for (int j{i} ; j<n ; j++){
            prod*=arr[j];
            product=max(product,prod);
        }
    }
    return product;
}

int optimal_preferred(vector<int>& arr, int n){
    int product{INT_MIN};
    int prefix{1},suffix{1};
    for (int i{} ; i<n ; ++i){
        if (prefix==0) prefix=1;
        if (suffix==0) suffix=1;
        prefix*=arr[i];
        product=max(product,prefix);
        suffix*=arr[(n-1)-i];
        product=max(product,suffix);
    }
    return product;
}

int optimal(vector<int>& arr, int n){
    int res{arr[0]};
    int maxProduct{arr[0]};
    int minProduct{arr[0]};
    for (int i{1} ; i<n ; i++){
        int current{arr[i]};

        if (current<0) swap(maxProduct,minProduct);

        maxProduct = max(current,maxProduct*current);
        minProduct = min(current,minProduct*current);

        res = max(res,maxProduct);
    }
    return res;
}

int main(){
    vector<int> vec{1,2,-3,0,-4,-5};
    // int product{brute(vec, vec.size())};
    int product{optimal_preferred(vec, vec.size())};
    // int product{optimal(vec, vec.size())};
    cout<< product;
    return 0;
}