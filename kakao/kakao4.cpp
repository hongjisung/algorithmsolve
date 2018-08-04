#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/*
���ͽ�Ʈ�� �����ε� �ּҰ�η� ����
�׷��� �ּҰ�θ鼭 �ּҺ��
�ּҰ���ε� s�� �Ѵ� ����� �Ұ���
������ �� �� ���� ��
�׷����� ������
���

3 3 150
[[0, 2, 99], [100, 100, 4], [1, 2, 0]]
4 6 25
[[0, 1, 1, -1, 2, 4], [-1, 7, 2, 1, 5, 7],[-1, 1, -1, 1, 6, 3], [-1, 1, -1, -1, 7, 0]]
5 5 12
[[0, 1, 1, 1, 1], [9, 9, 9, 1, 9], [1, 1, 1, 1, 9],[1, 1, 5, 9, 9], [1, 1, 1, 1, 0]]

01111
99919
11119
11599
11110

*/

struct root{
    int next;
    int nodecnt;
    long long talktime;
};

bool operator<(root r1, root r2){
    if(r1.nodecnt < r2.nodecnt){
        return false;
    }
    if(r1.nodecnt==r2.nodecnt){
        if(r1.talktime<r2.talktime){
            return false;
        }
    }
    return true;
}

pair<int,int> dijkstra(vector<vector<pair<int, int> > > graph, int start, int end, int s){
    // �ּҰ�� �ּҺ�� �ٵ� s�ʰ��ϸ� �ȵ�
    // �ΰ��� �� �����ϰ� ��ΰ� �ּ��̸鼭 ��뵵 �ּ��̴�
    // �׸��� ���� ����� s�ʰ��ϸ� �̵� �Ұ����̴�.
    vector<root> visited(graph.size(), {-1,-1,-1});
    priority_queue<root> pq;

    visited[start]={0,0,0};
    for(int i=0; i<graph[start].size(); i++){
        root r;
        r.next = graph[start][i].first;
        r.nodecnt = 1;
        r.talktime = graph[start][i].second;
        pq.push(r);
    }

    while(!pq.empty()){
        root r = pq.top();
        pq.pop();
        if(visited[r.next].talktime !=-1 && visited[r.next].talktime < r.talktime){
            continue;
        }

        visited[r.next] = r;
        if(r.next==end){
            break;
        }

        for(int i=0; i<graph[r.next].size(); i++){
            root nr;
            nr.next=graph[r.next][i].first;
            nr.nodecnt = r.nodecnt+1;
            nr.talktime = r.talktime+graph[r.next][i].second;
            if(nr.talktime<=s){
                pq.push(nr);
            }
        }
    }

    
    return make_pair(visited[end].nodecnt,visited[end].talktime);
}

void show(vector<vector<int> > &timemap){
    for(int i=0; i<timemap.size(); i++){
        for(int j=0; j<timemap[i].size(); j++){
            cout<<timemap[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int M=0, N=0, S=0;
    cin>>M>>N>>S;
    string str = "";
    getline(cin,str);
    getline(cin,str);
    vector<vector<int> > timemap(M,vector<int>(N,0));
    vector<vector<pair<int, int> > > graph(M*N);

    int row=0;
    int col=0;
    int minus=0;

    for(int i=0; i<str.size(); i++){
        // cout<<row<<", "<<col<<"\n";
        if(row==38 && col==0){
            show(timemap);
        }
        if(str[i]=='-'){
            minus=1;
        }
        if(str[i]>='0' && str[i]<='9'){
            int t = str[i]-'0';
            for(int j=i+1; j<str.size(); j++){
                if(str[j]<'0' || str[j]>'9'){
                    i=j;
                    break; 
                }
                t = t*10+str[j]-'0';
            }
            if(minus==1){
                t = -t;
            }
            timemap[row][col]=t;
            col++;
            if(col==N){
                row++;
                col=0;
            }

            minus=0;
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(timemap[i][j]<0){
                continue;
            }
            int gn = i*N+j;
            int up = (i-1)*N+j, down = (i+1)*N+j, right=i*N+j+1,left=i*N+j-1;
            if(up>=0 && timemap[i-1][j]>=0){
                graph[gn].push_back(make_pair(up,timemap[i-1][j]));
            }
            if(down<M*N && timemap[i+1][j]>=0){
                graph[gn].push_back(make_pair(down,timemap[i+1][j]));
            }
            if(j<N-1 && timemap[i][j+1]>=0){
                graph[gn].push_back(make_pair(right,timemap[i][j+1]));
            }
            if(j>0 && timemap[i][j-1]>=0){
                graph[gn].push_back(make_pair(left,timemap[i][j-1]));
            }
        }
    }

    pair<int,int> result=dijkstra(graph,0,M*N-1,S);

    cout<<result.first<<", "<<result.second<<"\n";

    return 0;
}