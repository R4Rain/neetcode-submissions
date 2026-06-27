#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int hash[123] = {0};
        hash[s[0]] += 1;
        int ans = 1, curr = 1, st = 0;

        for (int i = 1;i < s.size();i++) {
            hash[s[i]] += 1;
            curr += 1;

            while(hash[s[i]] > 1 && st < i) {
                hash[s[st]] -= 1;
                curr -= 1;
                st += 1;
            }

            ans = max(ans, curr);
        }
        return ans;
    }
};
