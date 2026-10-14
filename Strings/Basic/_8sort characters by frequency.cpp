#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string brute(string s) {
  if (s.empty())
    return "";
  int hash[128]{};
  // vector<char> ans;
  for (char i : s) {
    hash[i]++;
    // if (find(ans.begin(),ans.end(),i)==ans.end()) ans.emplace_back(i);
  }

  auto lambda = [&hash](char a, char b) {
    if (hash[a] != hash[b])
      return hash[a] > hash[b];
    return a < b;
  };
  sort(s.begin(), s.end(), lambda);
  // sort(ans.begin(),ans.end(),lambda);

  return s;
  // return ans;
}

string better(const string &s) {
  if (s.empty())
    return "";
  vector<char> ans;
  int hash[128]{};
  for (char i : s) {
    hash[i]++;
    if (find(ans.begin(), ans.end(), i) == ans.end())
      ans.emplace_back(i);
  }

  auto lambda = [&hash](char a, char b) {
    if (hash[a] != hash[b])
      return hash[a] > hash[b];
    return a < b;
  };
  sort(ans.begin(), ans.end(), lambda);

  string str;
  for (char c : ans) {
    str.append(hash[c], c);
  }
  return str;
}

// string sort_by_frequency(const string &s) {
//   if (s.empty())
//     return "";

//   int hash[128]{};
//   vector<char> characters;

//   for (char c : s) {
//     hash[c]++;

//     if (find(characters.begin(), characters.end(), c) == characters.end())
//       characters.emplace_back(c);
//   }

//   // Index = frequency, value = characters with that frequency
//   vector<vector<char>> buckets(s.size() + 1);

//   for (char c : characters)
//     buckets[hash[c]].emplace_back(c);

//   string result;
//   result.reserve(s.size());

//   // Highest frequency first
//   for (int frequency{static_cast<int>(s.size())} ; frequency > 0 ; --frequency) {
//     for (char c : buckets[frequency]) {
//       result.append(frequency, c);
//     }
//   }

//   return result;
// }

// /*
string sort_by_frequency(const string& s) {
    if (s.empty())
        return "";

    int hash[128]{};

    for (unsigned char c : s)
        hash[c]++;
    int bucket_size{128+1};
    if (s.size()<=128) bucket_size = s.size()+1;
    vector<vector<char>> buckets(bucket_size);

    // Visit characters alphabetically while placing them in buckets.
    for (int c = 0; c < 128; ++c) {
        if (hash[c] > 0)
        buckets[hash[c]].emplace_back(static_cast<char>(c));
    }

    string result;
    result.reserve(s.size());

    // Highest frequency first.
    for (int frequency = static_cast<int>(s.size()); frequency > 0;
        --frequency) {
        for (char c : buckets[frequency])
        result.append(frequency, c);
    }

    return result;
}
// */

int main() {
  string s{"tree"};
  string result_str{sort_by_frequency(s)};
  cout<<result_str;
  return 0;
}
