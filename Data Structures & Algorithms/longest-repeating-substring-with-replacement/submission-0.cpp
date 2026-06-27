class Solution {
public:

    // ABAB k = 2
    // window sliding
    // start...end, start = 0, end = 0
    // 
    // check if window_size - max_freq (window) > k (we need to change more than k)
    // if yes then we increment left pointer

    int characterReplacement(string s, int k) {
        int ans = 0, left = 0, max_freq = 0;
        unordered_map<char, int> map_freq;

        for (int right = 0;right < s.size();right++) {
            map_freq[s[right]]++;
            // Max frequency in window
            max_freq = max(max_freq, map_freq[s[right]]);

            while ((right - left + 1) - max_freq > k) {
                map_freq[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};