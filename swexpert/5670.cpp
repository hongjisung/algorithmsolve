#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct lean {
  int hori;
  int verti;

  bool operator==(const lean &le) const {
    return hori == le.hori && verti == le.verti;
  }
};

struct hashkey {
  size_t operator() (const lean& k) const {
    return hash<int>()(k.hori) ^ hash<int>()(k.verti);
  }
};

struct point {
  int x;
  int y;
};

int gcd (int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  }

  while (b > 0) {
    int t = a % b;
    a = b;
    b = t;
  }

  return a;
}

/*
1. 기울기가 같은 점을 처리하는 것
2. 이미 저장된 점에 대해 새로운 점으로 비교할 때 두 점이 달라야 한다.
*/
int main() {
  int T=0;
  cin>>T;
  for (int tc=1; tc<=T; tc++) {
    int G=0, N=0;
    cin>>G>>N;
    /*
    전부 평행한가?
    전부 일치하는가?
    */

    int total = N;
    unordered_map<lean, vector<point> , hashkey> um; 

    for (int i=0; i<N; i++) {
      int x1=0,y1=0,x2=0,y2=0;
      cin>>x1>>y1>>x2>>y2;
      
      int lx = x2 - x1, ly = y2 - y1;
      int gcdl = gcd(abs(lx), abs(ly));
      if (gcdl > 0) {
        lx /= gcdl; ly /= gcdl;
      }
      if (lx < 0 && ly != 0) {
        lx = -lx; ly = -ly;
      } else if (lx == 0) {
        ly = 1;
      } else if (ly == 0) {
        lx = 1;
      }

      if (um.find(lean{lx, ly}) != um.end()) {
        vector<point> vp = um[lean{lx,ly}];
        int ii = 0;
        for ( ; ii<vp.size(); ii++) {
          if (x1 == vp[ii].x && y1 == vp[ii].y) {
            x1 = x2; y1 = y2;
          }
          int llx = vp[ii].x - x1, lly = vp[ii].y - y1;
          int gcdll = gcd(abs(llx), abs(lly));
          if (gcdll > 0) {
            llx /= gcdll; lly /= gcdll;
          }
          if (llx<0 && lly != 0) {
            llx = -llx; lly = -lly;
          } else if (llx == 0) {
            lly = 1;
          } else if (lly == 0) {
            llx = 1;
          }

          if (llx == lx && lly == ly) {
            total--;
            break;
          } 
        }
        if (ii == vp.size()) {
          um[lean{lx, ly}].push_back(point{x1, y1});
        }
      } else {
        um[lean{lx,ly}].push_back(point{x1, y1});
      }
    }

    int result = 0;
    if (um.size() == 1) {
      if (G > total+1) {
        if (G <= (total+1)*2) {
          result = 1;
        } else {
          int suf = (G - (total+1)*2);
          result = 1 + suf/2+ suf%2;
        }
      }
    } else {
      if (G > total*2) {
        int suf = G - (total)*2;
        result = suf/2 + suf%2;
      }
    }

    cout<<"#"<<tc<<" "<<result<<"\n";
  }
  return 0;
}