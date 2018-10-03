#include <iostream>
#include <string>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    string a="",b="";
    cin>>a>>b;
    
    int i=0, cnt=0;
    for(i; i<n-1; i++){
        if(a[i]==b[i]){
            continue;
        }
        if(a[i+1]!=b[i+1] && a[i]!=a[i+1]){
            cnt++;
            i++;
        }    
        else{
            cnt++;
        }
    }
    if(i==n-1){
        if(a[n-1]!=b[n-1]){
            cnt++;
        }
    }

    cout<<cnt;
    return 0;
}