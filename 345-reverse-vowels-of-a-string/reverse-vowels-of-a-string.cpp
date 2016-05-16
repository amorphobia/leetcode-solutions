class Solution {
public:
    string reverseVowels(string s) {
        string vowels;
        for (string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
            if (isVowel(*rit)) {
                vowels.push_back(*rit);
            }
        }
    
        string::iterator vit = vowels.begin();
        for (string::iterator it = s.begin(); it != s.end(); ++it) {
            if (isVowel(*it)) {
                *it = *vit++;
            }
        }
    
        return s;
    }
    
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
    }
};