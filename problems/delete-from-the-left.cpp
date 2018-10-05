//Statement: http://codeforces.com/problemset/problem/1005/B

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int b = -1, i;
string s, t;

int main() {
	cin >> s >> t;
	for (i = 0; i < min(s.size(), t.size()) && b == -1; i++) {
		if (s[s.size()-1-i] != t[t.size()-1-i]) b = i;
	}
	if (b != -1) cout << (s.size()-b) + (t.size()-b);
	else cout << max(s.size(), t.size()) - min(s.size(), t.size());
}
