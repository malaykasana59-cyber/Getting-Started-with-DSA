#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int countdigits(int n) {
    // int cnt = 0;
    // while (n>0){
    //     ++cnt;
    //     n=n/10;
    // }
    // return cnt;

    int cnt = static_cast<int>(log10(n)) + 1; // TC -> O( log10(N) )
    return cnt;
}

int reversenumber(int n){
    int revnum {0};
    while (n>0){
        int r{n%10};
        revnum = revnum*10+r;
        n /= 10;
    }
    return revnum;
}

bool ifpalindrome(int n){
    int dup{n};
    int revnum{reversenumber(n)};
    if (dup==revnum){
        return true;
    }
    else {
        return false;
    }
}

bool ifarmstrongfor3digit(int n){
    int dup{n};
    int sumofcubes{0};
    while (n>0){
        int r{n%10};
        n /= 10;
        sumofcubes += (r*r*r);
    }
    if (dup==sumofcubes){
        return true;
    }
    else {
        return false;
    }
}

// o()
bool isPerfect(int n) {
    int s{};
    for (int i{1} ; i*i<n ; ++i){
        if (n%i==0){
            s+=i;
            if (n/i != n) s+=n/i;
        }
    }
    return s==n;
}

void printdivisions(int n){ // TC -> O(N)
    // for (int i{1} ; i<=n ; ++i){
    //     if (n%i==0){
    //         cout<< i<<' ';
    //     }
    // }

    vector<int> ls;
    for (int i{1} ; i*i<=n ; ++i){ // TC -> O(sqrt(n))
        if (n%i==0){
            ls.emplace_back(i);
            if (n/i != i){
                ls.emplace_back(n/i);
            }
        }
    }
    sort(ls.begin(),ls.end()); // O(no.of factors * log(no. of factors))
    for (auto it : ls) cout<< it << ' '; // O(no. of factors)
}

void ifprime(int n){
    if (n < 2) {
        cout << "It is not a prime number.";
        return;
    }

    int cnt{0};

    for (int i{1} ; i*i<=n ; ++i){
        if (n%i==0){ 
            ++cnt;
            if ((n/i)!= i) ++cnt;
        }
    }
    if (cnt == 2) cout<<"It is a prime number.";
    else cout << "It is not a prime number.";
}

// primes less than n 
// using sieve of eratosthenes
// keep marking multiples of that prime number till n, we already considered 2 so didnt compute for even numbers
int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> hash(n,1);
    hash[0]=hash[1]=0;
    int cnt{1}; // considering 2

    int i{};
    for (i=3 ; i*i<n ; i+=2){
        if (hash[i]){
            int d=i*2;
            for (int j=i*i ; j<n ; j+=d){
                hash[j]=0;
            }
        }
    }
    for (int i{3} ; i<n ; i+=2) if (hash[i]==1) cnt++;
    return cnt;
}

void printGcdHcf(int n1, int n2){
    // int gcd{};
    // for (int i{1} ; i<=min(n1,n2) ; ++i){ // O(min(n1,n2))
    //     if (n1%i==0 && n2%i==0) gcd=i;
    // }

    // Euclidean Algorithm
    // gcd(a,b)=gcd(a-b,b)  a>b
    // gcd(a,b)==gcd(a%b,b) a>b

    while (n1>0 && n2>0){ // O(log to base phi min(a,b))
        if (n1>n2) n1 %= n2;
        else n2 %= n1;
    }
    cout << "GCD = ";
    if (n1==0) cout<<n2;
    else cout<<n1;
}

// lcm * hcf = a * b
void lcm(int a, int b){
    while (a>0 && b>0){
        if (a>b) a%=b;
        else b%=a;
    }
    int gcd;
    if (a==0) gcd=b;
    else gcd=a;

    cout << "LCM of " << a << " and " << b << "is " <<(a*b)/gcd;
}

vector<int> divisors(int n) {
    vector<int> divs;
    for (int i{1} ; i*i<=n ; ++i){
        if (n%i==0){
            auto greater_than_i=upper_bound(divs.begin(),divs.end(),i);
            divs.insert(greater_than_i,i);
            if (i!=n/i){
                greater_than_i=upper_bound(divs.begin(),divs.end(),n/i);
                divs.insert(greater_than_i,n/i);
            }
        }
    }
    return divs;
}

int main(){
    int n{};
    cout<< "Enter a number : ";
    cin>> n;
    cout<<'\n';

    // int a = countdigits(n);
    // cout << "The number of digits in given number is "<<a;

    // int b = reversenumber(n);
    // cout<< "The reverse number is : "<< b <<'\n';

    // bool c{ifpalindrome(n)};
    // cout<< c;
    // // if (c==true){
    // //     cout << "The number is a palindrome.";
    // // }
    // // else {
    // //     cout << "The number is not a palindrome.";
    // // }

    // bool d{ifarmstrongfor3digit(n)};
    // cout<< d;

    // printdivisions(n);

    // ifprime(n);

    int n1{};
    int n2{};
    cout<< "Enter 2 numbers to check for prime : ";
    cin >> n1 >>n2;
    printGcdHcf(n1,n2);

    return 0;
}
