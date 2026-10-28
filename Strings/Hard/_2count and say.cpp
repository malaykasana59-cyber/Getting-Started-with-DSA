// Generate the nth term of the count-and-say sequence. Each term describes
// the previous term by counting consecutive equal digits.
// Optimized target: O(length of the generated sequence) time and space.

#include <iostream>
#include <string>
using namespace std;

// o(l), o(l)+o(n)
string recursive(int n, const string& number, int iteration){
    if (iteration==n) return number;
    int current_digit{number[0]-'0'}, cnt{};
    string str;
    for (char digit : number){
        if (cnt==0 || current_digit==digit-'0'){
            cnt++;
        } else {
            str += to_string(cnt);
            str += to_string(current_digit);
            current_digit=digit-'0';
            cnt=1;
        }
    }
    str += to_string(cnt);
    str += to_string(current_digit);
    return recursive(n, str, iteration+1);
}

string count_and_say(int n){
    string sequence{"1"}; // here this is 1st iteration and seed is taken as "1"
    for (int iteration{2} ; iteration<=n ; iteration++){
        int current_digit{sequence[0]-'0'}, cnt{};
        string str;
        for (char digit : sequence){
            if (cnt==0 || current_digit==digit-'0'){
                cnt++;
            } else {
                str += static_cast<char>('0'+cnt);
                str += static_cast<char>('0'+current_digit);
                // str += to_string(cnt);
                // str += to_string(current_digit);
                current_digit=digit-'0';
                cnt=1;
            }
        }
        str += static_cast<char>('0'+cnt);
        str += static_cast<char>('0'+current_digit);
        // str += to_string(cnt);
        // str += to_string(current_digit);
        sequence= std::move(str);
    }
    return sequence;
}

int main(){
    int n{4};
    cout << recursive(n,"1",1);
    cout << endl;
    cout << count_and_say(n);
    return 0;
}
