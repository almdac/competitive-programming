//Statement: http://codeforces.com/problemset/problem/879/A

#include <iostream>

using namespace std;

int n, s, d, t = 0, j;

int main() {
	cin >> n;
	while (n--) {
		cin >> s >> d;
		j = 0;
		while (s + j*d <= t) j++;
		t = s + j*d;
	}
	
	cout << t;
}
