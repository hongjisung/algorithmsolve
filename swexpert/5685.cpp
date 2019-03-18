#include <iostream>
#include <vector>
using namespace std;
#define mod 1234567891
#define ll long long

int main() {
  int T=0;
  cin>>T;
  for(int tc=1; tc<=T; tc++) {
    int N=0;
    cin>>N;
    vector<int> vi(N,0);
    for (int i=0; i<N; i++) {
      cin>>vi[i];
    }

    vector<vector<ll> > dp(N-1, vector<ll>(21,0));
    dp[0][vi[0]] = 1;
    for (int i=1; i<N-1; i++) {
      for (int j=0; j<21; j++) {
        int a = j - vi[i], b = j + vi[i];
        if (a >= 0) {
          dp[i][j] = (dp[i][j]+dp[i-1][a]) % mod;
        }
        if (b < 21) {
          dp[i][j] = (dp[i][j]+dp[i-1][b]) % mod;
        }
      }
    }

    cout<<"#"<<tc<<" "<<dp[N-2][vi[N-1]]<<"\n";
  }
  return 0;
}