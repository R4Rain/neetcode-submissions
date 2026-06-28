class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0, carry = 0;
        for (int i = 0;i < 32;i++) {
            int bit_a = ((a >> i) & 1);
            int carry_bit_a = bit_a | carry;
            carry = bit_a & carry;

            int bit_b = ((b >> i) & 1);
            int carry_bit_b = bit_b | carry;
            carry = bit_b & carry;

            int final_bit = (carry_bit_a ^ carry_bit_b) | carry;
            carry = carry_bit_a & carry_bit_b;

            sum += (final_bit << i);
        }
        return sum;
    }
};
