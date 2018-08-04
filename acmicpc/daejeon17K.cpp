#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <list>
#include <math.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define ll long long
#define imax 1000000000
#define bound 100010
#define div 1000000007


struct node {
	double x;
	double y;
};

struct point {
	int x;
	int y;
};

vector<node> vn(1, node{ 0.0,0.0 });

int cmpx(const void * f, const void * s) {
	int a = *(int*)f;
	int b = *(int*)s;
	if (vn[a].x - vn[b].x > 0) {
		return 1;
	}
	return -1;
}
int cmpy(const void * f, const void * s) {
	int a = *(int*)f;
	int b = *(int*)s;
	if (vn[a].y - vn[b].y > 0) {
		return 1;
	}
	return -1;
}

int main() {
	int N = 0;
	cin >> N;
	int w = 0;
	vector<int> d(N + 1, -1);
	list<int> xi(1,0);
	list<int> yi(1,0);
	auto xit = xi.begin();
	auto yit = yi.begin();
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &w, &d[i]);
		if ((i & 1) == 1) {
			if (d[i - 1] == -1) {
				xit++;
				xi.insert(xit,i);
				xit--;
			}
			else {
				xi.insert(xit, i);
				xit--;
			}
			
			if (d[i - 1] == 1) {
				d[i] *= -1;
			}
		}
		else {
			if (d[i - 1] == 1) {
				yit++;
				yi.insert(yit, i);
				yit--;
			}
			else {
				yi.insert(yit, i);
				yit--;
			}
			
			if (d[i - 1] == -1) {
				d[i] *= -1;
			}
		}
	}

	vector<point> vp(N + 1);
	int i_x = 0;
	for (auto idx = xi.begin(); idx != xi.end(); idx++) {
		vp[*idx].x = i_x;
		i_x++;
	}
	int i_y = 0;
	for (auto idx = yi.begin(); idx != yi.end(); idx++) {
		vp[*idx].y = i_y;
		i_y++;
	}

	for (int i = 1; i <= N; i++) {
		if ((i & 1) == 1) {
			printf("%d ", abs(vp[i].x - vp[i - 1].x));
			vp[i].y = vp[i - 1].y;
		}
		else {
			printf("%d ", abs(vp[i].y - vp[i - 1].y));
			vp[i].x = vp[i - 1].x;
		}
	}


	return 0;
}