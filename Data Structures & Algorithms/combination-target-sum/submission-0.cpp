class Solution {
private:
    vector<vector<int>> answer;
public:
    void solve(int idx, vector<int>& nums, vector<int> curr, int target) {
        if (idx >= nums.size() || target < 0) return;
        if (target == 0) {
            if (!curr.empty()) {
                answer.push_back(curr);
            }
            return;
        }

        for (int i = idx;i < nums.size();i++) {
            vector<int> tmp = curr;
            tmp.push_back(nums[i]);
            solve(i, nums, tmp, target-nums[i]);
        }
        return;
    }



    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        answer.clear();
        sort(nums.begin(), nums.end());
        solve(0, nums, {}, target);
        return answer;
    }
};
