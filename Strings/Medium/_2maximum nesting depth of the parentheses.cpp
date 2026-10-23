#include <iostream>
#include <string>
using namespace std;

int maximum_nesting_depth(const string& s){
    int depth{};
    int maxdepth{};
    for (char ch : s){
        if (ch == '('){
            ++depth;
            maxdepth=max(maxdepth,depth);
        } else if (ch == ')'){
            --depth;
        }
    }
    return maxdepth;
}

int main(){
    string s{"(1+(2*3)+((8)/4))+1"};
    cout << maximum_nesting_depth(s);
    return 0;
}
