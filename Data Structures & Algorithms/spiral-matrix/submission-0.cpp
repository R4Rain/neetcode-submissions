class Solution {
private:
    int r1, r2, c1, c2;
    vector<int> answer;
public:
    void topLeftToTopRight(vector<vector<int>>& matrix) {
        if (r1 > r2) return;

        for (int i = c1; i <= c2;i++) {
            answer.push_back(matrix[r1][i]);
        }
        r1++;
    }

    void topRightToBottomRight(vector<vector<int>>& matrix) {
        if (c1 > c2) return;
        
        for (int i = r1;i <= r2;i++) {
            answer.push_back(matrix[i][c2]);
        }
        c2--;
    }

    void bottomRightToBottomLeft(vector<vector<int>>& matrix) {
        if (r1 > r2) return;

        for (int i = c2;i >= c1;i--) {
            answer.push_back(matrix[r2][i]);
        }
        r2--;
    }

    void bottomLeftToTopLeft(vector<vector<int>>& matrix) {
        if (c1 > c2) return;

        for (int i = r2;i >= r1;i--) {
            answer.push_back(matrix[i][c1]);
        }
        c1++;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }

        r1 = 0, r2 = matrix.size() - 1;
        c1 = 0, c2 = matrix[0].size() - 1;

        while (r1 <= r2 || c1 <= c2) {
            // TOP LEFT -> TOP RIGHT
            topLeftToTopRight(matrix);

            // TOP RIGHT -> BOTTOM RIGHT
            topRightToBottomRight(matrix);

            // BOTTOM RIGHT -> BOTTOM LEFT
            bottomRightToBottomLeft(matrix);

            // BOTTOM LEFT -> TOP LEFT
            bottomLeftToTopLeft(matrix);
        }
        return answer;
    }
};
