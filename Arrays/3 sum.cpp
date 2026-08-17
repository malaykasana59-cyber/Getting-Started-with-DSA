#include <cstddef>
#include<iostream>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> brute(vector<int> &vec, size_t &n){
    vector<vector<int>> final;
    set<vector<int>> s;
    for (int i{} ; i<n-2 ; ++i){
        for (int j{i+1} ; j<n-1 ; ++j){
            for (int k{j+1} ; k<n ; ++k){
                if (vec[i]+vec[j]+vec[k]==0){
                    vector<int> temp;
                    temp.emplace_back(vec[i]);
                    temp.emplace_back(vec[j]);
                    temp.emplace_back(vec[k]);
                    sort(temp.begin(),temp.end());
                    if (s.find(temp)==s.end()) final.emplace_back(temp);
                    s.insert(temp);
                }
            }
            
        }
    }
    return final;
}

vector<vector<int>> better(int &vec, int n){
    vector<vector<int>> final;

    return final;
}

vector<vector<int>> optimal(int &vec, int n){

}

int main(){
    vector<int> vec{-1,0,1,2,-1,-4};
    size_t size{vec.size()};

    // vector<vector<int>> arr{brute(vec,size)};
    vector<vector<int>> arr{better(vec,size)};

    for (int i{} ; i<arr.size() ; ++i){
        for (int j{} ; j<3 ; ++j){
            cout<< arr[i][j]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}