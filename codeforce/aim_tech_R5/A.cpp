#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n=0,m=0;
    cin>>n>>m;
    vector<string> vs(n,"");
    for(int i=0; i<n; i++){
        cin>>vs[i];
    }
    int r = -1 , c = -1;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++){
            if(vs[i][j] == 'B'){
                if(r==-1){
                    r = i;
                }
                cnt++;
            }
            if(cnt>0 && vs[i][j] == 'W'){
                c = j-1 - (cnt>>1);
                r += (cnt>>1);
                break;
            }
            if(cnt>0 && j == m-1){
                c = j - (cnt>>1);
                r += (cnt>>1);
                break;
            }
        }
        if(r>=0){
            break;
        }
    }
    cout<<r+1<< " "<<c+1;
    return 0;
}