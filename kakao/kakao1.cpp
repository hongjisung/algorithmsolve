#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef struct rule {
	char c1;
	char c2;
	char op;
	int d;
}rule;

void check_rule(vector<rule> vr, int &result, char *ch) {
	int chidx[100] = { 0, };
	for (int i = 0; i < 8; i++) {
		chidx[int(ch[i])] = i;
	}
	int pass=0;
	for (int i = 0; i < vr.size(); i++) {
		rule r = vr[i];
		int dist = abs(chidx[int(r.c1)] - chidx[int(r.c2)]) - 1;
		if (r.op == '=' && dist == int(r.d)-48) {
			pass++;
		}
		else if (r.op == '<' && dist < int(r.d) - 48) {
			pass++;
		}
		else if (r.op == '>' && dist > int(r.d) - 48) {
			pass++;
		}
		else {
			break;
		}
	}
	if (pass == vr.size()) {
		result++;
	}
}

void next_permute(vector<rule> vr, int &result, char* ch, int cnt) {
	if (cnt == 1) {
		check_rule(vr, result, ch);
		return;
	}
	int idx = 8 - cnt;
	for (int i = idx; i < 8; i++) {
		char temp = ch[i];
		ch[i] = ch[idx];
		ch[idx] = temp;
		next_permute(vr, result, ch,cnt-1);
		temp = ch[i];
		ch[i] = ch[idx];
		ch[idx] = temp;
	}
}


int main() {
	int N = 0;
	string dump = "";
	string rulestr = "";
	cin >> N;
	getline(cin, dump);
	vector<rule> vr;
	for (int ii = 0; ii < N; ii++) {
		getline(cin, rulestr);
		int i = 0;
		rule r;
		r.c1 = rulestr[i];
		r.c2 = rulestr[i + 2];
		r.op = rulestr[i + 3];
		r.d = rulestr[i + 4];
		vr.push_back(r);

	}


	char ch[8] = { 'A','C','F','J','M','N','R','T' };
	int result = 0;
	next_permute(vr, result, ch, 8);

	cout << result << "\n";
	cin >> N;

	return 0;
}

