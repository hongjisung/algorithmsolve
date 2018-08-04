#include <iostream>
#include <string>
#include <vector>
using namespace std;

// a에서 b까지의 경로는 그 사이의 시간차만큼의 경로수 이하로 갈 수 있다면 가능하다
// 플로이드 워샬 알고리즘?
// 모든 두 점의 최단 경로 쌍을 구하고 그 사이의 시간차가 구한 최단경로보다 큰 지 구한다.
// 시간차가 작다면 갈 수 없으나 크거나 같으면 무조건 갈 수 있다.


/*
7 10
[[1, 2], [1, 3], [2, 3], [2, 4], [3, 4], [3, 5], [4, 6], [5, 6], [5, 7], [6, 7]]
6
[1, 2, 3, 3, 6, 7]

7 10
[[1, 2], [1, 3], [2, 3], [2, 4], [3, 4], [3, 5], [4, 6], [5, 6], [5, 7], [6, 7]]
6
[1, 2, 4, 6, 5, 7]

*/

void floyd_warshall(vector<vector<int> > &road) {
	int n = road.size();
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (road[i][k] + road[k][j] < road[i][j]) {
					road[i][j] = road[i][k] + road[k][j];
				}
			}
		}
	}
}


/*
log
1 2 3 3 4 6
edge
1 0 1 0 1
*/

int mincount(vector<vector<int> > &road, vector<int> &gps) {
	int time = gps.size();
	if (road[gps[0]][gps[time - 1]] > time - 1) {
		return -1;
	}
	
	vector<vector<int> > dp(time, vector<int>(time, 0));
	for(int i=1; i<time; i++){
		for (int j = 0; j < time-i; j++) {
			// j to j+i
			int mincng = INT_MAX/4;
			for (int k = j + 1; k < j + i; k++) {
				int temp = dp[k - j][j] + dp[j + i - k][k];
				if (temp < mincng) {
					mincng = temp;
				}
			}
			if (mincng < i) {
				dp[i][j] = mincng;
			}
			else {
				if (road[gps[j]][gps[j + i]] <= i) {
					dp[i][j] = i - 1;
				}
				else {
					dp[i][j] = INT_MAX/4;
				}
			}
		}
	}
	
	return dp[time-1][0];
}


int main222() {
	int N = 0, M = 0;
	cin >> N >> M;
	string edge_list = "";
	getline(cin, edge_list); // 빈줄
	getline(cin, edge_list);
	int K = 0;
	cin >> K;
	string gps_log;
	getline(cin, gps_log); //빈줄
	getline(cin, gps_log);
	// graph , 커봐야 N-1번
	vector<vector<int> > road(N, vector<int>(N, INT_MAX/3));
	for (int i = 0; i < N; i++) {
		road[i][i] = 0;
	}
	vector<int> gps;

	int a = 0;
	int b = 0;
	int comma = 0;
	// make road
	for (int i = 0; i < edge_list.size(); i++) {
		if (edge_list[i] >= '0' && edge_list[i] <= '9') {
			if (comma==1) {
				b = b*10 + int(edge_list[i]) - 48;
			}
			else {
				a = a*10 + int(edge_list[i]) - 48;
			}
		}
		else if (edge_list[i] == ',' && comma==0) {
			comma = 1;
		}
		else if(edge_list[i]==',' && comma==1){
			road[a-1][b-1] = 1;
			road[b-1][a-1] = 1;
			a = 0;
			b = 0;
			comma = 0;
		}
	}
	road[a - 1][b - 1] = 1;
	road[b - 1][a - 1] = 1;
	a = 0;
	b = 0;
	comma = 0;


	// make gps
	comma = 1;
	for (int i = 0; i < gps_log.size(); i++) {
		if (gps_log[i] >= '0' && gps_log[i] <= '9') {
			if (comma == 1) {
				gps.push_back(int(gps_log[i]) - 48);
				comma = 0;
			}
			else {
				gps[gps.size() - 1] = gps[gps.size() - 1] * 10 + int(gps_log[i]) - 48;
			}
		}
		if (gps_log[i] == ',') {
			gps[gps.size() - 1]--;
			comma = 1;
		}
	}
	gps[gps.size() - 1]--;

	floyd_warshall(road);
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << road[i][j] << " ";
		}
		cout << "\n";
	}*/

	int min = mincount(road, gps);

	cout << min << "\n";
	cin >> N;
	return 0;
}