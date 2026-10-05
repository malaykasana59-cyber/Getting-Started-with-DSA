#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// o(n2)
bool isIsomorphic(const string& s, const string& t){
    if (s.size() != t.size()) return false;
    int n = s.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if ((s[i] == s[j]) != (t[i] == t[j])) return false;
    return true;
}

// o(n), o(2n)
bool are_isomorphic(const string& s, const string& t){
    if (s.size()!=t.size()) return false;
    unordered_map<char,char> st,ts;
    for (size_t i{} ; i<s.size() ; ++i){
        char a{st[i]}, b{ts[i]};
        if ((st.count(a) && st[a]!=b) || (ts.count(b) && ts[b]!=a)) return false;
        // auto it1 = st.find(a);
        // if (it1 != st.end() && it1->second != b) return false;
        // auto it2 = ts.find(b);
        // if (it2 != ts.end() && it2->second != a) return false;

        st[a]=b;
        ts[b]=a;
    }
    return true;
}

bool optimal(const string& s, const string& t){
    if(s.size()!=t.size()) return false;
    int hash_1[256]{}, hash_2[256]{};
    for (size_t i{} ; i<s.size() ; ++i){
        unsigned char a{static_cast<unsigned char>(s[i])}, b{static_cast<unsigned char>(t[i])};
        if (hash_1[a] == 0 && hash_2[b] == 0) { hash_1[a] = b; hash_2[b] = a; }
        else if (hash_1[a] != b || hash_2[b] != a) return false;
    }
    return true;
}

int main(){
    string s{"egg"};
    string t{"add"};
    if (isIsomorphic(s,t)==true) cout << s << " and " << t << " are isomorphic.";
    else cout << s << " and " << t << " are isomorphic.";
    if (are_isomorphic(s,t)==true) cout << s << " and " << t << " are isomorphic.";
    else cout << s << " and " << t << " are isomorphic.";
    return 0;
}
