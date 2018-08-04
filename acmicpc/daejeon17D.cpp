#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <time.h>
#include <algorithm>
using namespace std;
#define ll long long
#define imax 1000000000
#define bound 1000000
#define div 1000000007

int squaredigit(int n) {
	int result = 0;
	while (n > 0) {
		int a = n % 10;
		result += (a*a);
		n /= 10;
	}
	return result;
}

int main() {
	int N = 0, K = 0;
	cin >> N;
	
	int step = N;
	set<int> si;
	si.insert(N);
	while (step != 1) {
		step = squaredigit(step);
		if (si.find(step) != si.end()) {
			break;
		}
		else {
			si.insert(step);
		}
	}

	if (step == 1) {
		cout << "HAPPY\n";
	}
	else {
		cout << "UNHAPPY\n";
	}

	return 0;
}