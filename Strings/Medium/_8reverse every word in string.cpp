#include <iostream>
#include <string>
using namespace std;

string brute(const string& s){
    string new_str;
    new_str.reserve(s.size());
    int start_index{}, word_end_index{static_cast<int>(s.size())-1};
    while(s[start_index]==' ') ++start_index;
    while(s[word_end_index]==' ') --word_end_index;
    if (start_index>word_end_index) return new_str;
    for (int i{word_end_index} ; i>start_index ; --i){
        if (s[i]==' '){
            // new_str.append(s.substr(i+1,word_end_index-(i+1)+1));
            new_str.append(s,i+1,word_end_index-i);
            // new_str.append(" ");
            new_str+=" ";
            word_end_index=i-1;
        }
    }
    // new_str.append(s.substr(start_index,word_end_index+1));
    new_str.append(s,start_index,word_end_index-start_index+1);
    return new_str;
}

// still a few problems like more than 1 space between words

string reverse_word(const string& s){
    string out;
    out.reserve(s.size());
    int i = static_cast<int>(s.size()) - 1;
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') --i;      // skip spaces
        if (i < 0) break;
        int end = i;
        while (i >= 0 && s[i] != ' ') --i;      // find the word start
        if (!out.empty()) out += ' ';
        out.append(s, i + 1, end - i);          // pass s
    }
    return out;
}

int main(){
    string s{"Welcome to the jungle"};
    cout << brute(s)<<endl;
    cout << reverse_word(s);
}