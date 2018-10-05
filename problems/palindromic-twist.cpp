//Statement: http://codeforces.com/problemset/problem/1027/A

#include <iostream>
#include <vector>

using namespace std;

int t, n;
string s, opts;
vector<string> str_opts;
bool p;

bool intersect(string a, string b) {
	if (a[0] == b[0]) return true;
	if (b.size() > 1 && a[0] == b[1]) return true;
	if (a.size() > 1 && a[1] == b[0]) return true;
	if (a.size() > 1 && b.size() > 1 && a[1] == b[1]) return true;
	return false;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> s;
		str_opts.clear();
		for (int i = 0; i < n; i++) {	
			if (s[i] != 'z') opts.push_back(s[i]+1);
			if (s[i] != 'a') opts.push_back(s[i]-1);
			str_opts.push_back(opts);
			opts.clear();
		}
		p = true;
		for (int i = 0; i < n/2; i++) {
			if (!intersect(str_opts[i], str_opts[n-1-i])) p = false;
		}
		if (p) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
