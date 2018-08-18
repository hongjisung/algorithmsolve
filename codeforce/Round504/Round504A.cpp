#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
    int n=0,m=0;
    cin>>n>>m;
    string s="", t="";
    cin>>s>>t;
    bool isstar=false;
    int front = 0, end = m-1;
    int i=0;
    for(i; i<n; i++){
        if(s[i]=='*'){
            isstar = true;
            break;
        }
        if(s[i] != t[front]){
            break;
        }
        else{
            front++;
        }
    }
    int j=n-1;
    for(j; j>=i; j--){
        if(s[j]!=t[end]){
            break;
        }
        else{
            end--;
            
        }
    }

    if(isstar){
        if(i==j && front-1 <=end){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
    else{
        if(i==n && front == m){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
    
    
    return 0;
}