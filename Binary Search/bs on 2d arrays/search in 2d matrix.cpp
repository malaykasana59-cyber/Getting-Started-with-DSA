#include<iostream>
#include<vector>
using namespace std;

bool isPresent(const vector<vector<int>>& arr, int x){
    int L{}, H{static_cast<int>(arr.size())-1};
    while (L<=H){
        int M=L+(H-L)/2;
        if (x<=arr[M][static_cast<int>(arr[M].size())-1] && x>=arr[M][0]){
            int low{}, high{static_cast<int>(arr[M].size())-1};
            while (low<=high){
                int mid{low+(high-low)/2};
                if (arr[M][mid]==x) return true;
                else if (arr[M][mid]<x) low=mid+1;
                else high=mid-1;
            }
            return false;
        } else if (x<arr[M][0]){
            H=M-1;
        } else L=M+1;
    }
    return false;
}

bool isPresent1(const vector<vector<int>>& arr, int x){
    int m{static_cast<int>(arr[0].size())};
    int n{static_cast<int>(arr.size())};
    int low{}, high{m*n-1};
    while(low<=high){
        int mid{low+(high-low)/2};
        int row{mid/m}, column{mid%m};
        if (arr[row][column]==x) return true;
        else if (x<arr[row][column]) high=mid-1;
        else low=mid+1;
    }
    return false;
}

int main(){
    vector<vector<int>> mat{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int target{8};
    if(isPresent(mat,target)) cout << "present\n";
    else cout << "not present\n";
    if(isPresent1(mat,target)) cout << "present";
    else cout << "not present";
    
    return 0;
}