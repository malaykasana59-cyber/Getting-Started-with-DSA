#include <cstddef>
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> brute(vector<int> &vec, size_t &n){
    set<vector<int>> s;
    for (int i{} ; i<n-2 ; ++i){
        for (int j{i+1} ; j<n-1 ; ++j){
            for (int k{j+1} ; k<n ; ++k){
                if (vec[i]+vec[j]+vec[k]==0){
                    vector<int> temp{vec[i],vec[j],vec[k]};
                    sort(temp.begin(),temp.end());
                    // if (s.find(temp)==s.end()) final.emplace_back(temp);
                    s.insert(temp);
                }
            }
            
        }
    }
    vector<vector<int>> final{s.begin(),s.end()};
    return final;
}

vector<vector<int>> better(vector<int> &vec, int n){
    set<vector<int>> temp;
    for (int i{} ; i<n-1 ; ++i){
        set<int> hashset;
        for (int j{i+1} ; j<n ; ++j){
            int triplet{-vec[i]-vec[j]};
            if (hashset.find(triplet)!=hashset.end()){
                vector<int> t{vec[i],vec[j],triplet};
                sort(t.begin(),t.end());
                temp.insert(t);
            }
            hashset.insert(vec[j]);
        }
    }
    vector<vector<int>> final{temp.begin(),temp.end()};
    return final;
}

vector<vector<int>> optimal(vector<int> vec, int n){
    vector<vector<int>> final;
    sort(vec.begin(), vec.end());
    for (int i{0} ; i<n-2 ; ++i){
        if (i>0 && vec[i]==vec[i-1]) continue;
        int j{i+1}, k{n-1};
        while (j<k){
            int sum{vec[i]+vec[j]+vec[k]};
            if (vec[i]+vec[j]+vec[k]<0) {
                j++;
            } else if(vec[i]+vec[j]+vec[k]>0) {
                k--;
            } else {
                vector<int> t{vec[i],vec[j],vec[k]};
                final.push_back(t);
                j++;k--;
                while (j<k && vec[j]==vec[j-1]) j++;
                while (j<k && vec[k]==vec[k+1]) k--;
            }
        }
    }
    return final;
}

int main(){
    vector<int> vec{-1,0,1,2,-1,-4};
    size_t size{vec.size()};

    // vector<vector<int>> arr{brute(vec,size)};
    // vector<vector<int>> arr{better(vec,size)};
    vector<vector<int>> arr{optimal(vec,size)};

    for (int i{} ; i<arr.size() ; ++i){
        for (int j{} ; j<3 ; ++j){
            cout<< arr[i][j]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}