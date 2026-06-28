class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 1);
        vector<int> suffixSum(n, 1);

        prefixSum[0] = nums[0];
        for (int i = 1;i < n;i++) {
            prefixSum[i] = prefixSum[i-1] * nums[i]; 
        }

        suffixSum[n-1] = nums[n-1];
        for (int i = n-2;i >= 0;i--) {
            suffixSum[i] = suffixSum[i+1] * nums[i];
        }

        vector<int> ans;
        for (int i = 0;i < n;i++) {
            if (i == 0) {
                ans.push_back(suffixSum[i+1]);
            } else if (i == n - 1) {
                ans.push_back(prefixSum[i-1]);
            } else {
                ans.push_back(prefixSum[i-1] * suffixSum[i+1]);
            }
        }
        return ans;
    }
};
