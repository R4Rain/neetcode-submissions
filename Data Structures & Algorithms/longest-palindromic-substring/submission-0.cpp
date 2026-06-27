class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";

        for (int i = 0;i < s.size();i++) {
            for (int j = i;j < s.size();j++) {
                bool isPalin = true;
                string temp = "";
                int range = (j - i);
                for (int k = 0; k <= range;k++) {
                    if (s[i+k] != s[j-k]) {
                        isPalin = false;
                        break;
                    }
                    temp += s[i+k];
                }
                cout << i << ' ' << j << ' ' << isPalin << endl;
                if (isPalin && temp.size() > res.size()) {
                    res = temp;
                }
            }
        }

        return res;
    }
};
