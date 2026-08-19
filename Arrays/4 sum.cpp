#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> brute(vector<int> &arr, int n){
    set<vector<int>> temp;
    for (int i{} ; i<n-3 ; ++i){
        for (int j{i+1} ; j<n-2 ; ++j){
            for (int k{j+1} ; k<n-1 ; ++k){
                for (int l{k+1} ; l<n ; ++l){
                    if (arr[i]+arr[j]+arr[k]+arr[l]==0){
                        vector<int> t{arr[i],arr[j],arr[k],arr[l]};
                        sort(t.begin(),t.end());
                        temp.insert(t);
                    }
                }
            }
        }
    }
    vector<vector<int>> final{temp.begin(),temp.end()};
    return final;
}

vector<vector<int>> better(vector<int> &arr, int n){
    set<vector<int>> temp;
    for (int i{} ; i<n ; ++i){
        for (int j{i+1} ; j<n ; ++j){
            set<int> hashset;
            for (int k{j+1} ; k<n ; ++k){
                int quadlet=-(arr[i]+arr[j]+arr[k]);
                if (hashset.find(quadlet)!=hashset.end()){
                    vector<int> t{arr[i],arr[j],arr[k],quadlet};
                    sort(t.begin(),t.end());
                    temp.insert(t);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> final{temp.begin(),temp.end()};
    return final;
}

vector<vector<int>> optimal(vector<int> arr, int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>> final;
    for (int i{} ; i<n-3 ; ++i){
        if (i>0 && arr[i]==arr[i-1]) continue;
        for (int j{i+1} ; j<n-2 ; ++j){
            if (j>i+1 && arr[j]==arr[j+1]) continue;
            int k{j+1},l{n-1};
            while(k<l){
                int sum{arr[i]+arr[j]+arr[k]+arr[l]};
                if(sum<0) {
                    k++;
                } else if(sum>0) {
                    l--;
                } else {
                    vector<int> t{arr[i],arr[j],arr[k],arr[l]};
                    final.push_back(t);
                    k++; l--;
                    while (k<l && arr[k]==arr[k-1]) k++;
                    while (k<l && arr[l]==arr[l+1]) l--;
                }
            }
        }
    }
    return final;
}

int main(){
    vector<int> vec{1,0,-1,0,-2,2};
    size_t size{vec.size()};

    // vector<vector<int>> arr{brute(vec,size)};
    vector<vector<int>> arr{better(vec,size)};
    // vector<vector<int>> arr{optimal(vec,size)};

    for (int i{} ; i<arr.size() ; ++i){
        for (int j{} ; j<4 ; ++j){
            cout<< arr[i][j]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}