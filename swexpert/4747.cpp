#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
1
12
10 6 2 4 4 4 4 4 4 4 4 4

이거 시간복잡도 계산 어떻게 하는지 모르겠다.
*/
bool dfs(vector<int> &check, vector<int> &value, int step, int upcut, vector<int> &partsum, int pos){
    if(step>=check.size()){
        return false;
    }

    if(check[step] == 0){
        partsum[pos] += value[step];
        check[step] = pos;
        if(partsum[pos] == upcut && (pos==2 || dfs(check, value, 0, upcut, partsum, pos+1))){
            return true;
        }
        if(partsum[pos]<upcut && dfs(check, value, step+1, upcut, partsum, pos)){
            return true;
        }
        partsum[pos] -= value[step];
        check[step] = 0;
    }
    
    return dfs(check, value, step+1, upcut, partsum, pos);
}

int main(){
    int test = 0;
    cin>>test;
    for(int tc=1; tc<=test; tc++){
        int N=0;
        cin>>N;

        vector<int> value(N);
        int totalsum = 0;
        for(int i=0; i<N; i++){
            cin>>value[i];
            totalsum+=value[i];
        }

        int upcut = totalsum/3;

        sort(value.begin(), value.end(), greater<int>());
        vector<int> check(N,0);
        vector<int> partsum(3,0);
        dfs(check, value, 0, upcut, partsum, 1);

        vector<vector<int> > output(3, vector<int>());
        for(int i=0; i<N; i++){
            output[check[i]].push_back(value[i]);
        }        

        cout<<"#"<<tc<<"\n";
        for(int i=0; i<3; i++){
            for(int j=0; j<output[i].size(); j++){
                cout<<output[i][j]<<" ";
            }
            cout<<"\n";
        }


    }
    return 0;
}