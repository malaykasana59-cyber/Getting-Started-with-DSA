#include<iostream>
using namespace std;

int main(){
    int max{2};
    for (int i{} ; i<29 ; ++i){
        max *= 2;
    }
    max=max-1+max;
    cout << max;
    return 0;
}