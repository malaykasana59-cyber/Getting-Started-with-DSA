#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(const string& s){
	int n{static_cast<int>(s.size())};
	for (int i{} ; i<n ; ++i)
		if (s[i] != s[n-1-i]) return false;
	return true;
}

int main(){
	string s{"A man, a plan, a canal: Panama"};
	cout << is_palindrome(s);
	return 0;
}
