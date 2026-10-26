/**
 * Comprehensive Guide to C++ String Concepts
 * 
 * This file covers:
 * 1. Basic Operations
 * 2. Modification
 * 3. Searching
 * 4. Conversion
 * 5. Advanced Concepts (Iterators, Substrings)
 * 6. Common DSA Patterns
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;

/*
===============================================================================
SECTION 1: BASIC DECLARATION AND INITIALIZATION
===============================================================================
*/

void basic_operations() {
    cout << "=== BASIC OPERATIONS ===" << endl;
    
    // 1. Empty string
    string s1; 
    
    // 2. From C-string
    const char* cstr = "Hello";
    string s2(cstr); 
    
    // 3. Copy initialization
    string s3 = s2; 
    
    // 4. From substring
    string s4(s3, 1, 3); // starts at index 1, length 3 -> "ell"
    
    // 5. From n chars
    string s5(5, 'a'); // "aaaaa"
    
    // 6. Range initialization (C++11)
    string s6(s3.begin() + 1, s3.end()); // "ello"

    cout << "s1 (empty): '" << s1 << "'" << endl;
    cout << "s2 (from cstr): '" << s2 << "'" << endl;
    cout << "s3 (copy): '" << s3 << "'" << endl;
    cout << "s4 (substring): '" << s4 << "'" << endl;
    cout << "s5 (repeated char): '" << s5 << "'" << endl;
    cout << "s6 (range): '" << s6 << "'" << endl;
    cout << endl;
}

/*
===============================================================================
SECTION 2: CAPACITY AND ACCESS
===============================================================================
*/

void capacity_and_access() {
    cout << "=== CAPACITY AND ACCESS ===" << endl;
    
    string s = "Hello World";
    
    // Access elements
    cout << "s[0] (front char): " << s[0] << endl;
    cout << "s.front(): " << s.front() << endl;
    cout << "s.back(): " << s.back() << endl;
    
    // Get C-string (useful for interfacing with C libraries)
    cout << "c_str(): " << s.c_str() << endl;
    
    // Capacity info
    cout << "size(): " << s.size() << endl;
    cout << "length(): " << s.length() << endl;
    cout << "capacity(): " << s.capacity() << endl;
    cout << "max_size(): " << s.max_size() << endl;
    cout << "empty(): " << boolalpha << s.empty() << endl; // boolalpha prints true/false instead of 1/0
    cout << endl;
}

/*
===============================================================================
SECTION 3: MODIFICATION
===============================================================================
*/

void modification() {
    cout << "=== MODIFICATION ===" << endl;
    
    string s = "Hello";
    
    // Append
    s += " World";
    s.append("!!");
    cout << "After append: " << s << endl;
    
    // Push back
    s.push_back('?');
    cout << "After push_back: " << s << endl;
    
    // Insert (index, string)
    s.insert(5, "Beautiful ");
    cout << "After insert: " << s << endl;
    
    // Insert (index, count, char)
    s.insert(0, 5, '.'); // "....."
    cout << "After insert char: " << s << endl;
    
    // Erase (index, length)
    s.erase(0, 5); // remove leading dots
    cout << "After erase: " << s << endl;
    
    // Clear
    // s.clear(); 
    // cout << "After clear: empty=" << s.empty() << endl;
    
    // Replace (index, length, new_string)
    string s2 = "abc";
    s2.replace(0, 1, "xyz"); // "xbc"
    cout << "After replace: " << s2 << endl;
    
    cout << endl;
}

/*
===============================================================================
SECTION 4: SEARCHING AND COMPARISON
===============================================================================
*/

void searching() {
    cout << "=== SEARCHING ===" << endl;
    
    string s = "hello world";
    
    // find: returns index or npos if not found
    size_t found = s.find("world");
    if (found != string::npos) {
        cout << "Found 'world' at index: " << found << endl;
    }
    
    // rfind: last occurrence
    string s2 = "banana";
    size_t lastA = s2.rfind("a");
    cout << "Last 'a' in '" << s2 << "' is at: " << lastA << endl;
    
    // find_first_of
    size_t pos = s.find_first_of("aeiou");
    cout << "First vowel in '" << s << "' is at: " << pos << endl;
    
    // Compare
    string a = "abc";
    string b = "abd";
    
    if (a.compare(b) < 0) cout << "'" << a << "' is alphabetically before '" << b << "'" << endl;
    else if (a.compare(b) > 0) cout << "'" << a << "' is alphabetically after '" << b << "'" << endl;
    else cout << "'" << a << "' is equal to '" << b << "'" << endl;
    
    cout << endl;
}

/*
===============================================================================
SECTION 5: CONVERSIONS
===============================================================================
*/

void conversions() {
    cout << "=== CONVERSIONS ===" << endl;
    
    // int to string
    int num = 12345;
    string s1 = to_string(num);
    cout << "Int to String: " << s1 << endl;
    
    // string to int
    string s2 = "42";
    int n1 = stoi(s2);
    cout << "String to Int: " << n1 << endl;
    
    // string to double
    string s3 = "3.14159";
    double d1 = stod(s3);
    cout << "String to Double: " << d1 << endl;
    
    // Stringstream for parsing
    string text = "10 20 30 40";
    stringstream ss(text);
    int val;
    while (ss >> val) {
        cout << "Parsed integer: " << val << endl;
    }
    
    cout << endl;
}

/*
===============================================================================
SECTION 6: COMMON DSA PATTERNS
===============================================================================
*/

void reverse_string() {
    cout << "=== DSA PATTERN: REVERSE STRING ===" << endl;
    
    string s = "DSA";
    // Reverse in-place using STL
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;
    
    // Manual reverse using two pointers
    string s2 = "Reverse Me";
    int left = 0, right = s2.length() - 1;
    while(left < right) {
        swap(s2[left], s2[right]);
        left++;
        right--;
    }
    cout << "Manually Reversed: " << s2 << endl;
    cout << endl;
}

void check_palindrome() {
    cout << "=== DSA PATTERN: PALINDROME CHECK ===" << endl;
    
    string s = "racecar";
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    if (s == rev) {
        cout << "'" << s << "' is a palindrome!" << endl;
    } else {
        cout << "'" << s << "' is NOT a palindrome." << endl;
    }
    cout << endl;
}

void check_anagram() {
    cout << "=== DSA PATTERN: ANAGRAM CHECK ===" << endl;
    
    string s1 = "listen";
    string s2 = "silent";
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    if (s1 == s2) {
        cout << "'" << s1 << "' and '" << s2 << "' are anagrams!" << endl;
    } else {
        cout << "'" << s1 << "' and '" << s2 << "' are NOT anagrams." << endl;
    }
    cout << endl;
}

void uppercase_conversion() {
    cout << "=== DSA PATTERN: UPPERCASE ===" << endl;
    
    string s = "hello world";
    
    // Using STL transform
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << "Upper case: " << s << endl;
    
    cout << endl;
}

void iterators_demo() {
    cout << "=== ITERATORS ===" << endl;
    string s = "Hello";
    
    // Forward iterator
    for(auto it = s.begin(); it != s.end(); ++it) {
        *it = toupper(*it);
    }
    cout << "Modified via iterators: " << s << endl;
    
    // Range-based for loop (syntactic sugar)
    for(char c : s) {
        cout << c;
    }
    cout << endl;
    cout << endl;
}

int main() {
    basic_operations();
    capacity_and_access();
    modification();
    searching();
    conversions();
    reverse_string();
    check_palindrome();
    check_anagram();
    uppercase_conversion();
    
    return 0;
}
