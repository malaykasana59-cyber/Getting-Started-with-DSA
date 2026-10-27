#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int i, int j){
    while (i<j){
        if (str[i]==str[j]) ++i, --j;
        else return false;
    }
    return true;
}
string brute(const string& s){
    int longest{};
    string longest_palindromic_substring;
    for (int i{} ; i<s.size() ; ++i){
        for (int j{i} ; j<s.size() ; ++j){
            if (j-i+1>longest){
                // string substring{s.substr(i,j-i+1)};
                if (isPalindrome(s,i,j)){
                    longest=j-i+1;
                    longest_palindromic_substring=s.substr(i,j-i+1);
                }
            }
        }
    }
    return longest_palindromic_substring;
}

// expand on both sides to check for palindrome
// o(n2), o(1)
string longest_palindromic_substring(const string& s){
    int n{static_cast<int>(s.size())};
    int longest{};
    int start_of_longest_palindrome_string{};
    for (int c{} ; c<n ; ++c){
        for (int k{} ; k<2 ; ++k){
            int l{c}, r=c+k;
            while (l>=0 && r<n && s[l]==s[r]) --l, ++r;
            if (r-l-1>longest) longest=r-l-1, start_of_longest_palindrome_string=l+1;
            // l points one position left of the palindrome
            // r points one position right of the palindrome
            // hence length=(r-1)-(l+1)+1 and start=l+1
        }
    }
    return s.substr(start_of_longest_palindrome_string, longest);
}

// optimal solution is manacher's algorithm o(n),o(n)

int main(){
    string s{"babad"};
    cout << "'" << s << "' has '" << brute(s) << "' as the the longest palindromic substring."<<endl;
    cout << "'" << s << "' has '" << longest_palindromic_substring(s) << "' as the the longest palindromic substring.";
    return 0;
}
