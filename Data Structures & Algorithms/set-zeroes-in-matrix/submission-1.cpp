class Solution {
public:
    // Solution 1 (Naive)
    // Creates a new matrix and then fill it in that new matrix
    // but it cost another memory usage O(n * m)

    // Solution 2 (Space optimal)
    // We can just mark the zero by the row & column but mark it in the initial matrix

    // 1 2 0 4
    // 0 2 0 4
    // 1 2 3 4
    // 1 2 3 4


    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstZeroRow = false;
        bool firstZeroColumn = false;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        firstZeroRow = true;
                    }
                    if (j == 0) {
                        firstZeroColumn = true;
                    }
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Fill the zero by row
        for (int i = 1;i < n;i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1;j < m;j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Fill the zero by column
        for (int i = 1;i < m;i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1;j < n;j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        // Handle Edge case
        if (matrix[0][0] == 0 && firstZeroRow) {
            for (int i = 0;i < m;i++) {
                matrix[0][i] = 0;
            }
        }

        if (matrix[0][0] == 0 && firstZeroColumn) {
            for (int i = 0;i < n;i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
