class Solution {
public:
    // TODO what happened if it is n x m

    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0;i < n;i++) {
            for (int j = i;j < n;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reverseRow(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0;i < n / 2;i++) {
            swap(matrix[i], matrix[n-1-i]);
        }
    }

    void display(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++)
                cout << matrix[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }

    void rotate(vector<vector<int>>& matrix) {
        // display(matrix);
        reverseRow(matrix);
        // display(matrix);
        transpose(matrix);
        // display(matrix);
    }
};
