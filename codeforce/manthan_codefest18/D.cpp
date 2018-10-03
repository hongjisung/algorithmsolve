#include <stdio.h>
#include <vector>
using namespace std;



int main(){
    int n=0;
    scanf("%d", &n);
    vector<vector<int> > vi(n+1);
    int a=0,b=0;
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &a,&b);
        vi[a].push_back(b);
        vi[b].push_back(a);
    }

    // 받을 때마다 다음 꺼 순서 체크
    vector<int> level(n+1,0);
    level[1]=1;

    int seq=2, now = 1,in;
    for(int i=0; i<n; i++){
        scanf("%d", &in);
        if(level[in] == 0 || level[in] < now){
            printf("No");
            return 0;
        }
        now = level[in];
        for(int d : vi[in]){
            level[d] = seq;
        }
        seq++;
    }
    printf("Yes");

    return 0;
}