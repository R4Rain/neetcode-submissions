class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> st;
        vector<int> res (temperatures.size(), 0);
        int start = 0;

        for (int i = 0;i < temperatures.size();i++) {
            int cnt = 0;
            while (st.size() > 0 && temperatures[i] > st.back().first) {
                int idx = st.back().second;
                res[idx] = i - idx;
                st.pop_back();
            }
            st.push_back({temperatures[i], i});
        }
        return res;
    }
};
