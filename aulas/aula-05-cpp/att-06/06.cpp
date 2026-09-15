#include <iostream>
#include <vector>
using namespace std;

void displayForest(const vector<vector<char>> &forest) {
    for (const auto &row : forest) {
        for (const auto &cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

void forestFire(vector<vector<char>> &forest, int l, int c)  {
    int nl = forest.size(); // Get the number of rows in the forest
    int nc = forest[0].size(); // Get the number of columns in the forest

    // Check if the current cell is out of bounds
    if (l < 0 || l >= nl || c < 0 || c >= nc) {
        return;
    }

    // If the current cell is a tree ('#'), mark it as burned ('o')
    if (forest[l][c] != '#') {
       return;
    }

    forest[l][c] = 'o'; // Mark the current cell as burned
    
    // Recursively call the function for the right and down neighbors
    forestFire(forest, l, c - 1);
    forestFire(forest, l - 1, c);
    forestFire(forest, l, c + 1);
    forestFire(forest, l + 1, c);
}

int main() {
    int nl, nc, l, c;

    cin >> nl >> nc >> l >> c; // Read the number of rows (nl), columns (nc), and the specific row (l) and column (c) to access
    vector<vector<char>> forest(nl, vector<char>(nc)); // Create a 2D vector (matrix) with nl rows and nc columns

    for (int i = 0; i < nl; ++i) {
        for (int j = 0; j < nc; ++j) {
            cin >> forest[i][j]; // Read the elements of the matrix
        }
    }

    forestFire(forest, l, c); // Call the forestFire function to simulate the fire spreading from the specified cell
    displayForest(forest); // Output the element at the specified row (l) and column (c)

    return 0;
}