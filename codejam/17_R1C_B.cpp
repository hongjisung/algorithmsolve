#include <iostream>
using namespace std;

int ac = 0, aj = 0;
int arrcj[201][2] = { 0, };
//int arrc[101][2];
//int arrj[101][2];
int index[201] = { 0, };
int diff[201] = { 0, };
int diff_index[201] = { 0, };

int compare(const void * a, const void * b) {
	int f = *(int*)a;
	int s = *(int*)b;
	return arrcj[f][0] - arrcj[s][0];
}

int compare2(const void * a, const void * b) {
	int f = *(int*)a;
	int s = *(int*)b;
	return diff[f] - diff[s];
}

int main() {
	int test_num = 0;
	cin >> test_num;
	for (int tn = 1; tn <= test_num; tn++) {
		int cleft = 720;
		int jleft = 720;

		cin >> ac >> aj;
		int result = ac+aj;

		// 1~ac   ac+1~ac+aj
		// 입력받고 시간순서대로 정렬
		for (int i = 1; i <= ac+aj; i++) {
			cin >> arrcj[i][0] >> arrcj[i][1];
			index[i] = i;
			if (i <= ac)
				cleft -= arrcj[i][1] - arrcj[i][0];
			else
				jleft -= arrcj[i][1] - arrcj[i][0];
		}
		qsort((void*)(index + 1), (size_t)(ac + aj), sizeof(int), compare);
		
		
		if (result <= 1) {
			cout << "Case #" << tn << ": " << 2 << "\n";
			continue;
		}


		// 각 구간 사이에 빈공간 다 계산하고 크기 순으로 정렬
		// circle이므로 마지막도 고려해줘야함
		for (int i = 1; i < ac + aj; i++) {
			diff[i] = arrcj[index[i + 1]][0] - arrcj[index[i]][1];
			diff_index[i] = i;
		}
		diff[ac + aj] = arrcj[index[1]][0] + 1440 - arrcj[index[ac+aj]][1];
		diff_index[ac + aj] = ac + aj;
		qsort((void*)(diff_index + 1), (size_t)(ac + aj), sizeof(int), compare2);

		// 각 구간 양쪽이 같은 value이고 크기가 left보다 작으면 거길 채운다.
		// 채우고 나서 result 1감소 left도 감소
		for (int i = 1; i <= ac + aj; i++) {
			int left_index = index[diff_index[i]];
			int right_index = 0;
			if (diff_index[i]!=ac+aj)
				right_index = index[diff_index[i] + 1];
			else
				right_index = index[1];
			// c c 로 양옆
			if (left_index <= ac && right_index<=ac) {
				if (diff[diff_index[i]] <= cleft) {
					result--;
					//cout << "cleft, diff " << cleft << " " << diff[diff_index[i]]<<"\n";
					cleft -= diff[diff_index[i]];
				}
				else {
					//cout << "cleft, diff " << cleft << " " << diff[diff_index[i]] << "\n";
					result += 1;
				}
			}
			if (left_index > ac && right_index > ac) {
				if (diff[diff_index[i]] <= jleft) {
					//cout << "jleft, diff " << jleft << " " << diff[diff_index[i]] << "\n";
					result--;
					jleft -= diff[diff_index[i]];
				}
				else {
					//cout << "jleft, diff " << jleft << " " << diff[diff_index[i]] << "\n";
					result += 1;
				}
			}
		}


		cout << "Case #" << tn << ": " << result << "\n";
	}

	return 0;
}