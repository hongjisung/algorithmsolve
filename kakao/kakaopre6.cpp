#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

/*
8
3 1 5 7 8 7 2 3 3 6 1 5 4 3
9
1 5 5 6 3 7 3 1 7 4 7 2 9 8 5 9


8
[[3, 1], [5, 7], [8, 7], [2, 3], [3, 6], [1, 5], [4, 3]]
9
[[1, 5], [5, 6], [3, 7], [3, 1], [7, 4], [7, 2], [9, 8], [5, 9]]


*/

void delnottree(vector<vector<int> > &G, int parent) {
	for (int i = 0; i < G[parent].size(); i++) {
		int next = G[parent][i];
		auto del = find(G[next].begin(), G[next].end(), parent);
		G[next].erase(del);
		delnottree(G, next);
	}
}

int shortest_path_faster_algorithm(vector<vector<pair<int, int> > > &spfa, int s, int &result) {
	vector<int> d(spfa.size(), INT_MAX);
	vector<int> b(spfa.size(), -1);
	d[0] = 0;

	queue<int > q;
	q.push(s);
	b[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < spfa[u].size(); i++) {
			int v = spfa[u][i].first;
			if (d[u] + spfa[u][i].second < d[v]) {
				d[v] = d[u] + spfa[u][i].second;
				if (b[v] == -1) {
					b[v] = u;
					q.push(v);
				}
			}
		}
	}

	if (d[spfa.size() - 1] == INT_MAX) {
		return 0;
	}

	int start = spfa.size() - 1;
	result += d[start];
	while (start != 0) {
		int next = b[start];
		for (int i = 0; i < spfa[next].size(); i++) {
			if (spfa[next][i].first == start) {
				spfa[next].erase(spfa[next].begin() + i);
				break;
			}
		}
		start = next;
	}

	return 1;
}

int maxcount(vector<vector<int> > &search, vector<vector<int> > &base, int snode, int bnode) {
	int ssubnum = search[snode].size();
	int bsubnum = base[bnode].size();
	vector<vector<int> > matchcount(ssubnum, vector<int>(bsubnum, 0));
	vector<vector<pair<int, int> > > spfa(2 + ssubnum + bsubnum);
	for (int i = 1; i <= ssubnum; i++) {
		spfa[0].push_back(make_pair(i, 0));
		//spfa[i].push_back(make_pair(0, -1));
	}
	for (int i = 1 + ssubnum; i <= ssubnum + bsubnum; i++) {
		spfa[i].push_back(make_pair(1 + ssubnum + bsubnum, 0));
		//spfa[1 + ssubnum + bsubnum].push_back(make_pair(i, -1));
	}
	for (int i = 0; i < ssubnum; i++) {
		for (int j = 0; j < bsubnum; j++) {
			matchcount[i][j] = maxcount(search, base, search[snode][i], base[bnode][j]);
			if (matchcount[i][j] > 0) {
				spfa[1 + i].push_back(make_pair(ssubnum + 1 + j, -matchcount[i][j]));
				//spfa[ssubnum+1+j].push_back(make_pair(1+i, matchcount[i][j]));
			}
		}
	}

	if (ssubnum == 0 || bsubnum == 0) {
		return 1;
	}

	int add = 0;
	while (shortest_path_faster_algorithm(spfa, 0, add) != 0) {
		continue;
	}

	return 1 - add;
}

int findmatch(vector<vector<int> > &search, vector<vector<int> > &base) {
	int count = maxcount(search, base, 0, 0);
	return count;
}

int main66666() {
	int n1 = 0, n2 = 0;
	cin >> n1;
	string str1="";
	getline(cin, str1);
	getline(cin, str1);

	vector<vector<int> >  g1(n1);
	int first = 0, second = 0, comma = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] >= '0' && str1[i] <= '9') {
			if (comma == 0) {
				first = first * 10 + str1[i] - '0';
			}
			else {
				second = second * 10 + str1[i] - '0';
			}
		}
		if (str1[i] == ',' && comma == 0) {
			comma = 1;
		}
		else if (str1[i] == ',' && comma == 1) {
			comma = 0;
			g1[first - 1].push_back(second-1);
			g1[second - 1].push_back(first - 1);
			first = 0;
			second = 0;
		}
	}
	g1[first - 1].push_back(second - 1);
	g1[second - 1].push_back(first - 1);
	comma = 0; first = 0; second = 0;
	delnottree(g1, 0);

	cin >> n2;
	string str2 = "";
	getline(cin, str2);
	getline(cin, str2);

	vector<vector<int> >  g2(n2);
	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] >= '0' && str2[i] <= '9') {
			if (comma == 0) {
				first = first * 10 + str2[i] - '0';
			}
			else {
				second = second * 10 + str2[i] - '0';
			}
		}
		if (str2[i] == ',' && comma == 0) {
			comma = 1;
		}
		else if (str2[i] == ',' && comma == 1) {
			comma = 0;
			g2[first - 1].push_back(second - 1);
			g2[second - 1].push_back(first - 1);
			first = 0;
			second = 0;
		}
	}
	g2[first - 1].push_back(second - 1);
	g2[second - 1].push_back(first - 1);
	
	delnottree(g2, 0);

	// g2를 갖고 g1과 일치하는 개수를 찾는것
	//
	int result = findmatch(g2, g1);

	cout << result << "\n";
	cin >> n1;

	return 0;
}