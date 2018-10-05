//Statement: https://www.spoj.com/problems/HS12MBR/en/

#include <iostream>

using namespace std;

int t, n, min_x, max_x, min_y, max_y, x, y, r, u, v;
char o;

int main() {
	cin >> t;
	
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> o;
			if (o == 'p') {
				cin >> x >> y;
				if (i == 0) {
					min_x = x;
					max_x = x;
					min_y = y;
					max_y = y;
				} else {
					if (x < min_x) min_x = x;
					if (x > max_x) max_x = x;
					if (y < min_y) min_y = y;
					if (y > max_y) max_y = y;
				}
			} else if (o == 'c') {
				cin >> x >> y >> r;
				if (i == 0) {
					min_x = x-r;
					max_x = x+r;
					min_y = y-r;
					max_y = y+r;
				} else {
					if (x-r < min_x) min_x = x-r;
					if (x+r > max_x) max_x = x+r;
					if (y-r < min_y) min_y = y-r;
					if (y+r > max_y) max_y = y+r;
				}
			} else if (o == 'l') {
				cin >> x >> y >> u >> v;
				if (i == 0) {
					if(x > u) {
						max_x = x;
						min_x = u;
					} else {
						max_x = u;
						min_x = x;
					}
					if (y > v) {
						max_y = y;
						min_y = v;
					} else {
						max_y = v;
						min_y = y;
					}
				} else {
					if(x > u) {
						if (x > max_x) max_x = x;
						if (u < min_x) min_x = u;
					} else {
						if (u > max_x) max_x = u;
						if (x < min_x) min_x = x;
					}
					if (y > v) {
						if (y > max_y) max_y = y;
						if (v < min_y) min_y = v;
					} else {
						if (v > max_y) max_y = v;
						if (y < min_y) min_y = y;
					}
				}
			}
		}
		cout << min_x << " " << min_y << " " << max_x << " " << max_y << endl;
	}
}
