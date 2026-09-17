#include<iostream>
#include<vector>
#include<queue>
using namespace std;

double brute(const vector<int>& arr, int k){
    int n{static_cast<int>(arr.size())};
    int* hash = new int[n-1]{};

    for (int cnt{1} ; cnt<=k ; ++cnt){
        double Max{-1};
        int maxindex{-1};
        for (int i{} ; i<n-1 ; ++i){
            int diff{arr[i+1]-arr[i]};
            double section_length{static_cast<double>(diff)/static_cast<double>(hash[i]+1)};
            if (section_length>Max){
                Max=section_length;
                maxindex=i;
            }
        }
        hash[maxindex]++;
    }
    double max_ans{-1};
    for (int i{} ; i<n-1 ; ++i){
        // int diff{arr[i+1]-arr[i]};
        // double section_length{diff/static_cast<double>(hash[i]+1)};
        max_ans=max(static_cast<double>(arr[i+1]-arr[i])/static_cast<double>(hash[i]+1),max_ans);
    }
    delete[] hash;
    return max_ans;
}

// o(n log n + k log n), o(n-1)
double better(const vector<int>& arr, int k){
    int n{static_cast<int>(arr.size())};
    vector<int> hash(n-1,1);
    priority_queue<pair<double,int>> pq; // section length, hash index
    for (int i{} ; i<n-1 ; ++i){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gsStation{} ; gsStation<k ; ++gsStation){
        auto tp = pq.top(); pq.pop(); // pick out top section length
        double section_length=tp.first;
        hash[tp.second]++;
        double new_section_length{section_length/hash[tp.second]};
        pq.push({new_section_length,tp.second});
    }
    return pq.top().first;
}

// optimal starts from here
// o(n+k log n), o(1)

int cnt_no_of_gas_stations(const vector<int>& arr, long double dist){
    int cnt{};
    for (int i{} ; i<static_cast<int>(arr.size())-1 ; ++i){
        int num_in_between{static_cast<int>(static_cast<double>(arr[i+1]-arr[i])/dist)};
        cnt+=num_in_between;
    }
    return cnt;
}

double optimal(const vector<int>& arr, int k){
    int n{static_cast<int>(arr.size())};
    long double low=0;
    long double high{};
    for (int i{} ; i<n-1 ; ++i){
        high=max(high,static_cast<long double>(arr[i+1]-arr[i]));
    }
    while (high-low>1e-6){
        long double mid{low+(high-low)/2};
        int cnt{cnt_no_of_gas_stations(arr,mid)};
        if (cnt<=k) high=mid;
        else low=mid;
    }
    return high;
}

int main(){
    // vector position_of_stations{1,2,3,4,5}; //k=4 to get ans 0.5
    vector position_of_stations{1,6,13,17,23};
    int more_to_add_btw_them{5};
    double min_max_dist_among_config{brute(position_of_stations,more_to_add_btw_them)};
    cout << min_max_dist_among_config << '\n';
    min_max_dist_among_config = better(position_of_stations,more_to_add_btw_them);
    cout << min_max_dist_among_config << '\n';
    min_max_dist_among_config = optimal(position_of_stations,more_to_add_btw_them);
    cout << min_max_dist_among_config;
    return 0;
}