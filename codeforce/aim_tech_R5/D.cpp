#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
#define div 1000000007
#define ll long long

/*
add x ~ accept x 사이에 있는 add y들은 accept y가 사이에 있지 않다면

1. add x ~ accept x 사이에 안사라지는 add y가  
x < y 면 무조건 sell, x>y 이면 무조건 buy

add x accept x씽이 지워지기 위해서는 이전의 배치 상태를 알아야한다.
이전의 배치 상태에서 x가 위나 아래중 어디로 갈 수 있는지 determine

2. x 이전에 나온 z들 (accept z로 내부에서 사라지지 않는)
은 x보다 크다면 무조건 sell , x보다 작다면 무조건 buy

이렇게 해서 만약 case 충돌이 일어나면 impossible

어떤 값도 할당되지 않는 것들은 buy,sell전부 가능



n이 36만인데 nlogn으로 어떻게 품?

accept가 나왓어 그런데 이전에 add되고 제거되지 않은 것들이
up down인지에 대해 표시를 하고
이 과정을 진행하다가 up down충돌이 일어나는 데이터는 impossible
어떻게 인지?
set을 세개를 유지 nonchecked, upset, downset

그런데 표시를 해야함, buy인지 sell인지

내가 나오고, accept되는데 중간에 다른 accept가 없는 것
add, accept위치로 accept 순서대로 저장한 vector에서 이전 accept의 idx랑 비교



{다른 사람의 풀이를 보고}
마지막에 accept로 체크되지 않는 add는 이전에 쌓여있는 board와 비교해서
buy와 sell 경계 사이의 값이 아니라면 값은 정해지고
경계사이의 값이라면 경우의 수들이 생긴다 
만약 경계 사이의 값이 3개라면
buy abc     sell
buy ab    c sell
buy a    bc sell
buy     abc sell
와 같이 4가지 case가 가능하다 (a<b<c)



set을 세개로 유지하는 것은 시간초과
set을 하나만으로 유지하면서 문제 푸는 방법 
 - accept뒤 그 값의 바로 크고 작은수를 min, max로 체킹하면서 품
*/



int main(){
    int n=0;
    cin>>n;
    
    string str;
    int val;
    set<int> si;
    ll lastadd=1,answer=1;
    ll mx = 400000000, mn=0;
    si.insert(mx); si.insert(mn);
    for(int i=0; i<n; i++){
        cin>>str>>val;
        if(str[1]=='D'){
            si.insert(val);
            if(mx>val && mn<val){
                lastadd++;
            }
        }
        else{
            if(mx<val || mn>val){
                cout<<"0";
                return 0;
            }
            if(mx!=val && mn!=val){
                answer = answer*2%div;
            }
            si.erase(val);
            set<int>::iterator itr = si.lower_bound(val);
            lastadd = 1;
            mx = *itr; mn=*(--itr);
        }
    }

    
    cout<<answer*lastadd%div;
    

    return 0;
}