#include <iostream>
using namespace std;
#define div 1000000007
#define ll long long

int main() {
  ll n=0, l=0, r=0;
  cin>>n>>l>>r;
  ll divcnt[3] = {r/3 - (l-1)/3, r/3 + (r%3 == 0?0:1) - (l-1)/3 - ((l-1)%3 == 0?0:1), r/3 + (r%3 == 2?1:0) - (l-1)/3 - ((l-1)%3 == 2?1:0)};
  ll** dp = new ll*[200000];
  for(int i=0; i<n; i++){
    dp[i] = new ll[3]{0,};
  }
  dp[0][0] = divcnt[0];
  dp[0][1] = divcnt[1];
  dp[0][2] = divcnt[2];

  for (int i=1; i<n; i++) {
    dp[i][0] = (dp[i-1][0] * divcnt[0] + dp[i-1][1] * divcnt[2] + dp[i-1][2] * divcnt[1] ) % div;
    dp[i][1] = (dp[i-1][0] * divcnt[1] + dp[i-1][1] * divcnt[0] + dp[i-1][2] * divcnt[2] ) % div;
    dp[i][2] = (dp[i-1][0] * divcnt[2] + dp[i-1][1] * divcnt[1] + dp[i-1][2] * divcnt[0] ) % div;
  }

  cout<<dp[n-1][0];
  return 0;
}