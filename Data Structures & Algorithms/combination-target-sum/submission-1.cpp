class Solution {
private:
    vector<vector<int>> answer;
public:
    void solve(int idx, vector<int>& nums, vector<int>& curr, int target) {
        if (idx >= nums.size() || target < 0) return;
        if (target == 0) {
            if (!curr.empty()) {
                answer.push_back(curr);
            }
            return;
        }

        for (int i = idx;i < nums.size();i++) {
            curr.push_back(nums[i]);
            solve(i, nums, curr, target-nums[i]);
            curr.pop_back();
        }
        return;
    }



    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        answer.clear();
        sort(nums.begin(), nums.end());
        vector<int> curr;
        solve(0, nums, curr, target);
        return answer;
    }
};
