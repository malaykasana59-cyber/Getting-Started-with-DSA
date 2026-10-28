// Given a string containing only '{' and '}' brackets, find the minimum
// number of bracket reversals needed to make the expression balanced.
// Optimized target: O(n) time and O(1) extra space.

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int using_stack(const string& s){
    if (s.size()%2==1) return -1;
    stack<char, vector<char>> st;
    for (char ch : s){
        if (ch == '{') st.push(ch);
        else if (st.empty() || st.top()=='}') st.push('}');
        else st.pop();
    }
    int openCnt{}, closeCnt{};
    while (!st.empty()){
        if (st.top()=='}') {closeCnt++; st.pop();}
        else {openCnt++; st.pop();}
    }
    return (openCnt+1)/2+(closeCnt+1)/2;
}

int minimum_reversals(const string& s){
    if (s.size()%2==1) return -1;
    int openCnt{}, closeCnt{};
    for (char ch : s){
        if (ch=='{') openCnt++;
        else if (openCnt>0) openCnt--;
        else closeCnt++;
    }
    return (openCnt+1)/2+(closeCnt+1)/2;
}

int main(){
    string s{"}}}{{}}}}{{{"};
    cout << using_stack(s) << endl;
    cout << minimum_reversals(s);
    return 0;
}
