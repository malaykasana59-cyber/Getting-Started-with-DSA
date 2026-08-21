#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> brute(vector<vector<int>> arr, int n){
    vector<vector<int>> final;
    sort(arr.begin(),arr.end());
    int start{},end{};
    for (int i{} ; i<arr.size()-1 ; ++i){
        start=i;
        end=i+1;
        if (arr[start][static_cast<int>(arr[i].size()-1)] < arr[end][0]){
            vector<int> temp{arr[start][0],arr[i][static_cast<int>(arr[i].size()-1)]};
            final.push_back(temp);
            start=i+1;
            end=i+2;
        } else {
            start=i;
            end=i+1;
        }
        // for (int j{} ; j<static_cast<int>(arr[i].size())){
        //     if (arr[i][])
        // }
    }
    return final;
}

// vector<vector<int>> optimal(vector<vector<int>> arr, int n){
//     return final;
// }

int main(){
    vector<vector<int>> vec{{1,3},{2,6},{8,9},{2,4},{15,18},{16,17}};
    vector<vector<int>> final{brute(vec, vec.size())};
    for (auto it : final){
        for (auto It : it){
            cout<<It<<' ';
        }
        cout<<'\n';
    }
    return 0;
}