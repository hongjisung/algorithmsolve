#include <iostream>
#include <stdio.h>
using namespace std;

int cmp(const void * a, const void * b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n=0,s=0;
    cin>>n>>s;
    int * arr = new int[n];
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }

    qsort((void*)arr, (size_t)(n), sizeof(int), cmp);

    long long result = 0;
    if(arr[n/2] < s){
        for(int i=n/2; i<n; i++){
            if(arr[i]>=s){
                break;
            }
            result += (long long)(s - arr[i]);
        }
    }
    else{
        for(int i=n/2; i>=0; i--){
            if(arr[i]<=s){
                break;
            }
            result +=(long long)(arr[i]-s);
        }
    }

    cout<<result;
    return 0;
}