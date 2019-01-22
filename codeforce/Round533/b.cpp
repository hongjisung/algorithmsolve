#include <string>
#include <iostream>
using namespace std;

int main(){
  int n=0,k=0;
  cin>>n>>k;
  string s = "";
  cin>>s;
  
  int cnt[30] = {0,};
  int len = 1;
  if (k==1) {
    cnt[int(s[0]) - int('a')] += 1;
    len = 0;
  }
  for(int i=1; i<n; i++){
    if (len>0 && s[i-1] == s[i]) {
      len += 1;
    } else {
      len = 1;
    }
    if (len == k) {
      cnt[int(s[i]) - int('a')] += 1;
      len = 0;
    }
  }

  int max = 0;
  for (int i=0; i<30; i++) {
    if (cnt[i] > max) {
      max = cnt[i];
    }
  }

  cout<<max;
  return 0;
}