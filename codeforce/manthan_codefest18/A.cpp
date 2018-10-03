#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin>>n;
    int cnt = 1;
    int i=2;
    while(i-1 < n){
        cnt++;
        i*=2;
    }

    cout<<cnt;
    return 0;
}