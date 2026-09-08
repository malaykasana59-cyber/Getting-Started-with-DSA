#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

void mymethod(const vector<int>& arr, int x){
    int low{}, high{static_cast<int>(arr.size())-1};
    int cnt{},findex{-1},lindex{-1};
    while(low<=high){
        int mid{low+(high-low)/2};
        if (x==arr[mid]){
            cnt++;
            findex=lindex=mid;
            int l{mid-1},h{mid+1};
            while(l>=0 && arr[l]==arr[mid]){
                cnt++;
                findex=l--;
            }
            while(h<static_cast<int>(arr.size()) && arr[h]==arr[mid]){
                cnt++;
                lindex=h++;
            }
            break;
        } else if (x>arr[mid]) low=mid+1;
        else high=mid-1;
    }
    cout<<"first occurrence of "<<x<<" is at "<<findex<<"\nlast occurrence at "<<lindex<<"\nand it occurs "<<cnt<<" number of times";
    return;
}

void think(const vector<int>& arr, int x){
    int n{static_cast<int>(arr.size())};
    int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
    int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin()-1;
    if (lb==n || arr[lb] != x) cout<<"first occurrence and last occurrence are {-1,-1} and count is 0";
    else cout<<"first occurrence at : "<<lb<<'\n'<<"last occurrence at : "<<ub<<"\nthe count is "<<ub-lb+1;
}

void optimal(const vector<int>& arr, int x){
    int low{};
    int high{static_cast<int>(arr.size()) - 1};
    int findex{-1};
    int lindex{-1};
    int cnt{};

    while (low<=high){
        int mid{low+(high-low)/2};
        if (arr[mid]==x){
            findex=mid;
            high=mid-1;
        } else if(x<arr[mid]) high=mid-1;
        else low=mid+1;
    }

    if (findex==-1) {
        cout << "first and last occurrence are {-1,-1}";
        cout << "\ncount is 0";
        return;
    }
    
    low=0,high=static_cast<int>(arr.size())-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
          lindex = mid;
          low = mid + 1;
        } else if (x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }

    cnt = lindex - findex + 1;
    cout<<"first occurrence of "<<x<<" is at "<<findex<<"\nlast occurrence at "<<lindex<<"\nand it occurs "<<cnt<<" number of times";
    return;
}

int main(){
    vector vec{3, 4, 13, 13, 13, 20, 40};
    int target{13};
    // mymethod(vec, target);
    // optimal(vec, target);
    think(vec, target);
    return 0;
}