#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;
#define ll long long
#define imax 1000000000
#define bound 100010
#define div 1000000007

/*
그래프를 받고
노드당 연결된 엣지 수를 배열에 두고
그 배열에 대한 인덱스를 정렬한다.
dp를 이용하여 이전의 연결가능한 노드중 최대 연결을 구함
단순한 dp는 n^2
nlogn으로 어떻게 푸는가
각 노드당 heap을 두어서 이전노드부터 값을 업데이트시키면서 최대값?
공간복잡도는? 512MB
M 최대 30만 => 노드당 연결평균 6개
60만개의 데이터, 10만개의 heap
*/

int nodecnt[bound] = { 0, };
int nodeidx[bound] = { 0, };
int cmp(const void * f, const void * s) {
	int a = nodecnt[*(int*)f];
	int b = nodecnt[*(int*)s];
	return a - b;
}

int main() {
	int N = 0, M = 0;
	cin >> N >> M;
	vector<vector<int> > vi(N);
	vector<priority_queue<int> > vqi(N, priority_queue<int>(1,0));
	int a = 0, b = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		nodecnt[a]++;
		nodecnt[b]++;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		nodeidx[i] = i;
	}

	qsort((void*)nodeidx, (size_t)N, sizeof(int), cmp);
	
	//cout << "nodeidx  nodecnt\n";
	//for (int i = 0; i < N; i++) {	
	//	cout << nodeidx[i] << " " << nodecnt[nodeidx[i]] << "\n";
	//}
	int result = 0;
	for (int i = 0; i < N; i++) {
		int idx = nodeidx[i];
		int bef = vqi[idx].top()+1;
		if (result < bef) {
			result = bef;
		}
		for (int j = 0; j < vi[idx].size(); j++) {
			if(nodecnt[vi[idx][j]] > nodecnt[idx])
				vqi[vi[idx][j]].push(bef);
		}
	}
	

	cout << result << "\n";
	return 0;
}