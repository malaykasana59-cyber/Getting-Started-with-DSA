#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(const vector<string>& str){
    if (str.empty()) return "";
    int size{static_cast<int>(str.size())};
    int start{};
    for (char s : str[0]) {
        bool present_in_all = true;
        for (int i{1}; i < size; ++i) {
            if (start >= static_cast<int>(str[i].size()) || str[i][start] != s) {
                present_in_all = false;
                break;
            }
        }
        if (present_in_all) start++;
        else break;
    }
    return str[0].substr(0, start);
}

// alternate : shrinking the prefix
string alternate(const vector<string>& str){
    const string& first = str[0];     // the string we use as the guess
    size_t len = first.size();        // guess = first[0 .. len-1]

    for (size_t i = 1; i < str.size() && len > 0; ++i) {
        size_t j = 0;
        while (j < len && j < str[i].size() && first[j] == str[i][j]) ++j;
        len = j;                      // new guess length = how many chars matched
    }
    return first.substr(0, len);
}

int main(){
    vector<string> strs{"flower", "flow", "flight"};
    string common{longestCommonPrefix(strs)};
    cout<<common;
    return 0;
}
