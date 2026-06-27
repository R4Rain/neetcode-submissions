#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_freq;
        unordered_map<int, vector<int>> freq_vect;

        for (int i = 0;i < nums.size();i++) {
            nums_freq[nums[i]]++;
        }

        auto itr = nums_freq.begin();
        while (itr != nums_freq.end()) {
            freq_vect[itr->second].push_back(itr->first);
            itr++;
        }
        vector<int> ans;
        for (int i = 10000;i >= 1 && k > 0;i--) {
          if (!freq_vect[i].empty()) {
            for (auto &num : freq_vect[i]) {
                ans.push_back(num);
                k--;
                if (k <= 0) break;
            }
          }
        }
        return ans;
    }
};