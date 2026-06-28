class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;

        for (int i = 0;i < nums.size();i++) {
            int remain = target - nums[i];
            if (hash_map.count(remain)) {
                return { hash_map[remain], i };
            }
            hash_map[nums[i]] = i;
        }
        return {};
    }
};
