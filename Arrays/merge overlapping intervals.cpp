#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// o(n log n), o(2n)
vector<vector<int>> self_think(vector<vector<int>> arr){
    vector<vector<int>> final;
    sort(arr.begin(),arr.end());
    int start{},end{1};
    while (end < arr.size()){
        if (arr[start][1]>=arr[end][0]){
            if (arr[start][1]<arr[end][1]){
                arr[start][1]=arr[end][1];
                end++;
            } else {
                end++;
            }
        } else {
            final.emplace_back(arr[start]);
            start=end;
            end++;
        }
        if (end==arr.size()){
            final.emplace_back(arr[start]);
        }
    }
    return final;
}

// o(n log n)+o(2n), o(n)
vector<vector<int>> brute(vector<vector<int>>& arr){
    int n{static_cast<int>(arr.size())};
    vector<vector<int>> final;
    sort(arr.begin(),arr.end());
    for (int i{} ; i<n ; ++i){
        int start{arr[i][0]},end{arr[i][1]};
        if (!final.empty() && end <= final.back()[1]){
            continue;
        }
        for (int j{i+1} ; j<n ; ++j){
            if (arr[j][0] <= end){
                end = max(end,arr[j][1]);
            } else {
                break;
            }
        }
        final.push_back({start,end});
    }
    return final;
}

// o(n log n), o(n)
vector<vector<int>> optimal(vector<vector<int>>& arr){
    int n{static_cast<int>(arr.size())};
    vector<vector<int>> final;
    sort(arr.begin(),arr.end());
    for (int i{} ; i<n ; i++){
        if (final.empty() || arr[i][0] > final.back()[1]){
            final.emplace_back(arr[i]);
        } else {
            final.back()[1]=max(final.back()[1],arr[i][1]);
        }
    }
    return final;
}

int main(){
    vector<vector<int>> vec{{1,3},{2,6},{8,9},{2,4},{15,18},{16,17}};
    // vector<vector<int>> final{brute(vec)};
    // vector<vector<int>> final{self_think(vec)};
    vector<vector<int>> final{optimal(vec)};
    for (auto it : final){
        for (auto It : it){
            cout<<It<<' ';
        }
        cout<<'\n';
    }
    return 0;
}