class Solution {
public:
    string minWindow(string s, string t) {
        int st = 0;
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;
        int matched = 0;

        for (int i = 0;i < t.size();i++) {
            t_map[t[i]]++;
        }

        string ans = "";
        int ans_leng = -1;
        for (int i = 0;i < s.size();i++) {
            s_map[s[i]]++;

            if (t_map.count(s[i]) && s_map[s[i]] <= t_map[s[i]]) {
                matched++;
            }

            while (matched == t.size()) {
                int leng = i - st + 1;
                if (ans_leng == -1 || leng < ans_leng) {
                    ans = s.substr(st, leng);
                    ans_leng = leng;
                }

                s_map[s[st]]--;
                if (t_map.count(s[st]) && s_map[s[st]] < t_map[s[st]]) {
                    matched--;
                }
                st++;
            }
        }

        return ans;
    }
};
