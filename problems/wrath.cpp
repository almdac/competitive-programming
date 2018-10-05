//Statement: http://codeforces.com/problemset/problem/892/B

#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> left_pts, right_pts;
int n, open = 0, survivors = 0, left_pt, l;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &l);
		if (l > 0 && i > 0) {
			left_pt = (i-l >= 0) ? i-l : 0;
			if (left_pts.find(left_pt) != left_pts.end())
				left_pts[left_pt]++;
			else left_pts[left_pt] = 1;
			right_pts[i-1] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (left_pts.find(i) != left_pts.end())
			open += left_pts[i];
		if (!open) survivors++;
		if (right_pts.find(i) != right_pts.end())
			open -= right_pts[i];
	}
	printf("%d", survivors);
}
