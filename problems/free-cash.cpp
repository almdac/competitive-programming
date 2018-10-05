//Statement: http://codeforces.com/problemset/problem/237/A

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, h, m, c = 1, max_c = 1;
vector<pair<int, int> > times;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h >> m;
		times.push_back(make_pair(h, m));
	}
	sort(times.begin(), times.end());
	for (int i = 0; i < n; i++) {
		if (i > 0 && times[i] == times[i-1]) {
			c++;
			if (c > max_c) max_c = c;
		} else c = 1;
	}
	cout << max_c;
}
