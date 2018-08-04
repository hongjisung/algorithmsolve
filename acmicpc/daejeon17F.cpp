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
4로 나누면서 k-1의 공간 체크하면서 위치찾으면 끝인거같다.
문제는 공간이 0, 3일 때임

현재 공간 1,3 이면 => 다음 공간 0 : 왼아래, 1: 왼위, 2: 오위, 3: 오아래
공간 0이면 => 다음 공간 0:왼아래, 1: 오아래, 2: 오위, 3: 왼위
공간 3이면 => 다음 공간 0: 오위, 1: 왼위, 2: 왼아래, 3: 오아래
*/
enum quot{
	leftdown,
	leftup,
	rightup,
	rightdown
};

struct nextlook {
	quot i0;
	quot i1;
	quot i2;
	quot i3;
};


struct point {
	ll x;
	ll y;
};

struct range {
	ll x1;
	ll x2;
	ll y1;
	ll y2;
};

point findpoint(ll leftn, ll leftk, range r, nextlook nl) {
	if (leftn == 1) {
		return point{ r.x1,r.y1 };
	}
	int nextn = (leftn >> 1);
	int pos = (leftk / (nextn*nextn));
	int nextk = leftk % (nextn*nextn);
	
	range newr;
	nextlook newnl = nl;
	if (pos == 0) {
		newnl.i3 = nl.i1;
		newnl.i1 = nl.i3;
	}
	else if (pos == 3) {
		newnl.i2 = nl.i0;
		newnl.i0 = nl.i2;
	}

	if (pos == 0) {
		pos = nl.i0;
		/*if (nl.i0 == leftdown) {
			pos = 0;
		}
		else if (nl.i0 == leftup) {
			pos = 1;
		}
		else if (nl.i0 == rightup) {
			pos = 2;
		}
		else if (nl.i0 == rightdown) {
			pos = 3;
		}*/
	}
	else if (pos == 1) {
		pos = nl.i1;
	}
	else if (pos == 2) {
		pos = nl.i2;
	}
	else {
		pos = nl.i3;
	}

	if (pos == 0) {
		newr = range{r.x1,r.x1+nextn-1, r.y1, r.y1+nextn-1};
	}
	else if (pos == 1) {
		newr = range{ r.x1,r.x1 + nextn-1, r.y1+nextn, r.y2 };
	}
	else if (pos == 2) {
		newr = range{ r.x1+nextn,r.x2, r.y1 + nextn, r.y2 };
	}
	else {
		newr = range{ r.x1 + nextn ,r.x2, r.y1, r.y1 + nextn-1 };
	}
	
	return findpoint(nextn, nextk, newr, newnl);
}

int main() {

	ll N = 0, K = 0;
	cin >> N >> K;

	point p = findpoint(N, K - 1, range{ 1,N,1,N }, nextlook{ leftdown,leftup,rightup,rightdown });
	cout << p.x << " " << p.y << "\n";


	return 0;
}