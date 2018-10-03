#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

/*
최대 200000
k - clique 
k choose 2 = k*(k+1)/2개의 연결이 있어야 함
m >= k*(k+1)/2
m이 최대 200000이면 k는 최대 600~700

--- 
다른 사람 풀이 봄
일단 데이터를 다 받고
주어진 조건에 맞는 즉 모든 점들에 대해 k개 이상의 다른 연결된 점이 모두 trip상태
인 경우를 구함

그 다음 거꾸로 edge를 제거해나가면서
위 상태에 해당하지 않는 점들을 제거해나간다.

*/
#define N 200100
int n,m,k,cnt, x[N], y[N], ans[N]={0,}, num[N]={0,}, del[N]={0,};
set<int> si[N];

void delval(int i){
    if(num[i]>=k || del[i]){
        return;
    }
    queue<int> q;
    q.push(i);
    del[i] = 1;
    cnt--;

    while(!q.empty()){
        int d = q.front();
        q.pop();
        for(int c : si[d]){
            num[c]--;
            if(num[c]<k && !del[c]){
                q.push(c);
                del[c] = 1;
                cnt--;
            }
        }
    }

}

int main(){
    scanf("%d %d %d", &n,&m,&k);
    for(int i=0; i<m; i++){
        scanf("%d %d", x+i,y+i);
        si[x[i]].insert(y[i]);
        si[y[i]].insert(x[i]);
        num[x[i]]++;
        num[y[i]]++;
    }
    
    cnt=n;
    for(int i=1; i<=n;i++){
        delval(i);
    }
    ans[m] = cnt;

    for(int i=m-1; i>0; i--){
        if(!del[x[i]]){
            num[y[i]]--;
        }
        if(!del[y[i]]){
            num[x[i]]--;
        }
        si[x[i]].erase(y[i]);
        si[y[i]].erase(x[i]);
        delval(x[i]);
        delval(y[i]);
        ans[i] = cnt;
    }

    for(int i=1; i<=m; i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}