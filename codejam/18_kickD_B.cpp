#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long


/*
    정렬한 뒤 겹치는 부분을 제거하면
    풍선의 앞뒤 기둥만 살펴보면 된다는 사실..
    겹치는 부분 제거는 stack으로 할 수 있다.
*/
struct flag{
    ll x;
    ll y;
};

struct ballon{
    ll x;
    ll y;
};

bool operator<(flag a, flag b){
    return a.x<b.x;
}

int main(){
    int T=0;
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        int N=0,K=0;
        int bigone = (N>K)?N:K;
        cin>>N>>K;
        vector<vector<long long> > data(4);
        data[0] = vector<long long>(N,0);
        data[1] = vector<long long>(N,0);
        data[2] = vector<long long>(K,0);
        data[3] = vector<long long>(K,0);
        for(int i=0; i<4; i++){
            long long d1,d2,a,b,c,m;
            cin>>d1>>d2>>a>>b>>c>>m;
            data[i][0] = d1;
            data[i][1] = d2;
            for(int j=2; j<data[i].size(); j++){
                data[i][j] = (a*data[i][j-1] + b*data[i][j-2] + c)%m+1;
            }
        }



        int result = 0;
        // small dataset
        // for(int i=0; i<K; i++){
        //     int ru = data[2][i] - data[3][i];
        //     int rd = data[2][i] + data[3][i];
        //     for(int j=0; j<N; j++){
        //         int cu = data[0][j] - data[1][j];
        //         int cd = data[0][j] + data[1][j];
        //         if(data[2][i] <= data[0][j]){
        //             if(ru >= cu){
        //                 result++;
        //                 break;
        //             }
        //         }
        //         else{
        //             if(rd<=cd){
        //                 result++;
        //                 break;
        //             }
        //         }
        //     }
        // }        

        // large dataset
        vector<flag> vf;
        for(int i=0; i<N; i++){
            flag f;
            f.x = data[0][i]; f.y = data[1][i];
            vf.push_back(f);
        }
        sort(vf.begin(), vf.end());

        vector<ballon> vb;
        for(int i=0; i<K; i++){
            ballon b;
            b.x = data[2][i]; b.y = data[3][i];
            vb.push_back(b);
        }

        vector<flag> reflag;
        for(int i=0; i<N; i++){
            flag f = vf[i];
            while(reflag.size()>0){
                flag f2 = reflag[reflag.size()-1];
                if(f2.x+f2.y >= f.x+f.y){
                    break;
                }
                else if(f2.x-f2.y >= f.x-f.y){
                    reflag.pop_back();
                }
                else{
                    reflag.push_back(f);
                    break;
                }
            }
            
            if(reflag.size()==0){
                reflag.push_back(f);

            }            
        }


        for(int i=0; i<K; i++){
            ballon b = vb[i];
            int start = 0, end = reflag.size()-1;
            while(end-start>1){
                int mid = (start+end)/2;
                if(reflag[mid].x <= b.x) start = mid;
                else{
                    end = mid;
                }
            }
            

            end = reflag.size()-1;
            if(reflag[end].x <= b.x){
                if(b.x+b.y <= reflag[end].x+reflag[end].y){
                    result++;
                }
            }
            else if(reflag[0].x > b.x){
                if(b.x-b.y >= reflag[0].x-reflag[0].y){
                    result++;
                }
            }
            else{
                if(b.x+b.y<=reflag[start].x+reflag[start].y || b.x-b.y>=reflag[start+1].x-reflag[start+1].y){
                    result++;
                }
            }
        }


        cout<<"Case #"<<tc<<": "<<result<<"\n";
    }

    return 0;
}