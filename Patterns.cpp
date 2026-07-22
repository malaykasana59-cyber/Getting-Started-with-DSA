#include <iostream>
using namespace std;

// *****
// *****
// *****
// *****
// *****
void pattern1(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "* ";
        }
        cout << '\n';
    }
}

// *
// **
// ***
// ****
// *****
void pattern2 (int n){
    for (int i{0}; i<n; i++){
        for (int j{0};j<i+1;j++){
            cout<<"* ";
        }
        cout<<'\n';
    }
}

// 1
// 12
// 123
// 1234
// 12345
void pattern3 (int n){
    for (int i{0}; i<n; i++){
        for (int j{0};j<i+1;j++){
            cout<<j+1<<" ";
        }
        cout<<'\n';
    }
}

// 1
// 22
// 333
// 4444
// 55555
void pattern4(int n){
    for (int i{0};i<n;i++){
        for (int j{0};j<i+1;j++){
            cout<<i+1<<" ";
        }
        cout<<'\n';
    }
}

// 12345
// 1234
// 123
// 12
// 1
void pattern5(int n){
    for (int i{n};i>0;i--){
        for (int j{0};j<i;j++){
            cout<<j+1<<" ";
        }
        cout<<'\n';

    }
}

//     *
//    **
//   ***
//  ****
// *****
void pattern6(int n){
    for (int i{n};i>0;i--){
        for (int j{0};j<i-1;j++){
            cout<<" ";
        }
        for (int k{0};k<n-i+1;k++){
            cout<<"*";
        }
        cout<<'\n';
    }
}

// *****
//  ****
//   ***
//    **
//     *
void pattern7(int n){
    for (int i{0};i<n;i++){
        for (int j{0};j<i;j++){
            cout<<" ";
        }
        for (int k{n-i};k>0;k--){
            cout<<"*";
        }
        cout<<'\n';
    }
}

//    *
//   ***
//  *****
// *******
//*********
void pattern8(int n){
    for (int i{0}; i<n; i++){
        for (int j{n-i-1};j>0;j--){
            cout<<' ';
        }
        for (int l{2*i+1};l>0;l--){
            cout<<"*";
        }
        for (int k{n-1};k>0;k--){
            cout<<' ';
        }
    cout<<'\n';
    }
}

// Reverse of above case i.e. upside down triangle.
void pattern9(int n){
    for (int i{0};i<n;i++){
        for (int j{0};j<i;j++){
            cout<<' ';
        }
        for (int k{0};k<2*(n-i)-1;k++){
            cout<<'*';
        }
        for (int l{0};l<i;l++){
            cout<<' ';
        }
    cout<<'\n';
    }
}

// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
void pattern10(int n){ // n is the number of rows in the upper half of the pattern
    for (int i{0};i<2*n-1;i++){
        if (i<n){
            for (int j{0};j<(i+1);j++){
                cout<<'*';
            }
        }
        else {
            for (int k{2*n-1-i};k>0;k--){
                cout<<'*';
            }
        }
        cout<<'\n';
    }
}// Solved in the most complicated way but I am a fool so no problem :)

// 1
// 01
// 101
// 0101
// 10101
void pattern11(int n){
//     for (int i{0};i<n;i++){
//         if (i%2==0){
//             for (int j{0};j<i+1;j++){
//                 if (j%2==0){
//                     cout<<'1';
//                 }
//                 else{
//                     cout<<'0';
//                 }
//             }
//         }
//         else {
//             for (int k{0};k<i+1;k++){
//                 if (k%2==0){
//                     cout<<'0';
//                 }
//                 else{
//                     cout<<'1';
//                 }
//             }
//         }
//         cout<<'\n';
//     }
    int start{1};
    for (int i{0};i<n;i++){
        if (i%2==0) start = 1;
        else start = 0;
        for (int j{0};j<i+1;j++){
            cout<<start;
            start=1-start;
        }
        cout<<'\n';
    }
}

// 1      1
// 12    21
// 123  321
// 12344321
/*
PYTHON CODE
for i in range (0,n,1):
    for j in range (0,i+1,1):
        print(j+1,end='')
    for k in range(2*(n-i)-2,0,-1):
        print(' ',end='')
    for l in range (i+1,0,-1):
        print(l,end='')
    print()
*/
void pattern12(int n){
    for (int i{0};i<n;i++){
        for (int j{0};j<i+1;j++){
            cout<<j+1;
        }
        for (int k{2*(n-i)-2};k>0;k--){
            cout<<' ';
        }
        for (int l{i+1};l>0;l--){
            cout<<l;
        }
        cout<<'\n';
    }
}


// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
void pattern13(int n){
    int num{1};
    for (int i{0};i<n;i++){
        for (int j{0};j<i+1;j++){
            cout<<num<<' ';
            ++num;
        }
        cout<<'\n';
    }
}

// A
// AB
// ABC
// ABCD
// ABCDE
void pattern14(int n){
    for (int i{0};i<n;i++){
        for (char ch='A';ch<'A'+i+1;++ch){
            cout<<ch;
        }
        cout<<'\n';
    }
}

// void pattern14(int n, char start){
//     int ch{static_cast<int>(start)};
//     for(int i{0};i<n;i++){
//         for (int j{0};j<i+1;j++){
//             cout<<char(ch+j);
//         }
//         cout<<'\n';
//     }
// }

// ABCDE
// ABCD
// ABC
// AB
// A
void pattern15(int n){
    for (int i{n};i>0;--i){
        for (char ch{'A'};ch<'A'+i;++ch){
            cout<< ch;
        }
        cout<<'\n';
    }
}

