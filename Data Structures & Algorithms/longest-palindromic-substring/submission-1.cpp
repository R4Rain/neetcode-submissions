class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        
        for (int i = 0;i < s.size();i++) {
            string temp = "";
            int l = i, r = i;
            // Odd
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if (l == r) {
                    temp += s[l];
                } else {
                    temp = s[l] + temp + s[r];
                }
                if (temp.size() > res.size()) {
                    res = temp;
                }
                l -= 1;
                r += 1;
            }


            temp = "";
            l = i, r = i + 1;
            // Even
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if (l == r) {
                    temp += s[l];
                } else {
                    temp = s[l] + temp + s[r];
                }
                if (temp.size() > res.size()) {
                    res = temp;
                }
                l -= 1;
                r += 1;
            }
        }    
        return res;
    }
};
