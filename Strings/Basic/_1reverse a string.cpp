#include<iostream>
#include<vector>
using namespace std;

void reverse_sstring(string& s){
    int n{static_cast<int>(s.size())};
    for (int i{} ; i< n/2 ; ++i)
        swap(s[i],s[n-1-i]);
    return;
}

void reverse_string(vector<char>& s){
    int n{static_cast<int>(s.size())};
    for (int i{} ; i< n/2 ; ++i)
        swap(s[i],s[n-1-i]);
    return;
}

int main(){
    vector<char> s{'h','e','l','l','o'};
    string S{"hello"};
    reverse_string(s);
    for (auto it : s) cout << it;
    cout << '\n';
    reverse_sstring(S);
    cout << S;
    return 0;
}