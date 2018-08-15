#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
	int N=0,K=0;
	cin>>N>>K;
	vector<int> arr(N,0);
	for(int i=0; i<N; i++){
		cin>>arr[i];
	}

    vector<int> dp(N,INT_MAX/2);
    for(int i=0; i<N; i++){
        int plant = -1;

		int min = 0;
		int minidx = -1;
        for(int j=i; j>i-K; j--){
            if(j<0){
                break;
            }
            if(arr[j]==0){
                continue;
            }
            int temp = INT_MAX/2;
			if(j-K<0){
                temp = 0;
            }
			else{
				if(minidx>=j-K && minidx<j){
					temp = min;
					if(dp[j-K] < min){
						temp = dp[j-K];
						min = temp;
						minidx = j-K;
					}
				}
				else{
	            	for(int t = j-K; t<j; t++){
    	        	    if(t<0){
        		            continue;
    	    	        }
	            	    if(dp[t]<temp){
            	    	    temp = dp[t];
							min = temp;
							minidx = t;
        	            	break;
    	            	}
	            	}
				}
            }
            
            if(temp < dp[i]){
                dp[i] = 1+temp;
                plant = j;
            }
        }
        if(plant>=0){
            for(int j=i+1; j<plant+K; j++){
                if(j>=N){
                    break;
                }
                dp[j] = dp[i];
            }
            i = plant+K-1;
        }
    }
    if(dp[N-1]==INT_MAX/2){
        dp[N-1]=-1;
    }

	cout<<dp[N-1]<<"\n";

	return 0;
}
