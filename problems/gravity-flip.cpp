//Statement: http://codeforces.com/problemset/problem/405/A

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > box;
int n, a;

void flip(int i) {
	int j;
	if (i < n-1) {
		for (j = 0; j < box[i].size() && box[i+1].size() >= j+1; j++);
		if (j < box[i].size()) {
			box[i+1].insert(box[i+1].end(), box[i].begin()+j, box[i].end());
			box[i].erase(box[i].begin()+j, box[i].end());
			flip(i+1);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		box.push_back(vector<int>(a, 1));
	}
	for (int i = 2; i <= n; i++) flip(n-i);
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << box[i].size();
	}
}
