#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define mod 1000000007

/*
Equal to 2018 kickstart roundC, C
*/

ll euclid(ll b, ll n = mod) {
  if (b == 1) {
    return 1;
  }

  ll f[3] = {1,0,b};
  ll s[3] = {0,1,n};
  while (s[2] != 1) {
    ll k = f[2]/s[2];
    ll t[3] = {f[0] - (s[0] * k) % mod, f[1] - s[1]*k % mod, f[2] - k * s[2]};
    f[0] = s[0]; f[1] = s[1]; f[2] = s[2];
    s[0] = t[0]; s[1]=t[1]; s[2]=t[2];
  }

  return (s[0]+n) % n;
}

ll exp(ll n, ll p) {
  ll arr[20] = {n,};
  for(int i=1; i<20; i++) {
    arr[i] = arr[i-1]*arr[i-1] % mod;
  }

  int i = 0;
  ll result = 1;
  while (p != 0) {
    if (p%2) {
      result = result * arr[i] % mod;
    }
    i += 1;
    p >>= 1;
  }

  return result;
}

int main() {
  int T = 0;
  cin>>T;
  for (int tc=1; tc<=T; tc++) {
    ll N=0, K=0, x1=0, y1=0, C=0, D=0, E1=0, E2=0, F=0;
    cin>>N>>K>>x1>>y1>>C>>D>>E1>>E2>>F;
    vector<ll> A(1, (x1+y1) % F);
    for (int i=0; i<N-1; i++) {
      ll temp = x1;
      x1 = (C * x1 + D * y1 + E1) % F;
      y1 = (D * temp + C * y1 + E2) % F;
      A.push_back((x1+y1) % F);
    }

    vector<ll> totsum(1, K);
    for (int i = 2; i <= N; i++) {
      ll up = exp(i, K+1) - 1;
      ll down = euclid(i-1);
      totsum.push_back( (up*down-1+totsum[i-2]) % mod);
    }

    ll result = 0;
    for (int i=0; i < N; i++) {
      result += (A[i]*(N-i) % mod) * totsum[i] % mod;
    }

    cout<<"Case #"<<tc<<": "<< result % mod <<"\n";
  }
  return 0;
}