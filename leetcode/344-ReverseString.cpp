// Write a function that reverses a string. The input string is given as an array of characters s.
// Constraints: 1 <= s.length <= 105, s[i] is a printable ascii character.
// Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
// --------------------------------------------------------------------------------
// Runtime: 28 ms, Memory Usage: 23.2 MB
// Your runtime beats 25.82 % of cpp submissions.
class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int sz = s.size();
        
        for(int i = 0; i < sz/2;i++){   // 절반 동안만!
            tmp = s[i];
            s[i] = s[sz - i - 1];
            s[sz - i - 1] = tmp; 
        }
    }
};