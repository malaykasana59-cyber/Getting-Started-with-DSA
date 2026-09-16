#include <algorithm>
#include<iostream>
#include <numeric>
#include<vector>
using namespace std;

bool count_students(const vector<int>& arr, int pages, int m){
    int n{static_cast<int>(arr.size())};
    int cnt_students{1}, add_pages{};
    for (int i{} ; i<n ; ++i){
        if (arr[i]+add_pages<=pages) add_pages+=arr[i];
        else {
            add_pages=arr[i];
            cnt_students++;
            if (cnt_students>m) return false;
        }
    }
    if (cnt_students<=m) return true;
    return false;
}

int brute(vector<int>& arr, int m){
    int n{static_cast<int>(arr.size())};
    if (m>n) return -1;
    int starting_pages{*max_element(arr.begin(),arr.end())};

    // int maximum_pages{};
    // for (int i{} ; i<n ; ++i) maximum_pages+=arr[i];
    int maximum_pages{accumulate(arr.begin(),arr.end(),0)};

    for (int pages{starting_pages} ; pages<=maximum_pages ; ++pages){
        if (count_students(arr,pages,m)==true) return pages;
    }
    return -1;
}

int optimal(const vector<int>& arr, int m){
    int n{static_cast<int>(arr.size())};
    if (m>n) return -1;
    int low{*max_element(arr.begin(),arr.end())};
    int high{accumulate(arr.begin(),arr.end(),0)};
    while (low<=high){
        int mid{low+(high-low)/2};
        if (count_students(arr,mid,m)==true) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    vector books{25, 46, 28, 49, 24};
    int students{4};
    int min_max_pages{brute(books,students)};
    cout << min_max_pages;
    min_max_pages=optimal(books,students);
    cout << min_max_pages;
    return 0;
}