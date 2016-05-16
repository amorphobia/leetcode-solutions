class Solution {
public:
    // Solution One
    bool isPowerOfFour(int num) {
        double root = sqrt(num);
        return ((num > 0) && (root == (int)root) && (32768 % (int)root == 0));
    }

    // Solution Two
    bool isPowerOfFour2(int num) {
        return ((((num - 1) & num) == 0) && ((num - 1) % 3 == 0));
    }
};