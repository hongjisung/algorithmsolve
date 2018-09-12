#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n=0,m=0;
    cin>>n>>m;
    
    int len = (n-5)/9;
    if( (n-5)%9>0){
        len+=1;
    }

    string first ="";
    string second = "";
    for(int i=0; i<len*2; i++){
        if((i&1)==0){
            first+="4";
            second+="5";
        }
        else{
            first+="5";
            second+="4";
        }
    }
    first+="5";
    second+="5";

    cout<<first<<"\n"<<second;
    return 0;
}