// A
// BB
// CCC
// DDDD
// EEEEE
void pattern16(int n){
    // char ch{'A'};
    // for (int i{0};i<n;++i){
    //     for (int j{0};j<i+1;++j){
    //         cout<<ch;
    //     }
    //     ++ch;
    //     cout << '\n';
    // }
    for (char ch{'A'};ch<'A'+n;++ch){
        for (int chr{static_cast<int>('A')};chr<static_cast<int>(ch)+1;++chr){
            cout <<ch;
        }
        cout <<'\n';        
    }
}

//    A
//   ABA
//  ABCBA
// ABCDCBA
void pattern17(int n){
    for (int i{0};i<n;++i){
        for (int j{n-i-1};j>0;--j){
            cout<<' ';
        }
        char ch{'A'};
        for (int j{0};j<2*i+1;++j){
            cout<<ch;
            if (j<i){
                ++ch;
            }
            else{
                --ch;
            }
        }
        cout<<'\n';
    }
}

//    A
//   BAB
//  CBABC
// DCBABCD
void pattern18(int n){
    for (int i{0};i<n;++i){
        for (int k{n-i-1};k>0;--k){
            cout<<' ';
        }
        char start{'A'};
        for (int j{0};j<2*i+1;++j){
            cout<<static_cast<char>(start+i);
            if (j<i){
                --start;
            }
            else{
                ++start;
            }
        }
        cout<<'\n';
    }
}

// E
// DE
// CDE
// BCDE
// ABCDE
void pattern19(int n){
    for (int i{0};i<n;++i){
        char start {static_cast<char>('A'+n-i-1)};
        for (int j{0};j<i+1;++j){
            cout<<start;
            ++start;
        }
        cout<<'\n';
    }
}

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
void pattern20(int n){
    for (int i{0};i<2*n;++i){
        if (i<n){
            for (int j{n-i};j>0;--j){
                cout<<'*';
            }
            for (int k{0};k<2*i;++k){
                cout<<' ';
            }
            for (int l{n-i};l>0;--l){
                cout<<'*';
            }
            cout<<'\n';
        }
        else{
            for (int j{n};j<i+1;++j){
                cout<<'*';
            }
            for (int k{0};k<2*(2*n-i-1);++k){
                cout<<' ';
            }
            for (int l{n};l<i+1;++l){
                cout<<'*';
            }
            cout<<'\n';
        }
    }
}

// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
void pattern21(int n){
    for ( int i{0} ; i<2*n-1 ; ++i ){
        if (i<n){
            for ( int j{0} ; j<i+1 ; ++j ){
                cout<< '*' ;
            }
            for ( int k {2*(n-i-1)} ; k>0 ; --k ){
                cout<< ' ' ;
            }
            for ( int l{0} ; l<i+1 ; ++l ){
                cout<< '*' ;
            }
            cout<< '\n' ;
        }
        else {
            for ( int j {2*n-1-i} ; j>0 ; --j){
                cout<< '*' ;
            }
            for ( int k {0} ; k<2*(i+1-n) ; ++k ){
                cout<< ' ' ;
            }
            for ( int l {2*n-1-i} ; l>0 ; --l){
                cout<< '*' ;
            }
            cout<< '\n';
        }
    }
}

// ****
// *  *
// *  *
// ****
void pattern22(int n){
    // for ( int i{0} ; i<n ; ++i){
    //     if (i==0 or i==n-1){
    //         for ( int j{0} ; j<n ; ++j){
    //             cout<< '*';
    //         }
    //     }
    //     else {
    //         cout<< '*';
    //         for ( int j{1} ; j<n-1 ; ++j){
    //             cout<< ' ';
    //         }
    //         cout<< '*';
    //     }
    //     cout << '\n';
    // }
    for ( int i{0} ; i<n ; ++i){
        for ( int j{0} ; j<n ; ++j){
            if (i==0 or i==n-1 || j==0 || j==n-1){ // or is also written as ||
                cout<< '*';
            }
            else {
                cout<< ' ';
            }
        }
        cout<< '\n';
    }
}

// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444
int minoftwo(int num1,int num2){
    if (num1<num2){
        return num1;
    }
    else {
        return num2;
    }
}
int minimum(int n1,int n2,int n3, int n4){
    // int a= minoftwo(top,bottom);
    // int b= minoftwo(left,right);
    return minoftwo(minoftwo(n1,n2),minoftwo(n3,n4));
}
void pattern23(int n){
    for ( int i{0} ; i<2*n-1 ; i++ ){
        for ( int j{0} ; j<2*n-1 ; ++j ){
            int top =i;
            int left =j;
            int bottom =2*n-2-i;
            int right =2*n-2-j;
            int mindis=minimum(top,bottom,left,right);
            cout << n-mindis;
        }
        cout<< '\n';
    }
}

int main() {
    pattern1(5,5);
    pattern2(5);
    pattern3(5);
    pattern4(5);
    pattern5(5);
    pattern6(5);
    pattern7(5);
    pattern8(5);
    pattern9(5);
    pattern10(5);
    pattern11(5);
    pattern12(4);
    pattern13(5);
    pattern14(5);
    // pattern14(5, 'A');
    pattern15(5);
    pattern16(5);
    pattern17(5);
    pattern18(5);
    pattern19(5);
    pattern20(5);
    pattern21(5);
    pattern22(4);
    pattern23(4);
    return 0;
}
