#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Point {
  int x;
  int y;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isRange(int x, int y, int n, int m) {
  if (x < 0 || x >= n) {
    return false;
  }
  if (y < 0 || y >= m) {
    return false;
  }
  return true;
}

int main() {
  int n=0, m=0;
  cin>>n>>m;
  vector<vector<int>> map(n, vector<int>(m, 0));
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin>>c;
      map[i][j] = c - '0';
    }
  }

  vector<vector<int>> searched(n, vector<int>(m, 0));
  queue<Point> qu;
  qu.push({0, 0});
  searched[0][0] = 1;
  while (!qu.empty()) {
    Point p = qu.front();
    qu.pop();

    for (int i = 0; i < 4; i++) {
      int newx = p.x + dx[i];
      int newy = p.y + dy[i];
      if (isRange(newx, newy, n, m) && !searched[newx][newy]) {
        if (map[newx][newy] == 1) {
          qu.push({newx, newy});
          searched[newx][newy] = searched[p.x][p.y] + 1;
        }
      }
    }

    if (searched[n-1][m-1]) {
      break;
    }
  }

  cout<<searched[n-1][m-1]<<"\n";
}