#include <climits>
#include <iostream>
#include <string>
using namespace std;

// o(n3+26*n2)
int beauty_of_substr(const string& str){
    int hash[26]{};
    for (char ch : str) ++hash[ch-'a'];
    int max_freq{0}, min_freq{INT_MAX};
    for (int i{} ; i<26 ; ++i){
        max_freq=max(max_freq,hash[i]);
        if (hash[i]!=0) min_freq=min(min_freq,hash[i]);
    }
    return max_freq-min_freq;
}
int brute(const string& s){
    int n{static_cast<int>(s.size())};
    int ans{};
    for (int i{} ; i<n ; ++i){
        for (int j{i+1} ; j<n ; ++j){
            ans+= beauty_of_substr(s.substr(i,j-i+1));
        }
    }
    return ans;
}

// o(26*n2),o(1)
int sum_of_beauty(const string& s){
    int n{static_cast<int>(s.size())};
    int ans{};
    for (int i{} ; i<n ; ++i){
        int hash[26]{};
        for (int j{i} ; j<n ; ++j){
            hash[j-'a']++;
            int mn{INT_MAX}, mx{0};
            for (int k{} ; k<26 ; ++k){
                mx=max(mx,hash[k]);
                if (hash[k]) mn=min(mn,hash[k]);
            }
            ans += mx-mn;
        }
    }
    return ans;
}

int main(){
    string s{"aabcbaa"};
    cout << brute(s)<<endl;
    cout << sum_of_beauty(s);
    return 0;
}
