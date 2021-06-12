// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// Constraints: -2^31 <= x <= 2^31 - 1
// ---------------------------------------------------------------------------------
// exception occurred
class Solution {
public:
    int reverse(int x) {
        int tmp = x;
        int res = 0;
        while(tmp != 0){    // 음수도 처리하기 위해서 not equal 연산을 사용해야 한다.
            if(res > INT_MAX/10||(res == INT_MAX/10 && tmp%10 > 7))
                return 0;
            if(res < INT_MIN/10||(res == INT_MIN/10 && tmp%10 < -8))
                return 0;
            res = res*10 + tmp%10;
            tmp/=10;
        }
        return res;
    }
};