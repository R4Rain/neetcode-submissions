
// 3, 4, 5, 6, 1, 2
// target = 4

// l = 0, r = 6, m = 3
//     3      2      6


class Solution {
public:
    int binarySearch(int l, int r, vector<int>& nums, int target) {
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target) {
                ans = m;
                break;
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            cout << l << ' ' << r << ' ' << m << endl;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << "Cut in " << l << ' ' << r << endl;
        return max(binarySearch(0, l-1, nums, target), binarySearch(l, nums.size()-1, nums, target));
    }
};
