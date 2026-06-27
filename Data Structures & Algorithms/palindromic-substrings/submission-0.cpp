class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0;i < s.size();i++) {
            int l = i, r = i;
            // Odd
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                cnt += 1;
                l -= 1;
                r += 1;
            }

            l = i, r = i + 1;
            // Even
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                cnt += 1;
                l -= 1;
                r += 1;
            }
        }    
        return cnt;
    }
};
