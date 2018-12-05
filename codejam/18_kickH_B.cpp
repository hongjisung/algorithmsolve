#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int T=0;
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        int N=0;
        string wall="";
        cin>>N>>wall;
        
        vector<int> partsum(N+1,0);
        for(int i=0; i<N; i++){
            partsum[i+1] = partsum[i]+ (int)(wall[i]) - (int)('0');
        }

        int paintmax = N/2 + ((N&1)==1?1:0);
        int result = 0;
        for(int i=paintmax; i<=N; i++){
            if(result < partsum[i] - partsum[i-paintmax]){
                result = partsum[i] - partsum[i-paintmax];
            }
        }
        cout<<"Case #"<<tc<<": "<<result<<"\n";
    }
    return 0;
}