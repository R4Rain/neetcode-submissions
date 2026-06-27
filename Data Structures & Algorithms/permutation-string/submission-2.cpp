class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int hash_s1[27] = {0}, hash_s2[27] = {0}, st = 0;
        for (int i = 0;i < s1.size();i++) {
            hash_s1[s1[i] - 'a']++;
        }

        for (int i = 0;i < s2.size();i++) {
            int idx = s2[i] - 'a';
            hash_s2[idx]++;

            while (st <= i && hash_s2[idx] > hash_s1[idx]) {
                hash_s2[s2[st] - 'a']--;
                st++;
            }

            bool ok = true;
            for (int j = 0;j < 26;j++) {
                if (hash_s1[j] != hash_s2[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }

        return false;
    }
};
