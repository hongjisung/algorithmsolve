#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// 알파벳 순서대로 for문을 계속 돌면서 지울 수 있는지 없는지 확인하고 지운다.
// 다 지워지면 지운순서대로 return
// 다 못지우면 impossible

void show(vector<string> &board){
    for(int i=0; i<board.size(); i++){
        cout<<board[i]<<"\n";
    }
}

int main(){
    int M=0, N=0;
    cin>>M>>N;
    vector<string> board(M,"");
    set<int> alpha;
    vector<vector<pair<int,int> > > alphaplace(26);

    for(int i=0; i<M;i++){
        cin>>board[i];
        for(int j=0; j<N; j++){
            if(board[i][j]!='*' && board[i][j]!='.'){
                alpha.insert(board[i][j]-'A');
                alphaplace[board[i][j]-'A'].push_back(make_pair(i,j));
            }
        }
    }

    string result="";
    while(!alpha.empty()){
        set<int>::iterator i=alpha.begin();
        for(i; i!=alpha.end(); i++){
            auto p1 = alphaplace[*i][0];
            auto p2 = alphaplace[*i][1];
            int can_del[4]={1,1,1,1};
            int isdel=1;

            int imin = (p1.first>p2.first)?p2.first:p1.first;
            int imax = (p1.first>p2.first)?p1.first:p2.first;
            int jmin = (p1.second>p2.second)?p2.second:p1.second;
            int jmax = (p1.second>p2.second)?p1.second:p2.second;
            for(int i1=imin; i1<=imax; i1++){
                if(!(board[i1][jmin] == '.' || int(board[i1][jmin]-'A') == *i)){
                    can_del[0]=0;
                }
                if(!(board[i1][jmax] == '.' || int(board[i1][jmax]-'A') == *i)){
                    can_del[1]=0;
                }
            }
            for(int j1=jmin; j1<=jmax; j1++){
                if(!(board[imin][j1] == '.' || int(board[imin][j1]-'A') ==*i)){
                    can_del[2]=0;
                }
                if(!(board[imax][j1] == '.' || int(board[imax][j1]-'A') == *i)){
                    can_del[3]=0;
                }
            }
            if(p1.first==p2.first){
                if(can_del[2]==0){
                    isdel=0;
                }
            }
            else if(p1.second == p2.second){
                if(can_del[0] == 0){
                    isdel=0;
                }
            }
            else if(p1.first==imin && p1.second==jmin || p1.first==imax && p1.second==imax){
                if( (can_del[2]==0 || can_del[1]==0) && (can_del[0]==0 || can_del[3]==0)){
                    isdel=0;
                }
            }
            else{
                if( (can_del[2]==0 || can_del[0]==0) && (can_del[1]==0 || can_del[3]==0)){
                    isdel=0;
                }
            }

            if(isdel == 1){
                break;
            }
        }
        if(i!=alpha.end()){
            auto p1 = alphaplace[*i][0];
            auto p2 = alphaplace[*i][1];
            board[p1.first][p1.second] = '.';
            board[p2.first][p2.second]='.';
            result+=char(*i+'A');
            alpha.erase(i);
        }
        else{
            result="IMPOSSIBLE";
            break;
        }
    }


    cout<<result<<"\n";

    return 0;
}

