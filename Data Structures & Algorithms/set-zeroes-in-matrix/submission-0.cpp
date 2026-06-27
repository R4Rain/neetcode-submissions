class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> rows (n, false);
        vector<bool> columns (m, false);

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    columns[j] = true;
                }
            }
        }

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (rows[i] || columns[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
