//Statement: http://codeforces.com/problemset/problem/433/A

#include <iostream>

using namespace std;

int n, w, h, th;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w;
		if (w == 100) h++;
		else th++;
	}
	if (th && h && (h*100 - th*200) % 200 == 0) cout << "YES";
	else if (th && h && (h*100 - th*200) % 200 != 0) cout << "NO";
	else if (!th && h % 2 == 0) cout << "YES";
	else if (!th && h % 2 != 0) cout << "NO"; 
	else if (!h && th % 2 == 0) cout << "YES";
	else if (!h && th % 2 != 0) cout << "NO";
}
