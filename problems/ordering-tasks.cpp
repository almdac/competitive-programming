//Statement: https://odzkskevi.qnssl.com/10b4efc19562fa67c26851fd2b184af3?v=1538659377

#include <iostream>
#include <vector>

using namespace std;

int n, m, i, j;
vector<vector<int> > graph;
vector<bool> vis;
vector<int> seq;

void doTask(int t) {
	if (!vis[t]) {
		for (i = 0; i < graph[t].size(); i++) {
			if (!vis[graph[t][i]]) doTask(graph[t][i]);
		}
		seq.push_back(t);
		vis[t] = true;
	}
}

int main() {
	while (cin >> n >> m && (n || m)) {
		graph.resize(n, vector<int>());
		vis.resize(n, false);
		while (m--) {
			cin >> i >> j;
			graph[j-1].push_back(i-1);
		}
		for (int t = 0; t < n; t++) doTask(t);
		for (int t = 0; t < n; t++) {
			if (t) cout << " " << seq[t]+1;
			else cout << seq[t]+1;
		}
		cout << endl;
		graph.clear();
		vis.clear();
		seq.clear();
	}
}
