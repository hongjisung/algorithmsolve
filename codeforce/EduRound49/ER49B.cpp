#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
#define ll long long

int main(){
    ll N=0, Q=0;
    cin>>N>>Q;
    
    ll r=0, c=0;
    for(int tc=1; tc<=Q; tc++){
        scanf("%d %d", &r, &c);
        ll result = 0;
        if((N&1)==0){
            if((r+c)%2==0){
                ll cnt = N/2 * (r-1) + (c-1)/2+1;
                result = cnt;
            }
            else{
                ll cnt = N/2 *(r-1) + (c-1)/2 +1;
                result = N*N/2 + N*N%2 +cnt;
            }
        }
        else{
            if((r+c)%2==0){
                ll cnt = (N/2 +1) * (r/2) + (N/2) * ((r-1)/2) + (c-1)/2 +1;
                result = cnt;
            }
            else{
                ll cnt = (N/2)*(r/2) + (N/2+1)*((r-1)/2) +(c-1)/2+1;
                result = N*N/2 +N*N%2 +cnt;
            }
        }

        printf("%lld\n", result);
    }
    return 0;
}