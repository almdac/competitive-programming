//Statement: http://codeforces.com/problemset/problem/214/A

#include <iostream>
#include <cmath>

using namespace std;

int n, m, total = 0;

int main() {
	cin >> n >> m;
	
	for (int i = 0; i <= 1000; i++) {
		if ((sqrt(n-i) + pow(i, 2)) == m) total++;
	}
	cout << total;
}
