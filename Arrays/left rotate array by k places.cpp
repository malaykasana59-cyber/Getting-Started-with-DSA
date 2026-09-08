#include <iostream>
#include <array>
using namespace std;

// Brute force method is to create a temporary array and copy the elements in the required order and then copy back to the original array.
//This takes O(n) time and O(n) space.
void brute(int arr[], int n, int k){
    if (k>=n) k %= n;
    if (k==0) return;
    int temp[n];
    for (int i{k} ; i<n ; ++i){
        temp[i-k]=arr[i];
    }
    for (int j{0} ; j<k ; ++j){
        temp[n-k+j]=arr[j];
    }
    for (int i{0} ; i<n ; ++i) arr[i]=temp[i];
}

// Better method is to create a temporary array of size k and copy the first k elements in it and then shift the 
// remaining n-k elements to the left and then copy the k elements from the temporary array to the end of the original array.
// This takes O(n) time and O(k) space.
void better(int arr[], int n, int k){
    if (k>=n) k=k%n;
    if (k==0) return;
    int temp[k];
    for (int i{0} ; i<k ; ++i) temp[i]=arr[i];
    for (int j{k} ; j<n ; ++j) arr[j-k]=arr[j];
    for (int l{0} ; l<k ; ++l) arr[n-k+l]=temp[l];
}

// Optimal method is to reverse the first k elements, then reverse the remaining n-k elements and then reverse the whole array.
// This takes O(n) time and O(1) space.
void reverse (int arr[], int start, int end){
    while (start<end){
        swap(arr[start], arr[end]);
        ++start; --end;
    }
}
void optimal(int arr[], int n, int k){
    if (k>=n) k %= n;
    if (k==0) return;
    reverse(arr,0,k-1);
    reverse(arr,k,n);
    reverse(arr,0,n);
    return;
}

int main() {
    int arr[]{1,2,3,4,5};
    int n{size(arr)};
    int k{3};
    // brute(arr,n,k);
    better(arr,n,k);
    // optimal (arr, n, k);
    for (auto it : arr) cout << it << ' ';
    return 0;
}
