class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(n);

        while (n > 1) {
            int tmp = n, sum = 0;
            while (tmp > 0) {
                int digit = tmp % 10;
                sum += digit * digit;
                tmp /= 10;
            }

            if (st.find(sum) != st.end()) {
                return false;
            }
            st.insert(sum);
            n = sum;
        }

        return true;
    }
};
