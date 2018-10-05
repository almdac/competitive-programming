//Statement: http://codeforces.com/problemset/problem/580/B

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define lli long long int

using namespace std;

int n;
lli d, m, s, factor, max_factor = 0;
vector<pair<lli, lli> > frds;
vector<pair<lli, lli> >::iterator up;

bool cmp(lli val, pair<lli, lli> frd) { return val < frd.first; };

int main() {
	cin >> n >> d;
	if (d > 0) {
		for (int i = 0; i < n; i++) {
			cin >> m >> s;
			frds.push_back(make_pair(m, s));
		}
		sort(frds.begin(), frds.end());
		if (frds.size() > 1) for (int i = 1; i < n; i++) frds[i].second += frds[i-1].second;
		for (int i = 0; i < n; i++) {
			if (i == 0 || frds[i].first != frds[i-1].first) {
				up = upper_bound(frds.begin()+i, frds.end(), frds[i].first+d-1, cmp);
				factor = (i > 0) ? (up-1)->second - frds[i-1].second : (up-1)->second;
				if (factor > max_factor) max_factor = factor;
			}
		}
		cout << max_factor;
	} else cout << 0;
}
