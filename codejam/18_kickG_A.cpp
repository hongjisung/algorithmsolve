#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
1) O(N*2 log N)
    sort the array,
    for each NC2 cases find the value in array by using binary search
    N = 7000 => 7000 * 7000 * log 7000 * 30(T) = 13014888179 ~= 10^10

    the values can exist many times

2) O(N*2)
    0<=A<=200000 => count array
    make unique set
    make set => n log n
    find value => O(1) : count array
    watch out value 0,1

    N*2인데 속도가 좀 느린듯? => stl?
    7000*7000*30 = 1470000000 ~= 10^9
*/

int main(){
    int T=0;
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        // read data
        int N=0;
        cin>>N;
        vector<long long> arr(200001,0);
        set<long long> si;
        long long a = 0;
        for(int i=0; i<N; i++){
            cin>>a;
            arr[a]++;
            si.insert(a);
        }
        
        // result
        long long result = 0;

        // search
        for(set<long long>::iterator itr1 = si.begin(); itr1!=si.end(); itr1++){
            // case value 0
            if(*itr1 == 0){
                // choose 3 in 0
                if(arr[*itr1]>=3){
                    result += arr[*itr1]*(arr[*itr1]-1)/2*(arr[*itr1]-2)/3;
                }
                // choose 2 in 0 and 1 in others
                if(arr[*itr1]>=2 && (N - arr[*itr1] >=1)){
                    result += arr[*itr1]*(arr[*itr1]-1)/2 * (N-arr[*itr1]);
                }
                // choose 1 in 0 and 2 in others
                // if(N-arr[*itr1]>=2)
                //     result += arr[*itr1] * ((N-arr[*itr1]) * (N-arr[*itr1]-1)/2);
                
                continue;
            }

            // case value 1
            if(*itr1 == 1 && arr[1]>=3){
                // choose 3 in 1
                result += arr[1]*(arr[1]-1)/2*(arr[1]-2)/3;
            }

            // a*a = b
            long long finding = (*itr1)*(*itr1);
            if(arr[*itr1]>=2 && finding != 1 && finding<=200000){
                result += arr[*itr1]*(arr[*itr1]-1)/2 * arr[finding];
            }
            

            set<long long>::iterator itr2 = itr1;
            itr2++;
            for(itr2; itr2!=si.end(); itr2++){
                // case value 1
                if(*itr1 == 1){
                    if(arr[*itr2]>=2){
                        // choose 1 in 1 and 2 in other
                        result += arr[1] * (arr[*itr2]*(arr[*itr2]-1)/2);
                    }
                    continue;
                }

                // case no value 0,1
                long long finding = (*itr1) * (*itr2);
                if(finding<=200000){
                    result += arr[*itr1]*arr[*itr2]*arr[finding];
                }
            }
        }


        cout<<"Case #"<<tc<<": "<<result<<"\n";
    }
    return 0;
}