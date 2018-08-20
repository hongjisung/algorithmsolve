#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main(){
    int T=0;
    cin>>T;
    
    for(int tc=1; tc<=T; tc++){
        int N=0;
        cin>>N;
        string str="";
        cin>>str;
        bool pal=true;
        for(int i=0; i<N/2; i++){
            if(abs(int(str[i]-str[N-1-i]))!=2 && abs(int(str[i]-str[N-1-i]))!=0){
                pal=false;
                break;
            }
        }

        if(pal){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";

        }

    }
    return 0;
}