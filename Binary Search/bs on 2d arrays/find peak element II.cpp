#include <climits>
#include<iostream>
#include<vector>
using namespace std;

int findmax(const vector<vector<int>>& arr, int col, int no_of_rows){
    int best{0};
    for (int i{1}; i < no_of_rows; ++i)
        if (arr[i][col] > arr[best][col]) best = i;
    return best;
}

pair<int,int> bs(const vector<vector<int>>& arr){
    int m{static_cast<int>(arr.size())};        // rows
    int n{static_cast<int>(arr[0].size())};     // columns
    int low{}, high{n - 1};
    
    while (low <= high) {
        int mid{low + (high - low) / 2};
        int max_element_containing_row{findmax(arr, mid, m)};
        int current = arr[max_element_containing_row][mid];

        int left  = (mid > 0)     ? arr[max_element_containing_row][mid - 1] : INT_MIN;
        int right = (mid + 1 < n) ? arr[max_element_containing_row][mid + 1] : INT_MIN;

        if (current > left && current > right) return {max_element_containing_row, mid};
        else if (left > current) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};
}

int main(){
    vector<vector<int>> mat{
        {1, 4, 7, 11, 15}, 
        {2, 5, 8, 12, 19}, 
        {3, 6, 9, 16, 22}, 
        {10, 13, 14, 17, 24}, 
        {18, 21, 23, 26, 30}
    };
    pair<int,int> peak_element_index{bs(mat)};
    cout << peak_element_index.first << ' ' << peak_element_index.second;
    return 0;
}