#include <iostream>
#include <string>
#include <stdio.h>
#include <deque>
using namespace std;
#define ll long long

int main(){
    int n=0,k=0;
    cin>>n>>k;
    string str;
    cin>>str;
    
    string newstr;
    int left = n;

    deque<char> vc;
    for(int i=0; i<n; i++){
        if(str[i]=='('){
            vc.push_back(str[i]);
        }
        else if(left>k){
            vc.pop_back();
            left-=2;
        }
        else{
            vc.push_back(str[i]);
        }
    }

    while(!vc.empty()){
        printf("%c", vc.front());
        vc.pop_front();
    }
    

    return 0;
}