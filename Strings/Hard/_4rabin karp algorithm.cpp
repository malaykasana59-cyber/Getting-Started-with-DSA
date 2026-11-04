// Given a text and a pattern, return every 0-based index where the pattern
// occurs in the text. Return an empty vector when it does not occur.
// Implement Rabin-Karp with a rolling hash and verify matching windows to
// handle collisions. Optimized target: O(n + m) average time and O(1) extra
// space apart from the returned indices, where n and m are input lengths.

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

vector<int> brute(const string& text, const string& pattern){
    int n{static_cast<int>(text.size())};
    int m{static_cast<int>(pattern.size())};
    if (m==0 || n==0 || m>n) return {};
    vector<int> indices;
    for (int i{} ; i<n ; ++i){
        for (int j{i} ; j<n ; ++j){
            if (j-i+1==m && text.substr(i,j-i+1)==pattern) {
                indices.emplace_back(i);
                break;
            }
        }
    }
    if (indices.empty()) indices.emplace_back(-1);
    return indices;
}
//  ||     this is almost the same just few modifications
//  ||     like it compares in place directly without creating a substring
// \||/    without creating a substring
//  \/
vector<int> brute1(const string& text, const string& pattern){
    int n{static_cast<int>(text.size())};
    int m{static_cast<int>(pattern.size())};
    if (m==0 || m>n || n==0) return {};
    vector<int> indices;
    for (int i{} ; i+m<=n ; ++i)
        if (text.compare(i,m,pattern)==0) indices.emplace_back(i);
/*
compare doesn’t return a bool. It returns an int that tells you the ordering, like strcmp:

0: the two strings are equal
negative: the first (the window) is lexicographically smaller than the second (pattern)
positive: the first is lexicographically larger
*/
    if (indices.empty()) indices.emplace_back(-1);
    return indices;
}

// rolling hash
// we take base as 256 as we are considering all characters that can be fit on a byte
vector<int> rabin_karp(const string& text, const string& pattern){
    int n{static_cast<int>(text.size())};
    int m{static_cast<int>(pattern.size())};
    if (m == 0 || m > n) return {};

    const long long MOD = 1'000'000'007, B = 26; // 1e9+7 is prime and big and satifies most conditions to be a MOD
    long long high = 1, ph = 0, th = 0; // ph->patternHash , th->currentTextHash
    // high will hold B^(m-1), the weight of the leftmost character. It is needed later to remove that character when the window slides.
    vector<int> indices;

    for (int k = 0; k < m - 1; ++k) high = high * B % MOD;
    // This multiplies by B exactly m-1 times, so high = B^(m-1) mod M
    // basically it reduces spurious hits by taking MOD so high and then taking high = high % MOD

    for (int k = 0; k < m; ++k) {
    ph = (ph * B + (unsigned char)pattern[k]) % MOD;
    th = (th * B + (unsigned char)text[k]) % MOD;
    // exponential like a*B^0 + b*B^1 + c*B^2 + ... using horner's form
    }

    if (th==ph && text.compare(0,m,pattern)==0)
        indices.emplace_back(0);

    int i{1}, j{m};
    while (j<n) {
        th = (th - ((unsigned char)text[i - 1] * high) % MOD + MOD) % MOD;
        th = (th * B + ((unsigned char)text[j])) % MOD;
        if (th==ph && text.compare(i,m,pattern)==0)
            indices.emplace_back(i);
        i++; j++;
    }

    if(indices.empty()) indices.emplace_back(-1);
    return indices;
}

int main(){
    string text{"ababcabcabababd"};
    string pattern{"ababd"};
    vector<int> ans{brute(text, pattern)};
    for (int it : ans) cout << it << ' ';
    return 0;
}
