// Statement: http://codeforces.com/problemset/problem/1138/A

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef unsigned int uint;

uint n;
vector<uint> groups;

bool subSegExists(uint len) { // Check wether the subsegment exists
    for (int i = 1; i < groups.size()-1; i++) {
        if (groups[i] >= len && (groups[i-1] >= groups[i] || groups[i+1] >= groups[i])) // If the group is big enough and has a neighbor as big as it's
            return true; 
    }
    if (groups.size() == 2) {
        if (groups[0] < groups[1]) return groups[0] >= len;
        else return groups[1] >= len;

    }
    return false;
}

uint findMaxSubSeg(uint l, uint r) { // Try to find the max segment size by binary searching the solution space
    uint mid;
    
    while (l < r-1) {
        mid = (r+l) >> 1;
        if (subSegExists(mid)) l = mid; // It could be better
        else r = mid-1; // Ok, let's try smaller subsegments
    }
    if (subSegExists(r)) return 2*r;
    else return 2*l;
}

void getGroups() { // Get groups of sushi types
    char t, last_t = 0;
    uint g_len = 0;

    cin >> n;
    for (uint i = 0; i < n; i++) {
        cin >> t;
        if (last_t == 0) last_t = t;
        if (last_t == t) g_len++;
        else {
            groups.push_back(g_len);
            last_t = t;
            g_len = 1;
        }
    }
    groups.push_back(g_len);
}

int main() {
    getGroups();
    cout << findMaxSubSeg(1, n/2);
}