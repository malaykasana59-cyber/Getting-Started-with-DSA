#include <iostream>
#include <string>
#include <vector>
using namespace std;

string removeOuterParentheses_using_stack(const string& s) {
    //TC:O(N) SC:O(N)  --  Stack Approach
    string ans="";
    vector<char> stck;
    for(auto ch:s){
        if(ch == '('){
            stck.emplace_back(ch);
            if(stck.size()>1) ans += ch;
        }else{
            stck.pop_back();
            if(stck.size()>=1) ans+= ch;
        }
    }
    return ans;
}

// o(n), o(1)
string removeOuterParentheses(const string& s) {
    string str;
    int cnt{1};
    for (int i{1} ; i<static_cast<int>(s.size()) ; ++i){
        if (s[i]=='(') {
            cnt++;
        } else cnt--;
        if (cnt!=0) {
            str.push_back(s[i]);
        } else {
            cnt=1;
            i++;
        }
    }
    return str;
}
//    |
//    |
//   \ /
//    o  
string remove_outermost_parentheses(const string& s){
    string str;
    str.reserve(s.size());
    int depth{};
    for (char c : s){
        if (c=='('){
            if (depth++ > 0) str.push_back(c);
        } else if (--depth > 0) str.push_back(c);
    }
    return str;
}

int main(){
    string s{"(()())(())"};
    string new_str{remove_outermost_parentheses(s)};
    // string new_str{remove_outermost_parentheses(s)};
    cout<< s << '\n';
    cout<< new_str;
    return 0;
}
