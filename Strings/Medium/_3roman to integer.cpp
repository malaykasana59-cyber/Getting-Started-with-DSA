#include <iostream>
#include <string>
using namespace std;

int num(char c){
    switch (c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int roman_to_integer(const string& s){
    int answer{};
    for (size_t i{} ; i<s.size()-1 ; ++i){
        int current{num(s[i])};

        if (i + 1 < s.size() && current < num(s[i + 1])){
            answer -= current;
        } else {
            answer += current;
        }
    }
    return answer;
}

int main(){
    string s{"III"};
    cout<<s<<'='<<roman_to_integer(s);
    return 0;
}
