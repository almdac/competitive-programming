//Statement: http://codeforces.com/problemset/problem/988/B

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s;
vector<string> strs;
int n;
bool correct = true;
size_t found;

bool order (string a, string b) {return a.size() < b.size();}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		strs.push_back(s);
	}
	sort(strs.begin(), strs.end(), order);
	for (int i = 1; i < n && correct; i++) {
		for (int j = 0; j < i && correct; j++) {
			found = strs[i].find(strs[j]);
			if (found == string::npos) correct = false;
		}
	}
	if (correct) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) cout << strs[i] << endl;
	} else cout << "NO";
}
