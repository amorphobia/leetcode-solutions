class Solution {
public:
    int integerBreak(int n) {
        if ((n == 2) || (n == 3)) return n - 1;
        int q = n / 3;
        int r = n % 3;
    
        if (r == 0) {
            return (int)pow(3, q);
        }
        if (r == 1) {
            return (int)pow(3, q - 1) * 4;
        }
        return (int)pow(3, q) * 2;
    }
};