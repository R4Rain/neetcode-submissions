class Solution {
public:
    vector<int> min_product;
    vector<int> max_product;
    int ans;

    void solve(int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            return;
        }

        int res1 = min_product[idx-1] * nums[idx];
        int res2 = max_product[idx-1] * nums[idx];

        int mini = min(nums[idx], min(res1, res2));
        min_product[idx] = mini;

        int maxi = max(nums[idx], max(res1, res2));
        max_product[idx] = maxi;

        ans = max(maxi, ans);
        solve(idx+1, nums);

        return; 
    }


    int maxProduct(vector<int>& nums) {
        min_product.assign(nums.size(), -1);
        max_product.assign(nums.size(), -1);
        ans = nums[0];
        min_product[0] = nums[0];
        max_product[0] = nums[0];

        solve(1, nums);
        return ans;
    }
};
