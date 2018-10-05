#include <iostream>
#include <vector>

using namespace std;

int n, p, amazing = 0;
vector<int> contests;
bool l, g;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (i) {
			l = true, g = true;
			for (int j = 0; j < i; j++) {
				if (contests[j] <= p) l = false;
				if (contests[j] >= p) g = false;
			}
		}
		contests.push_back(p);
		if (l || g) amazing++;
	}
	cout << amazing;
}
