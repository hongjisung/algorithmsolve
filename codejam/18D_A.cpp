#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		long long N = 0, O = 0, D = 0;
		cin >> N >> O >> D;
		long long x1 = 0, x2 = 0, A = 0, B = 0, C = 0, M = 0, L = 0;
		cin >> x1 >> x2 >> A >> B >> C >> M >> L;
		vector<long long> x(N, 0);
		vector<long long> s(N, 0);
		vector<long long> partsum(N + 1, 0);
		x[0] = x1; x[1] = x2;
		s[0] = x[0] + L;
		s[1] = x[1] + L;
		partsum[1] = s[0]; partsum[2] = s[0] + s[1];
		for (int i = 2; i<N; i++) {
			x[i] = (A*x[i - 1] + B * x[i - 2] + C) % M;
			s[i] = x[i] + L;
			partsum[i + 1] = s[i] + partsum[i];
		}

		long long dmax = LLONG_MIN;
		long long start = 1, end = 0, onum = 0;
		multiset<long long> ms;
		//ms.insert(LLONG_MIN);
		while (start <= N) {
			if (O == 0) {
				if (  (abs(s[end]) & 1) == 1 && start>end) {
					start++;
					end++;
					continue;
				}
			}
			while (onum <= O) {
				if (end >= N || onum == O && (abs(s[end]) & 1) == 1) {
					break;
				}
				if ( (abs(s[end]) & 1) == 1) {
					onum++;
				}
				end++;
				ms.insert(partsum[end]);
			}

			ms.insert(partsum[start-1]+D);
			auto fbase = ms.find(partsum[start-1]+D);
			auto fcomp = fbase;
			fcomp++;
			if(*fbase == *fcomp){
				if (dmax < *fbase - partsum[start - 1]) {
					dmax = *fbase - partsum[start - 1];
				}
			}
			else if(fbase!=ms.begin()){
				fbase--;
				if (dmax < *fbase - partsum[start - 1]) {
				
					dmax = *fbase - partsum[start - 1];
				}
				fbase++;
			}
			ms.erase(fbase);


			
			if (onum>0 && (abs(s[start - 1]) & 1) == 1) {
				onum--;
			}
			if(start<=end)
				ms.erase(ms.find(partsum[start]));
			start++;
		}

		if (dmax == LLONG_MIN) {
			cout << "Case #" << tc << ": IMPOSSIBLE\n";
		}
		else {
			cout << "Case #" << tc << ": " << dmax << "\n";
		}
	}
}