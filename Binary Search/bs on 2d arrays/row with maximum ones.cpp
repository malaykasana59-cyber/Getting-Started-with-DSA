#include<iostream>
#include<vector>
using namespace std;

int bs_lb(const vector<int>& arr, int low, int high, int target){
    int ans{-1};
    while(low<=high){
        int mid{(low+high)/2};
        if (arr[mid]>=target){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}

int bs_ub(const vector<int>& arr, int low, int high, int target){
    int ans{-1};
    while(low<=high){
        int mid{(low+high)/2};
        if (arr[mid]>target){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}

int firstoccurence(const vector<int>& arr, int low, int high, int x){
    int findex{-1};

    while (low<=high){
        int mid{low+(high-low)/2};
        if (arr[mid]==x){
            findex=mid;
            high=mid-1;
        } else if(x<arr[mid]) high=mid-1;
        else low=mid+1;
    }
    return findex;
}

int rowwithmax1s(const vector<int>& arr, int rows, int columns){
    int maxcnt{0};
    int index{-1};
    for (int i{} ; i<rows ; ++i){
        int low=i*columns;
        int high=i*columns+columns-1;
        int _1s_column_index=bs_lb(arr,low,high,1);
        // int _1s_column_index=bs_ub(arr,low,high,0);
        // int _1s_column_index=firstoccurence(arr,low,high,1);
        if (_1s_column_index!=-1){
            int cnt_1s{columns-(_1s_column_index-low)};
            // or high+1-_1s_column_index
            if (cnt_1s>maxcnt) {
                index=i;
                maxcnt=cnt_1s;
            }
        }
    }
    return index;
}

int main(){
    int m{3}, n{3};
    vector<int> mat{
        1, 1, 1,
        0, 0, 1,
        0, 0, 0
    };

    // lowerbound of 1
    // upperbound of 0
    // first occurence of 1
    int rownumber{rowwithmax1s(mat,m,n)};
    cout << rownumber;

    return 0;
}