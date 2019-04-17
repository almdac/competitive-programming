// Alternative O(n) solution 
// Statement: http://codeforces.com/problemset/problem/1138/A

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned int uint;

uint n;
vector<char> sushi_row;

uint findMaxSegSize() { // Return the max segment size by linear searching the sushi row
    uint neighbor_len = 0, group_len = 1, max_seg_len = 0;

    for (uint i = 1 ; i < n; i++) {
        if (sushi_row[i-1] == sushi_row[i]) 
            group_len++;
        else if (neighbor_len && 2*min(neighbor_len, group_len) > max_seg_len) {
            max_seg_len = 2*min(neighbor_len, group_len);
            neighbor_len = group_len;
            group_len = 1;
        }
        else {
            neighbor_len = group_len;
            group_len = 1;
        }
    }
    return (2*min(neighbor_len, group_len) > max_seg_len) ? 2*min(neighbor_len, group_len) : max_seg_len;
}

int main() {
    char t;

    cin >> n;
    for (uint i = 0; i < n; i++) {
        cin >> t;
        sushi_row.push_back(t);
    }
    cout << findMaxSegSize();
}