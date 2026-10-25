#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int brute(const string& s, int k){
    int ans{};
    for (int i{} ; i<s.size() ; i++){
        string str;
        int cnt{};
        for (int j{i} ; j<s.size() ; j++){
            if (find(str.begin(),str.end(),s[j])==str.end()) cnt++;
            str.push_back(s[j]);
            if (cnt==k) ans++;
            else if (cnt>k) break;
        }
    }
    return ans;
}

// # using sliding window
int count_substrings_till_k_unique_el(const string& s, int k){
    int ans{};
    unordered_map<char,int> mp;
    int i{};
    for (int j{} ; j<s.size() ; ++j){
        mp[s[j]]++;
        while(mp.size()>k){
            mp[s[i]]--;
            if (mp[s[i]]==0) mp.erase(s[i]);
            i++;
        }
        ans += j-i+1;
    }
    return ans;
}

// int using_hash_array(const string& s, int k){
//     int ans{};
//     int hashmap[256]{};
//     int i{}, cntr{};
//     for (int j{} ; j<s.size() ; ++j){
//         if (hashmap[s[j]]==0) ++cntr;
//         ++hashmap[s[j]];
//         while (cntr>k){
//             --hashmap[s[i]];
//             if (hashmap[s[i]]==0) --cntr;
//             ++i;
//         }
//         ans += j-i+1;
//     }
//     return ans;
// }

int optimal(const string& s, int n_unique){
    int k{count_substrings_till_k_unique_el(s,n_unique)};
    int k_1{count_substrings_till_k_unique_el(s,n_unique-1)};
    return k-k_1;
    // required substrings with k distinct = substr with atmost k distinct - substr with atmost k-1 distinct
}

int main(){
    string s{"abaabbca"};
    int k{2};
    cout << brute(s,k)<<'\n';
    cout<<optimal(s,k);
    return 0;
}
