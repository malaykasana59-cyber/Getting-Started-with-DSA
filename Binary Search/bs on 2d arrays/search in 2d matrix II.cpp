#include<iostream>
#include<vector>
using namespace std;

bool isPresent(const vector<vector<int>>& arr, int x){
    int m{static_cast<int>(arr[0].size())};
    int n{static_cast<int>(arr.size())};
    int row{}, column{m-1};
    while(row<n && column>=0){
        if (arr[row][column]==x) {cout<<'{'<<row<<','<<column<<"}\n"; return true;}
        else if (arr[row][column]<x) row++;
        else column--;
    }
    return false;
}

int main(){
    vector<vector<int>> mat{
        {1, 4, 7, 11, 15}, 
        {2, 5, 8, 12, 19}, 
        {3, 6, 9, 16, 22}, 
        {10, 13, 14, 17, 24}, 
        {18, 21, 23, 26, 30}
    };
    int target{20};
    if(isPresent(mat,target)) cout << "present\n";
    else cout << "not present\n";
    return 0;
}