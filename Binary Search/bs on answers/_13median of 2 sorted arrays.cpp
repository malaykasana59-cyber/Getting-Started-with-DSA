#include<iostream>
#include<vector>
using namespace std;

// 1st method is to merge two arrays with merge sort then find medium of that array
// 2nd method is to use shell sort and then find indexes to calculate median
// this is brute method

void brute(vector<int>& arr1, vector<int>& arr2){
    int n1{static_cast<int>(arr1.size())};
    int n2{static_cast<int>(arr2.size())};
    int gap{(n1+n2+1)/2};
    while (gap>0){
        int index{};
        while (index<n1+n2-gap){
            int left{index}, right{index+gap};
            if (left<n1){
                if (right<n1){
                    if (arr1[left]>arr1[right]) swap(arr1[left],arr2[right]);
                } else if (arr1[left]>arr2[right-n1]) swap(arr1[left],arr2[right-n1]);
            } else {
                left=left-n1; right=right-n1;
                if (arr1[left]>arr2[right]) swap(arr1[left-n1],arr2[right-n1]);
            }
            index++;
        }
        if (gap==1) return;
        gap=(gap+1)/2;
    }
    return;
}
// the two arrays are now sorted now find median in main itself;

bool even(int a, int b){
    if ((a+b)%2==0) return true;
    else return false; 
}

float better(vector<int>& arr1, vector<int>& arr2){
    int n1{static_cast<int>(arr1.size())};
    int n2{static_cast<int>(arr2.size())};
    int index_med1{(n1+n2-1)/2}, index_med2{(n1+n2-1)/2+1};
    float val1{-1}, val2{-1};
    int cnt{};
    int left{}, right{};
    while(left<n1 && right<n2){
        if (arr1[left]<=arr2[right]){
            if (cnt==index_med1) val1=arr1[left];
            if (cnt==index_med2){
                val2=arr1[left];
                if (even(n1,n2)) return (static_cast<float>(val1+val2))/2.0;
                else return val1;
            }
            cnt++; left++;
        } else {
            if (cnt==index_med1) val1=arr2[right];
            if (cnt==index_med2){
                val2=arr2[right];
                if (even(n1,n2)) return (static_cast<float>(val1+val2))/2.0;
                else return val1;
                break;
            }
            cnt++; right++;
        }
    }
    while (left<n1){
        if (cnt==index_med1) val1=arr1[left];
        if (cnt==index_med2){
            val2=arr1[left];
            if (even(n1,n2)) return (static_cast<float>(val1+val2))/2.0;
            else return val1;
            break;
        }
        cnt++; left++;
    }
    while (right<n2){
        if (cnt==index_med1) val1=arr2[right];
        if (cnt==index_med2){
            val2=arr2[right];
            if (even(n1,n2)) return (static_cast<float>(val1+val2))/2.0;
            else return val1;
            break;
        }
        cnt++; right++;
    }
    if (even(n1,n2)) return (static_cast<float>(val1+val2))/2.0;
    else return val1;
}

int main(){
    vector arr1{2, 4, 6};
    vector arr2{1, 3, 5};
    float median{better(arr1,arr2)};
    cout << median;
    return 0;
}