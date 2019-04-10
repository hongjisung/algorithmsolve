#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll countNum(vector<ll> table, ll m) {
  ll result = 0;
  for (ll t : table) {
    result += m/t;
  }
  return result;
}

int main() {
  int T=0;
  cin>>T;
  
  for (int tc=1; tc<=T; tc++) {
    ll N=0, M=0;
    cin>>N>>M;
    vector<ll> table(N);
    ll largest = 0;
    for (int i=0; i<N; i++) {
      cin>>table[i];
      if(table[i] > largest) {
        largest = table[i];
      }
    }

    ll start = 0, end = largest*M+1;
    while(start + 1 < end) {
      ll m = start+end>>1;
      
      ll num = countNum(table, m);
      if(num >= M) {
        end = m;
      } else {
        start = m;
      }
    }


    cout<<"#"<<tc<<" "<<end<<"\n";
  }
  
  return 0;
}