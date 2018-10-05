//Statement: UVA - 750

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, x, y;
vector<vector<int> > sols;
vector<int> sol(8, 0);

bool valid(int col, int row) {
	for (int i = 0; i < col; i++) {
		if (sol[col-(i+1)] == row) return false;
		if (row-(i+1) >= 0 && sol[col-(i+1)] == row-(i+1)) return false;
		if (row+(i+1) < 8 && sol[col-(i+1)] == row+(i+1)) return false;
	}
	return true;
}

void getSols(int col) {
	for (int row = 0; row < 8; row++) {		
		if (col == 0 || valid(col, row)) {
			sol[col] = row;			
			if (col < 7) getSols(col+1);
			else if (sol[y] == x) sols.push_back(sol);
		}
	}
}

void printSols(){
	sort(sols.begin(), sols.end());
	cout << "SOLN       COLUMN" << endl;
	cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
	for (int i = 0; i < sols.size(); i++) {
		if (i+1 < 10) cout << " ";
		cout << i+1 << "     ";
		for (int j = 0; j < 8; j++) cout << " " << sols[i][j]+1;
		if (i != sols.size()-1) cout << endl;
	}
};

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		x--; y--;
		getSols(0);
		if (i > 0) cout << endl;
		printSols();
		cout << endl;
		sols.clear();
	}
}
