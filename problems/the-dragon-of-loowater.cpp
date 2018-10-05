// Statement: https://uva.onlinejudge.org/external/112/11292.pdf

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, measure, k = 0, d = 0, coins = 0;
vector<int> dhd, kh;
vector<int>::iterator it;

int main() {
	while (cin >> n >> m && (n != 0 || m != 0)) {
		for (int i = 0; i < n; i++) {
			cin >> measure;
			dhd.push_back(measure);
		}
		for (int i = 0; i < m; i++) {
			cin >> measure;
			kh.push_back(measure);
		}
		sort(kh.begin(), kh.end());
		sort(dhd.begin(), dhd.end());
		while (d < n && k < m) {
			while (dhd[d] > kh[k] && k < m) k++;
			if (k == m) break;
			else coins += kh[k];
			d++;
			k++;
		}
		if (d == n) cout << coins << endl;
		else cout << "Loowater is doomed!" << endl;
		coins = 0;
		k = 0;
		d = 0;
		dhd.clear();
		kh.clear();
	}
}
