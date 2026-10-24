#include <climits>
#include <iostream>
#include <string>
using namespace std;

int string_to_integer(const string& s){
    int ans{};
    int i{};
    bool positive{true};
    while (s[i]==' ' && i<s.size()) ++i;
    if (s[i]=='-'){
        positive=false;
        i++;
    }
    for ( ; i<static_cast<int>(s.size()) ; ++i){
        int digit=s[i]-'0';
        if (digit>9 || digit<0) break;
        else if (ans>INT_MAX/10 || (ans==INT_MAX/10 && digit>7)){
            ans=INT_MIN;
        } else ans = ans*10 + digit;
    }
    if (!positive) ans*=-1;
    return ans;
}

int main(){
    string s{"   -42"};
    cout<<s<<"="<<string_to_integer(s);
    return 0;
}
