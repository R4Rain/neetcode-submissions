#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char DELIMITER = '|';

    string encode(vector<string>& strs) {
        string result = "";
        for (int i = 0;i < strs.size();i++) {
            int leng = strs[i].size();
            result += to_string(leng) + DELIMITER + strs[i];
            if (i != strs.size() - 1) {
                result += DELIMITER;
            }
        }
        cout << "ENCODED: " << result << endl;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int idx = 0;
        
        while (idx < s.size()) {
            string lengthStr = "";
            while (idx < s.size() && s[idx] != DELIMITER) {
                lengthStr += s[idx];
                idx++;
            }

            // current idx should be in the DELIMITER
            if (idx < s.size()) idx++;

            string str = "";
            int length = idx + stoi(lengthStr);
            while (idx < length && idx < s.size()) {
                str += s[idx];
                idx++;
            }
            result.push_back(str);

            // current idx should be in the DELIMITER
            if (idx < s.size()) idx++;
        }
        return result;
    }
};
