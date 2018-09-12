#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long

/*
    a1 ... an
    b1 ... bn

    bi = ai mod ai+1
    ai = bi + (ai+1)*k

    두 개일 때
    a1 = b1 + a2*k1
    a2 = b2 + a1*k2

    

    결국 양수라면, 크기 순서가 있을 것이다.
    뒤에거보다 작은 놈은 그대로이다.
    뒤에거보다 큰놈은 뒤에것으로 나눈 나머지이다.

    모두 같은 수 일 때 불가능
    a<b 인 시점을 하나 잡고
    거기서 부터 앞으로 나가면서
    a = a+b로 변화시키면서 구해보자
    만약 c>k인 시점이 온다면, k가 c보다 크도록 a +b*alpha를 하자
*/


int main(){
    int n=0;
    cin>>n;
    vector<ll> vl(n,0);
    bool check = true;
    int start = -1;

    scanf("%d", &vl[0]);
    for(int i=1; i<n; i++){
        scanf("%d", &vl[i]);
        if(check && vl[i-1] < vl[i]){
            check = false;
            start = i;
        }
    }
    
    if(check && vl[n-1] < vl[0]){
        check = false;
        start = 0;
    }

    if(check && vl[0] == 0){
        cout<<"YES\n";
        for(int i=0; i<n; i++){
            printf("%d ", 1);
        }
        return 0;
    }

    if(check){
        cout<<"NO";
        return 0;
    }

    ll now = (start + n- 1)%n;
    ll mul = 190000/vl[start] + ( (190000%vl[start] > 0) ? 1 : 0);
    vl[now] = vl[start] * mul +vl[now];
    while(now!= start){
        ll next = (now+n-1)%n;
        if(next == start){
            break;
        }
        vl[next] = vl[next] + vl[now];
        now = next;
    }

    cout<<"YES\n";
    for(int i=0; i<n; i++){
        printf("%lld ", vl[i]);
    }

    return 0;
}