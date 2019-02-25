#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct node {
  bool exist = false;
  unordered_map<char, node*> um;
};

node trie;
vector<string> board;
vector<vector<bool> > visited;
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool rangein(int x, int y) {
  if (x>=0 && x<4 && y>=0 && y<4 && visited[x][y] == false) {
    return true;
  }
  return false;
}

void find_word(int r, int c, int step, node * n, string now, unordered_map<string, bool> &um, int &total,int &cnt,string &longmin) {
  // 최대길이 8
  if (step > 8) {
    return;
  }

  // 단어 tree가 더 없으면 종료
  if((*n).um[board[r][c]] == 0) {
    return;
  }

  // 단어 문자 추가
  now += board[r][c];
  visited[r][c] = true;

  // 단어가 있으면 추가.
  if ( (*(*n).um[board[r][c]]).exist == true ) {
    // 이미 찾은 단어가 아니어야 추가
    if (um[now] == false) {
      um[now] = true;
      if (now.size()==3 || now.size()==4) {
        total += 1;
      } else if (now.size()==5) {
        total += 2;
      } else if (now.size()==6) {
        total += 3;
      } else if (now.size()==7) {
        total += 5;
      } else if (now.size()==8) {
        total += 11;
      }

      cnt += 1;
      if (longmin.size() == now.size() && now < longmin) {
        longmin = now;
      } else if(longmin.size() < now.size()) {
        longmin = now;
      }
    }
  }

  for (int i=0; i<8; i++) {
    int nextr = r+dx[i], nextc = c+dy[i];
    if (rangein(nextr, nextc)) {
      find_word(nextr, nextc, step+1, (*n).um[board[r][c]], now, um, total, cnt, longmin);
    }
  }
  visited[r][c]=false;
}

int main() {
  int w = 0;
  cin>>w;
  
  for (int i=0; i<w; i++) {
    string str;
    cin>>str;

    node* n = &trie;
    for (int i=0; i<str.size(); i++) {
      if ((*n).um[str[i]] == 0) {
        (*n).um[str[i]] = new node();
      }
      if (i == str.size() - 1) {
        (*(*n).um[str[i]]).exist = true;
      }
      n = (*n).um[str[i]];
    }
  }

  int b = 0;
  cin>>b;
  for (int i=0; i<b; i++) {
    board = vector<string>(4);
    
    for(int j=0; j<4; j++) {
      string str = "";
      while (str=="") {
        cin>>str;
      }
      board[j] = str;
    }

    unordered_map<string, bool> um;
    int total=0, cnt=0;
    string longmin="";
    for(int r=0; r<4; r++) {
      for(int c=0; c<4; c++) {
        visited = vector<vector<bool> >(4, vector<bool>(4, false));
        find_word(r, c, 1, &trie, "", um, total, cnt, longmin);
      }
    }

    cout<<total<<" "<<longmin<<" "<<cnt<<"\n";
  }
  return 0;
}