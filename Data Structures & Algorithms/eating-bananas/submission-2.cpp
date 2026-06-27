class Solution {
public:

    bool isPossible(vector<int> & piles, int h, int k) {
        int cnt = 0;
        for (int i = 0;i < piles.size();i++) {
            cnt += piles[i] / k + (piles[i] % k ? 1 : 0);
        }
        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1000000000;
        int ans = 1000000000;

        while(l <= r) {
            int m = l + (r - l) / 2;
            if (isPossible(piles, h, m)) {
                ans = min(ans, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
