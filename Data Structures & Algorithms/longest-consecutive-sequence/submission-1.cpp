#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    int findParent(int i) {
        if (parent[parent[i]] != parent[i]) {
            parent[i] = findParent(parent[i]);
        }
        return parent[i];
    }

    int unionNodes(int a, int b) {
        int parent_a = findParent(a);
        int parent_b = findParent(b);

        if (parent_a == parent_b) return size[parent_a];

        if (size[parent_a] >= size[parent_b]) {
            size[parent_a] += size[parent_b];
            parent[parent_b] = parent_a;
        } else {
            size[parent_b] += size[parent_a];
            parent[parent_a] = parent_b;
        }
        return max(size[parent_a], size[parent_b]);
    }

    int longestConsecutive(vector<int>& nums) {
      int ans = 0;
      for (int i = 0;i < nums.size();i++) {
          int curr = nums[i];
          auto it = parent.find(curr);
          if (it == parent.end()) { // not exist, then set as parent
              parent[curr] = curr;
              size[curr] = 1;
              ans = max(ans, 1);
          }

          it = parent.find(curr-1);
          if (it != parent.end()) { // exist, union with curr - 1
              ans = max(unionNodes(curr-1, curr), ans);
          }

          it = parent.find(curr+1);
          if (it != parent.end()) { // exist, union with curr + 1
              ans = max(unionNodes(curr, curr+1), ans);
          }
      }
      return ans;
    }
};

