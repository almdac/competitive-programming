//Statement: UVA - 11849

#include <iostream>
#include <set>

using namespace std;

int n, m, c, t;
set<int> cds;

int main() {
	while (cin >> n >> m && n && m) {
		cds.clear();
		t = 0;
		for (int i = 0; i < n+m; i++) {
			cin >> c;
			if (i < n) cds.insert(c);
			else if (cds.count(c) > 0) t++;
		}
		cout << t << endl;
	}
}
