// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// Constraints: -2^31 <= x <= 2^31 - 1
// ---------------------------------------------------------------------------------
// Line 12: signed integer overflow
class Solution {
public:
    int reverse(int x) {
        int tmp = abs(x);
        int res = 0;
        while(tmp > 0){
            res = res*10 + tmp%10;
            tmp/=10;
        }
        if(x > 0)
            return res;
        else
            return -1 * res;
    }
};