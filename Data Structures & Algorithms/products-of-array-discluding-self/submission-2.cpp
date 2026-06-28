class Solution {
public:
    // -1, 0, 1, 2, 3 => 
    // 


    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0, sum = 1;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                sum = sum * nums[i];
            }
        }
        vector<int> ans;
        for (int i = 0;i < nums.size();i++) {
            if (zeroCount > 0 && nums[i] != 0) {
                ans.push_back(0);
            } else if (zeroCount == 1 && nums[i] == 0) {
                ans.push_back(sum);
            } else if (zeroCount > 1 && nums[i] == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(sum / nums[i]);
            }
        }
        return ans;
    }
};
