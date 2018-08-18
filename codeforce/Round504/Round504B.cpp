#include <iostream>
using namespace std;
#define ll long long

int main(){
    ll n=0,k=0;
    cin>>n>>k;
    
    if(n+1 >=k){
        cout<<(k-1)/2;
    }
    else{
        ll t = k-n;
        ll re = (k-1)/2 - (t-1);
        if(re<0){
            re = 0;
        }
        cout<<re;
    }

    return 0;
}