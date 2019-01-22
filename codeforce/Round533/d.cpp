#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n=0,m=0,p=0;
  cin>>n>>m>>p;
  
  vector<vector<int> > board(n, vector<int>(m));
  queue<pair<int, int> > qp[10];
  int si[10] ={0,};
  for (int i=0; i<p; i++) {
    cin>>si[i];
  }

  int inqueuecnt = 0;
  for(int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      char c;
      cin>>c;
      board[i][j] = int(c);
      if (board[i][j] != int('.') && board[i][j] != int('#')) {
        qp[board[i][j] - int('1')].push(make_pair(i,j));
        inqueuecnt += 1;
      }
    }
  }

  while (inqueuecnt > 0) {
    inqueuecnt = 0;
    for (int i=0; i<p; i++) {
      for (int step = 1; step <= si[i]; step++) {
        if (qp[i].empty()) {
          break;
        }
        queue<pair<int, int> > qpnew;
        while(!qp[i].empty()) {
          pair<int, int> p = qp[i].front();
          qp[i].pop();
          if (p.first - 1 >=0 && board[p.first - 1][p.second] == int('.')) {
            board[p.first - 1][p.second] = i + int('1');
            qpnew.push(make_pair(p.first-1, p.second));
          }
          if (p.second - 1 >=0 && board[p.first][p.second-1] == int('.')) {
            board[p.first][p.second-1] = i + int('1');
            qpnew.push(make_pair(p.first, p.second-1));
          }
          if (p.first + 1 <n && board[p.first + 1][p.second] == int('.')) {
            board[p.first + 1][p.second] = i + int('1');
            qpnew.push(make_pair(p.first+1, p.second));
          }
          if (p.second + 1 <m && board[p.first][p.second+1] == int('.')) {
            board[p.first][p.second + 1] = i + int('1');
            qpnew.push(make_pair(p.first, p.second+1));
          }
        }
        qp[i] = qpnew;
      }
      inqueuecnt += qp[i].size();
    }
  }

  int cnt[10]= {0,};
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(board[i][j] != int('.') && board[i][j]!=int('#')) {
        cnt[board[i][j] - int('1')] += 1;
      }
    }
  }

  for(int i=0; i<p; i++){
    cout<<cnt[i]<<" ";
  }
  return 0;
}