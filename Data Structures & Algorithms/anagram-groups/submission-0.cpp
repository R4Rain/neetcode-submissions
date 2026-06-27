class Solution {
public:
    const int MAX_N = 1001;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int strCnt[MAX_N][30] = {0};

        for (int i = 0;i < strs.size();i++) {
            for (int j = 0;j < strs[i].size(); j++) {
                int idx = strs[i][j] - 'a';
                strCnt[i][idx] += 1;
            }
        }

        int used[MAX_N] = {0};
        vector<vector<string>> res;
        for (int i = 0;i < strs.size();i++) {

            if (used[i] != 0) {
                continue;
            }
            vector<string> group;
            used[i] = 1;
            group.push_back(strs[i]);

            for (int j = i + 1;j < strs.size();j++) {
                if (used[j] != 0) {
                    continue;
                }  

                bool isSame = true;
                for (int k = 0;k < 27;k++) {
                    if (strCnt[i][k] != strCnt[j][k]) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) {
                    used[j] = 1;
                    group.push_back(strs[j]);
                }
            }
            res.push_back(group);
        }
        return res;
    }
};
