class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> freq_nums;

        for (int i = 0;i < nums.size();i++) {
            freq_nums[nums[i]]++;
        }
        vector<vector<int>> answer;
        unordered_map<int, unordered_map<int, int>> used_map;
        for (int i = 0;i < nums.size();i++) {
            for (int j = i+1;j < nums.size();j++) {
                int firstNum = nums[i], secondNum = nums[j];
                if (used_map[firstNum].count(secondNum) == 0) {
                    freq_nums[firstNum]--;
                    freq_nums[secondNum]--;
                    int remaining = (firstNum + secondNum) * -1;
                    if (freq_nums[remaining] > 0) {
                        answer.push_back({firstNum, secondNum, remaining});
                        used_map[firstNum][secondNum] = 1;
                        used_map[firstNum][remaining] = 1;
                        used_map[secondNum][remaining] = 1;
                        used_map[secondNum][firstNum] = 1;
                        used_map[remaining][firstNum] = 1;
                        used_map[remaining][secondNum] = 1;
                    }
                    freq_nums[firstNum]++;
                    freq_nums[secondNum]++;
                }
            }
        }
        return answer;
    }
};
