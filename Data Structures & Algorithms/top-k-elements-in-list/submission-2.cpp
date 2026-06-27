#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_freq;

        for (int i = 0;i < nums.size();i++) {
            nums_freq[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &[number, count] : nums_freq) {
            bucket[count].push_back(number);
        }
        
        vector<int> ans;
        for (int i = bucket.size()-1;i >= 0 && k > 0;i--) {
            auto itr = bucket[i].begin();
            while (itr != bucket[i].end() && k > 0) {
                ans.push_back(*itr);
                itr++;
                k--;
            }
        }
        return ans;
    }
};