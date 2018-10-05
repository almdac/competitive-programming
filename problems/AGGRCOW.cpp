//Statement: https://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stalls;
int c, n;

bool allocCowsWithMinDist(int dist) {
	int last = 0, allocated = 1;
	
	for (int i = 1; i < n; i++) {
		if (stalls[i] - stalls[last] >= dist) {
			last = i;
			allocated++;
		}
	}
	if (allocated < c) return false;
	else return true;
}

int binarySearchTheAns(int r, int l) {
	int mid;
	
	if (r < l-1) {
		mid = (r+l) >> 1;
		if (allocCowsWithMinDist(mid)) return binarySearchTheAns(mid, l);
		else return binarySearchTheAns(r, mid);
	}
	if (allocCowsWithMinDist(l)) return l;
	else return r;
}

int main() {
	int t, x;
	
	cin >> t;
	while(t--){
		cin >> n >> c;
		for (int i = 0; i < n; i++) {
			cin >> x;
			stalls.push_back(x);	
		}
		sort(stalls.begin(), stalls.end());
		cout << binarySearchTheAns(0, stalls[n-1]-stalls[0]) << endl;
		stalls.clear();
	}
}
