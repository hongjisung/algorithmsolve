#include <iostream>
#include <vector>
using namespace std;
#define div 1000000007
long long two[200001], fact[200001];

/*
2N people 
M pairs
each pair can not sitting next to each other

total = 2N!  : m=0
m pairs attached -> 2^m * (2N-m)!
    odd -1
    even +1
    mCr

sigma (r = 0 to m) 2^r * (2N-r)! * mCr * (-1)^r 

1<=M<=N<=100000

*/

long long twoover(long long n){
    long long re = 1;
    for(long long i=0; i<n; i++){
        re<<=1;
        if(re>div){
            re%=div;
        }
    }
    return re;
}

long long factorial(long long n){
    long long re = 1;
    for(long long i=2; i<=n; i++){
        re*=i;
        if(re>div){
            re%=div;
        }
    }
    return re;
}

long long euclid(long long a, long long b){
    long long a1 = 1, a2 = 0, a3 = a;
    long long b1 = 0, b2 = 1, b3 = b;
    while(b3 > 1){
        long long t = a3/b3;
        long long t1 = a1 - b1*t, t2 = a2 - b2*t, t3 = a3 - b3*t;
        a1 = b1; a2 = b2; a3 = b3;
        b1 = t1; b2 = t2; b3 = t3;
    }

    if(b1 < 0){
        b1 += b;
    }
    return b1;
}

long long mCr(long long m, long long r){
    long long up = fact[m];
    long long down1 = fact[r], down2 = fact[m-r];
    down1 = euclid(down1, div);
    down2 = euclid(down2, div);
    return (up*down1)%div * down2 % div;

}

int main(){
    int T=0;
    cin>>T;

    // make pre-computed array
    two[0] = 1; fact[0] = 1;
    for(int i=1; i<=200000; i++){
        two[i] = (two[i-1]<<1)%div;
        fact[i] = (fact[i-1]*i)%div;
    }

    for(int tc=1; tc<=T; tc++){
        long long N=0,M=0;
        cin>>N>>M;

        long long total = 0;
        for(long long r=0; r<=M; r++){
            // cout<<"twoover " << r <<" " << twoover(r) << "\n";
            // cout<<"factorial " << 2*N-r <<" " << factorial(2*N-r) << "\n";
            // cout<<"mCr " << M << " " << r << " " << mCr(M,r) << "\n";
            // cout<<"r&1 " << r << " " << ((r&1)==1?-1:1) << "\n";
            // cout<<"result : "<<( ( ( twoover(r) * fact(2*N-r) ) % div * mCr(M,r) ) % div * ((r&1)==1?-1:1) ) % div<<"\n";

            total += ( ( ( two[r] * fact[2*N-r] ) % div * mCr(M,r) ) % div * ((r&1)==1?-1:1) ) % div;
            if(total<0){
                total +=div;
            }
            total %= div; 
        }
        cout<<"Case #"<<tc<<": "<<total<<"\n";
    }
    return 0;
}