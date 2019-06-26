// Statement: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=645&page=show_problem&problem=103

#include <cstdio>
#include <string>

int board[8][8], partial[8], max_points = 0;

int getPartialPoints() {
    int sum = 0;

    for (int i = 0; i < 8; i++) {
        sum += board[i][partial[i]];
    }
    return sum;
}

bool isAValidState(int column, int row) {
    for (int i = 1; i < 8; i++) {
        // Same row
        if (column - i >= 0 && partial[column - i] == row)
            return false;

        // Same negative diagonal
        if (column - i >= 0 && row - i >= 0 && partial[column - i] == row - i)
            return false;

        // Same positive diagonal
        if (column - i >= 0 && row + i < 8 && partial[column - i] == row + i)
            return false;
    }
    return true;
}

void backtrack(int column) {
    int partialPoints;

    // Check wether it's a solution
    if (column == 8) {
        // Get the points of the partial solution
        partialPoints = getPartialPoints();

        // Check wether it's a max solution to be saved
        if (partialPoints > max_points) {
            max_points = partialPoints;
        }
    } else {
        // Try the next extensions
        for (int row = 0; row < 8; row++) {
            // Check wether it's a valid state
            if (isAValidState(column, row)) {
                // Extend
                partial[column] = row;
                column++;

                // Proceed the search
                backtrack(column);

                // Backtrack
                column--;
            }
        }
    }
}

int main() {
    int k;
    std::string max_solution;

    scanf("%d", &k);
    while (k--) {
        // Get the chess board points
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                scanf("%d", &board[i][j]);
            }
        }

        // Search for the max solution
        backtrack(0);

        // Get the string of the max solution
        max_solution = std::to_string(max_points);

        // Generate the pre-space field
        for (int i = 0; i < 5 - max_solution.length(); i++) {
            printf(" ");
        }

        // Print the max solution
        printf("%d\n", max_points);

        // Clean the variables for the next test case
        max_points = 0;
    }
}