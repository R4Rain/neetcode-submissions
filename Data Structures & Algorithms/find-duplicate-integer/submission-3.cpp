class Solution {
public:
    // 3 1 3  4 2
    // 3 1 -3 4 2

    // -3 1 -3 4 2

    int findDuplicate(vector<int>& nums) {
        for (int i = 0;i < nums.size();i++) {
            int idx = abs(nums[i]);
            
            if (nums[idx - 1] < 0) {
                return idx;
            }
            nums[idx - 1] *= -1;
        }
        return -1;
    }
};
