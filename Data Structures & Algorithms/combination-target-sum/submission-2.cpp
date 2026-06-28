class Solution {
private:
    vector<vector<int>> answer;
public:
    void solve(int idx, vector<int>& nums, vector<int>& curr, int target) {
        if (idx >= nums.size() || target < 0) return;
        if (target == 0) {
            answer.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        solve(idx, nums, curr, target-nums[idx]);
        curr.pop_back();
        
        solve(idx+1, nums, curr, target);
    }



    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        answer.clear();
        sort(nums.begin(), nums.end());
        vector<int> curr;
        solve(0, nums, curr, target);
        return answer;
    }
};
