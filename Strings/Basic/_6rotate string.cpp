#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

// Brute:
// if len(s) != len(goal): return false
// n = len(s)
// for i in 0 to n-1:
//     rotated = suffix from i + prefix upto i
//     if rotated == goal: return true
// return false
 

bool can_rotate_better(const string& s, const string& goal){
    if (s.size()!=goal.size()) return false;
    for (size_t i{0} ; i<s.size() ; ++i){
        bool is_match{true};
        for (size_t j{} ; j<s.size() ; ++j){
            if (s[(i+j)%s.size()]!=goal[j]){
                is_match=false;
                break;
            }
        }
        if (is_match) return true;
    }
    return false;
}

bool can_rotate(const string& s, const string& goal){
    if (s.size()!=goal.size()) return false;
    if (s==goal) return true;
    string doubled{s+s};
    for (size_t i{1} ; i<s.size()-1 ; ++i){
        if (goal==doubled.substr(i,s.size())) return true;
    }
    return false;
}

int main(){
    string s{"abcde"};
    string goal{"cdeab"};
    bool can{can_rotate(s,goal)};
    if (can==0) return 0;
    cout << "true, " << s << " can be rotated to get " << goal;
    return 0;
}
