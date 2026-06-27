class Solution {
public:
    bool canJump(vector<int>& nums) {
        int endIdx = nums.size() - 1, cnt = 1;
        while (endIdx - cnt >= 0) {
            if (nums[endIdx - cnt] >= cnt) {
                endIdx = endIdx - cnt;
                cnt = 1;
            } else {
                cnt += 1;
            }
        }
        if (endIdx == 0) {
            return true;
        } 
        return false;
    }
};
