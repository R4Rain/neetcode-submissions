class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        while(n != 0) {
            if (n < 0) {
                res = res / x;
                n += 1;
            } else {
                res = res * x;
                n -= 1;
            }
        }
        return res;
    }
};
