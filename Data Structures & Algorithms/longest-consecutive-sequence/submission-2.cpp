class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for (int num : s) {
            if (!s.count(num - 1)) {
                int curr = num;
                int streak = 1;

                while (s.count(curr + 1)) {
                    curr++;
                    streak++;
                }

                ans = max(ans, streak);
            }
        }

        return ans;
    }
};