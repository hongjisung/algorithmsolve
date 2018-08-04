#include <vector>
#include <iostream>
using namespace std;

// divide and conquer을 이용한다.
// x축과 y축 최대 값은 모두 2^31-1이다.
// 우선 이를 정렬한뒤 n*n 배열로 축소하자 n의 최대값이 5천이므로 2차원 5천개의 배열로 축소가능
// 이에 대해 n*1 n개로 recursion을 이용하여 프로그래밍
// n*1 에서 가능한 개수는 0개
// n*m 과 n*m이 합쳐질 때 
// n*m에서 가능한 개수 + n*m에서 가능한 개수 + 새로 생기는 추가 개수
//	세로 축 기준으로 한쪽(왼쪽)에서 정렬순으로 하나잡고 다음 점을 같은 행렬내에 나오기 전까지 검색해 나가면서 다른 쪽 점에서 가능한 거 찾음
//  다른 쪽(오른쪽) 것 중 x축 기준 min값을 갱신해 나가면서 min값 보다 초과하는 점 나오면 답 없음
// 왼쪽 점 기준 아래에서 위로 위에서 아래로 두번을 해야함.

vector<pair<int,int> > vi;
int cmpf(const void *f, const void *s) {
	return vi[*(int*)f].first > vi[*(int*)s].first;
}
int cmps(const void *f, const void *s) {
	return vi[*(int*)f].second > vi[*(int*)s].second;
}

void addition_count(vector<vector<int> > &board,int base_line, int start, int end, int lower_bound, int upper_bound, int &result) {
	if (base_line < start) {
		return;
	}
	vector<int> vi;
	vi.push_back(lower_bound);
	for (int i = lower_bound; i <= upper_bound; i++) {
		if (board[base_line][i] == 1) {
			vi.push_back(i);
			int lb = lower_bound;
			int ub = upper_bound;
			for (int j = start + (end - start) / 2; j < end; j++) {
				if (lb == ub) {
					break;
				}
				int lbt = lb, ubt = ub;
				for (int k = lb; k <= ub; k++) {
					if (board[j][k] == 1) {
						if (k != i) {
							result++;
						}
						if (k >= i) {
							ubt = k;
						}
						if (k <= i) {
							lbt = k;
						}
					}
				}
				lb = lbt; ub = ubt;
			}
		}
	}
	vi.push_back(upper_bound);

	for (int i = 0; i < vi.size()-1; i++) {
		if(vi[i]!=vi[i+1])
			addition_count(board, base_line - 1, start, end, vi[i],vi[i+1] , result);
	}
}

int dac(vector<vector<int> > &board, int start, int end) {
	int len = end - start;
	if (len == 1) {
		return 0;
	}
	int result = 0;
	result += dac(board, start, start + len / 2);
	result += dac(board, start + len / 2, end);

	// down to up
	addition_count(board, start+len/2-1,start, end, 0, board.size()-1, result);

	return result;
}


int main5() {
	int N = 0;
	cin >> N;
	if (N < 2 || N>5000) {
		cout << "wrong input n\n";
	}

	vector<vector<int> > board(N, vector<int>(N,0));
	int * xs = new int[N] {0, };
	int * ys = new int[N] {0, };

	int first=0, second=0;
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		if (first < 0 || second < 0) {
			cout << "wrong input\n";
		}
		vi.push_back(make_pair(first, second));
		xs[i] = i;
		ys[i] = i;
	}

	qsort(xs, (size_t)(N), sizeof(int), cmpf);
	qsort(ys, (size_t)(N), sizeof(int), cmps);
	

	int beforex = -1;
	int beforey = -1;
	for (int i = 0; i < N; i++) {
		if (vi[xs[i]].first == beforex) {
			vi[xs[i]].first = vi[xs[i - 1]].first;
		}
		else {
			beforex = vi[xs[i]].first;
			vi[xs[i]].first = i;
		}
		if (vi[ys[i]].second == beforey) {
			vi[ys[i]].second = vi[ys[i - 1]].second;
		}
		else {
			beforey = vi[ys[i]].second;
			vi[ys[i]].second = i;
		}
	}

	for (int i = 0; i < N; i++) {
		board[vi[i].first][vi[i].second] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j]<<" ";
		}
		cout << "\n";
	}

	int answer = dac(board, 0, N);
	cout << answer << "\n";
	cin >> N;

	delete[] xs;
	delete[] ys;
	vi.clear();
	return 0;
}