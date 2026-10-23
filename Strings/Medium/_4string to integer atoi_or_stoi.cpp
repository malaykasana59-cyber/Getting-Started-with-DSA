#include <climits>
#include <iostream>
#include <string>
using namespace std;

int string_to_integer(const string& s){
    int ans{};
    int i{};
    bool positive{true};
    while (s[i]==' ' && i<s.size()) ++i;
    if (s[i]=='-'){
        positive=false;
        i++;
    }
    for ( ; i<static_cast<int>(s.size()) ; ++i){
        int digit=s[i]-'0';
        if (digit>9 || digit<0) break;
        else if (ans>INT_MAX/10 || (ans==INT_MAX/10 && digit>7)){
            ans=INT_MIN;
        } else ans = ans*10 + digit;
    }
    if (!positive) ans*=-1;
    return ans;
}

int main(){
    string s{"   -42"};
    cout<<s<<"="<<string_to_integer(s);
    return 0;
}

// Here are some targeted hints to help you fix and improve the function:

// 1. **🛑 Skip spaces safely:** The `while (s[i++]==' ')` loop doesn't verify that `i` is still within the string bounds. If the string is empty or contains only spaces, it will read past the end of memory. Add a bounds check: `i < s.size()`.

// 2. **🔢 Convert `char` to digit correctly:** `static_cast<int>(s[i])` returns the ASCII value (e.g., `'5'` becomes `53`). To get the actual numeric value, subtract the character `'0'`: `int digit = s[i] - '0';`

// 3. **🔄 Fix the loop-breaking condition:** The condition `s[i] >= static_cast<char>(0) && s[i] <= static_cast<char>(127)` will break on almost every printable character, causing you to lose valid digits. You should only break when you encounter a non-digit: `if (s[i] < '0' || s[i] > '9') break;`

// 4. **📈 Overflow/Underflow logic:** 
//    - The tie-breaker in your overflow check should use `==` instead of `>`: `ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > 7)`
//    - The clamped value should respect your sign flag: `pos ? INT_MAX : INT_MIN`

// 5. **🏷️ Apply the sign:** You track `pos`, but never use it before returning. Multiply `ans` by `-1` if `!pos`, or handle the sign during accumulation.

// 6. **➕ Handle the `+` sign (optional but recommended):** Standard `atoi`/`stoi` also skip an optional leading `'+'`. Consider adding a quick check after skipping spaces.

// Try fixing these one by one, and you'll have a robust implementation! Let me know if you want to check your progress after each hint. 💡