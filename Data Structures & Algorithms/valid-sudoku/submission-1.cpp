class Solution {
public:
    // 0, 0
    // 3, 0
    // 6, 0
    // 
    // 0, 3

    bool isValid3x3(int x, int y, vector<vector<char>>& board) {
        int hash_map[10] = {0};
        for (int i = x;i < x + 3;i++) {
            for (int j = y;j < y + 3;j++) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    int num = board[i][j] - '0';
                    hash_map[num] += 1;
                    if (hash_map[num] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidRow(int x, vector<vector<char>> &board) {
        int hash_map[10] = {0};
        for (int i = 0;i < 9;i++) {
            if (board[i][x] == '.') {
                continue;
            } else {
                int num = board[i][x] - '0';
                hash_map[num] += 1;
                if (hash_map[num] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidColumn(int x, vector<vector<char>> &board) {
        int hash_map[10] = {0};
        for (int i = 0;i < 9;i++) {
            if (board[x][i] == '.') {
                continue;
            } else {
                int num = board[x][i] - '0';
                hash_map[num] += 1;
                if (hash_map[num] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0;i <= 6;i+=3) {
            for (int j = 0;j <= 6;j+=3) {
                if (!isValid3x3(i, j, board)) {
                    return false;
                }
            }
        }
        for (int i = 0;i < 9;i++) {
            if (!isValidRow(i, board)) {
                return false;
            }

            if (!isValidColumn(i, board)) {
                return false;
            }
        }
        return true;
    }
};
