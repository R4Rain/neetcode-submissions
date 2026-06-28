class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1; // Get carry bit then shift to the right
            a = a ^ b; // XOR for sum without carry
            b = carry;
        }
        return a;
    }
};
