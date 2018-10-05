//Statement: http://codeforces.com/problemset/problem/266/A

#include <iostream>
#include <string>

using namespace std;

int n, r = 0;
string row;

int main() {
	cin >> n >> row;
	for (int i = 0; i < n; i++) {
		if (i != n-1 && row[i+1] == row[i]) r++;
	}
	cout << r;
}
