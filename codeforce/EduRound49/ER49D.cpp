#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
#define ll long long

int main(){
    int N=0;
    cin>>N;
    vector<int> C(N,0);
    vector<int> A(N,0);
    for(int i=0; i<N; i++){
        scanf("%d", &C[i]);
    }
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
        A[i]--;
    }

    int result = 0;
    vector<int> visited(N,-1);
    for(int i=0; i<N; i++){
        if(visited[i]>=0){
            continue;
        }
        // this round i saved in visited;
        int ti = i;
        while(visited[A[ti]]<0){
            visited[ti] = i;
            ti = A[ti];
        }
        // if find loop this time
        if(visited[A[ti]] == i){
            int minval = C[ti];
            int temp = ti;
            ti = A[ti];
            while(ti != temp){
                if(C[ti]<minval){
                    minval = C[ti];
                }
                ti = A[ti];
            }
            result+=minval;
        }
    }

    cout<<result<<"\n";

    return 0;
}