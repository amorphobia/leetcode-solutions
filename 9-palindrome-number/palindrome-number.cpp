class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        return isPalindromeHelper(x, log10(x), 0);
    }
    
    bool isPalindromeHelper(int x, int h, int l) {
        if (h <= l) return true;
        int hd = (x / (int)pow(10, h)) % 10;
        int ld = (x / (int)pow(10, l)) % 10;
        
        if (hd != ld) return false;
        return isPalindromeHelper(x, h - 1, l + 1);
    }
};