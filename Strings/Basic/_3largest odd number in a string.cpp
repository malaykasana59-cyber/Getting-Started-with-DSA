#include <iostream>
#include <string>
using namespace std;

string largest_odd_number(const string& s){
    int n{static_cast<int>(s.size())};
    int i{};
    while(s[i]=='0') i++;
    for (int j=n-1 ; j>=i ; --j){
        if ((s[j]-'0')%2!=0){
            return s.substr(i,j-i+1);
        }
    }
    return "";
}

int main(){
    string num{"00035427001"};
    string largest{largest_odd_number(num)};
    cout << largest;
    return 0;
}
