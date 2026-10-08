#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool brute(string s, string t){
    if (s.size()!=t.size()) return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

bool is_anagram(const string& s, const string& t){
    if (s.size()!=t.size()) return false;
    int hash[26]{};
    for (int i{} ; i<s.size() ; ++i){
        ++hash[s[i]-'a'];
        --hash[t[i]-'a'];
    }
    for (int i : hash){
        if (i) return false;
    }
    return true;
}

int main(){
    string s{"anagram"};
    string t{"nagaram"};
    bool ans{is_anagram(s, t)};
    cout << ans;
    return 0;
}
