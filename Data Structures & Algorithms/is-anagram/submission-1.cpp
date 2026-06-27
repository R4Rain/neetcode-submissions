#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash_map[27];
        memset(hash_map, 0, sizeof(hash_map));

        for (int i = 0;i < s.size();i++) {
            hash_map[s[i] - 'a'] += 1;
        }

        for (int i = 0;i < t.size();i++) {
            hash_map[t[i] - 'a'] -= 1;
        }

        for (int i = 0;i < 26;i++) {
            if (hash_map[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
