class Solution {
public:
    bool solve(vector<int>& piles, int h, int k) {
        int cnt = 0;
        for (int i = 0;i < piles.size();i++) {
            cnt += (piles[i] / k) + (piles[i] % k != 0 ? 1 : 0);
        }
        return cnt <= h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for (auto pile: piles) {
            if (pile > high) {
                high = pile;
            }
        }
        
        int k = -1;
        int low = 1;
        while (low <= high) {
            int mid = ((high - low) / 2) + low;

            bool isGood = solve(piles, h, mid);
            if (isGood) {
                k = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return k;
    }
};
