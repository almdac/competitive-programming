// Statement: https://www.spoj.com/problems/SPIKES/

#include <vector>
#include <iostream>

using namespace std;

int n, m, j, traps = 0;
vector<char> maze;
vector<bool> visited, visited_backup;
bool catched = false;

bool solve(int node); // Solve the maze by using Backtracking
bool reject(int node); // Reject the current state (unsolvable)
bool accept(int node); // Accept the current state (solution)
void update(int node); // Update the path variables for the current state
vector<int> generateAdjacent(int node); // Generate the children of the current state
void revoke(int node); // Revoke the current states's variables

int main() {
    int i;
    char p; 

    cin >> n >> m >> j;
    for (i = 0; i < n*m; i++) {
        cin >> p;
        maze.push_back(p);
    }
    visited = vector<bool>(n*m, false);
    for (i = 0; i < n*m; i++) {
        if (maze[i] == '@' && solve(i)) { // Try entrances
            cout << "SUCCESS";
            break;
        }
    }
    if (i == n*m) cout << "IMPOSSIBLE";
    return 0;
}

bool solve(int node) {
    vector<int> adjacent;

    if (reject(node)) return false;
    if (accept(node)) return true;
    update(node);
    adjacent = generateAdjacent(node);
    for (auto point : adjacent) {
        if (solve(point)) return true;
    }
    revoke(node);
    return false;
}

bool reject(int node) {
    if (maze[node] == '#') return true; // Wall
    if (maze[node] == 's' && traps+1 > j) return true; // Trap limit exceeded
    return false;
}

bool accept(int node) {
    if (maze[node] == '@' && catched) return true; // Treasure catched and an exit found
    return false;
}

void update(int node) {
    if (maze[node] == 's') traps++;
    if (maze[node] == 'x') {
        visited_backup = visited;
        visited = vector<bool>(n*m, false); // Reverse path allowed to go back
        catched = true;
    }
    visited[node] = true;
}

vector<int> generateAdjacent(int node) {
    vector<int> adjacent;

    if (node-m >= 0 && !visited[node-m]) // Line above
        adjacent.push_back(node-m);
    if (node+m < (n*m)-1 && !visited[node+m]) // Line bellow
        adjacent.push_back(node+m);
    if ((node-1)/m == node/m && !visited[node-1]) // Same line, left position
        adjacent.push_back(node-1);
    if ((node+1)/m == node/m && !visited[node+1]) // Same line, right position
        adjacent.push_back(node+1);

    return adjacent;
}

void revoke(int node) {
    if (maze[node] == 's') traps--;
    if (maze[node] == 'x') {
        visited = visited_backup;
        catched = false;
    }
    visited[node] = false;
}