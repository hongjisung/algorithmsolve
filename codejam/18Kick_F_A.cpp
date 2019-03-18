#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T = 0;
    cin>>T;
    for (int tc = 1; tc <= T; tc++) {
        int L=0;
        cin>>L;
        
        string A="", B="";
        cin>>A>>B;
        
        vector<vector<vector<int> > > dpa(L+1, vector<vector<int> >(L, vector<int>(26, 0)));
        vector<vector<vector<int> > > dpb = dpa;
        
        for(int len=1; len<=L; len++) {
            for(int i=0; i < L; i++) {
                for(int j = i - len + 1; j <= i; j++) {
                    if (j >= 0 && j + len <= L) {
                        dpa[len][j][A[i] - 'A']++;
                        dpb[len][j][B[i] - 'A']++;
                    }
                }
            }
        }
        
        int result = 0;
        for (int len = 1; len<=L; len++) {
            for(int i=0; i<L-len+1; i++) {
                bool find = false;
                for(int i2 = 0; i2<L-len+1; i2++) {
                    bool ok = true;
                    
                    for (int j=0; j<26; j++) {
                        if (dpa[len][i][j] != dpb[len][i2][j]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        find = true;
                        break;
                    }
                }
                
                if (find) {
                    result++;
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<result<<"\n";
    }
    return 0;
}