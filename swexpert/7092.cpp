#include <iostream>
#include <algorithm>
using namespace std;

char ans[3][30000];

int main() {
  int T=0;
  cin>>T;
  for(int tc=1; tc<=T; tc++) {
    int N=0;
    cin>>N;
    for(int i=0; i<3; i++) {
      for(int j=0; j<N; j++) {
        cin>>ans[i][j];
      }
    }

    int anscase[5]={0,0,0,0,0};
    for(int j=0; j<N; j++) {
      if(ans[0][j] == ans[1][j] && ans[0][j] == ans[2][j]) {
        anscase[0]++;
      } else if (ans[0][j] == ans[1][j]) {
        anscase[1]++;
      } else if (ans[0][j] == ans[2][j]) {
        anscase[2]++;
      } else if (ans[1][j] == ans[2][j]) {
        anscase[3]++;
      } else {
        anscase[4]++;
      }
    }

    int score = anscase[0];

    int min3 = min(anscase[1], min(anscase[2], anscase[3]));
    score += min3*2;
    
    int left2 = min3 * (-3);
    for(int i=1; i<=3; i++) {
      left2 += anscase[i];
    }
    
    int minlast = min(left2, anscase[4]);
    score += minlast;
    
    left2 -= minlast;
    anscase[4] -= minlast;
    score += left2/2 + anscase[4]/3;

    cout<<"#"<<tc<<" "<<score<<"\n";
  }
  return 0;
}