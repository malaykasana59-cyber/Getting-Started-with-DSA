#include <algorithm>
#include<vector>
#include<iostream>
using namespace std;

int brute(const vector<int>& arr, int given_hours){
	int n = static_cast<int>(arr.size());

    int total = 0;
    for (int x : arr) total += x;
	// At speed k, Koko can eat at most k * given_hours bananas.
	// Therefore k must be at least ceil(total / given_hours).
	// Adding given_hours - 1 performs ceiling division using integers.
    int hourly_eaten_bananas = (total + given_hours - 1) / given_hours;
    if (hourly_eaten_bananas < 1) hourly_eaten_bananas = 1;

	// instead of above code hourly_eaten_bananas=1 can also be taken

    while (true){
        int hours_taken = 0;
        for (int i = 0; i < n; i++){
            hours_taken += (arr[i] + hourly_eaten_bananas - 1) / hourly_eaten_bananas;
            if (hours_taken > given_hours) break;   // already failed, stop early
        }
        if (hours_taken <= given_hours) return hourly_eaten_bananas;
        hourly_eaten_bananas++;
    }
}

int optimal(const vector<int>& arr, int h){
	int n{static_cast<int>(arr.size())};
	int maxPile = *max_element(arr.begin(),arr.end());
	// for (int i{} ; i<n ; i++){
	// 	maxPile=max(maxPile,arr[i]);
	// }
	int ans{arr[maxPile]}; 
	int low{1}, high{maxPile};
	while(low<=high){
		int mid{low+(high-low)/2};
		int hours_taken{};

		for (int i{} ; i<n ; i++){
			hours_taken += (arr[i]+mid-1)/mid; // hours taken = ceil (+arr[i])/mid
			if (hours_taken>h) break;
		}
		
		if (hours_taken <= h){
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return ans;
}

int main(){
	vector no_of_piles{3,6,7,11};
	int hours_to_eat{8};
	// int ans{brute(no_of_piles,hours_to_eat)};
	int ans{optimal(no_of_piles,hours_to_eat)};
	cout << ans;
	return 0;
}
