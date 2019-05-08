// Statement: http://codeforces.com/problemset/problem/1138/A

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned int uint;

uint n;
vector<char> sushi_row;

bool segExists(uint len) { // Try to find a valid segment with length len
    uint neighbor_len = 0, group_len = 1;

    for (uint i = 1 ; i < n; i++) {
        if (sushi_row[i-1] == sushi_row[i]) group_len++;
        else if (neighbor_len && 2*min(neighbor_len, group_len) >= len) return true;
        else {
            neighbor_len = group_len;
            group_len = 1;
        }
    }
    return (2*min(neighbor_len, group_len) >= len) ? true : false;
}

uint findMaxSegSize(uint l, uint r) { // Return the max segment size by binary searching the solution space
    uint mid;

    while (l < r-1) {
        mid = (l+r) >> 1;
        if (segExists(mid)) l = mid; // It could be better
        else r = mid-1; // Ok, try smaller segments
    }
    if (segExists(r)) return r;
    else return l;
}

int main() {
    char t;

    cin >> n;
    for (uint i = 0; i < n; i++) {
        cin >> t;
        sushi_row.push_back(t);
    }
    cout << findMaxSegSize(2, n);
}