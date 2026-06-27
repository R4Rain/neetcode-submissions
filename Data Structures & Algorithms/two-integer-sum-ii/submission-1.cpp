class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;

        for (int i = 0;i < numbers.size();i++) {
            mp[numbers[i]] = i+1;
        }

        for (int i = 0;i < numbers.size();i++) {
            int remain = target - numbers[i];
            if (remain != numbers[i] && mp.count(remain) != 0) {
                return {i+1, mp[remain]};
            }
        }
        return {};
    }
};
