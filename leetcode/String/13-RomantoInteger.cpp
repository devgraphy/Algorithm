/* ----------<문제 정의>----------
목표:로마숫자가 주어지면 아라비아 숫자 정수로 변환
입력: 로마숫자 1<=s.length<=15, s는 7개 문자만 들어옴
출력: 정수
*/
/* ----------<고려 사항>----------
입력이 적절하다고 가정할 수 있는가?
- 문제에서 그렇지 적절하지 않은 경우에 대해서 말을 해주지 않았기 때문에 그렇게 가정할 수 있다.
- 예를 들어 ICD같은 입력이 주어지는 경우에 대해 걱정할 필요 없다.
- 실제 인터뷰에서는 면접관한테 질문해야 한다.
- 절대 입력이 타당한지 묻지 않고 가정하지 마라.

*/
/* ----------<알고리즘: time-o(n), space:o(1)>----------
핵심:일반적으로 로마 숫자는 왼쪽부터 크기가 큰 것에서 작아진다.
커지는 순간에는 뺄셈이 적용된다.

순회하면서
    이전 보다 작거나 같으면, 더해나간다. 
    커지는 수가 나오면, 바로 전의 숫자를 기존에 서 빼주고 큰 것에서 이전 값을 빼준 값을 추가해준다.
*/
/* ----------<런타임 & 메모리 사용량>----------
Runtime: 8 ms, faster than 76.05% of C++ online submissions for Roman to Integer.
Memory Usage: 6 MB, less than 62.56% of C++ online submissions for Roman to Integer.
*/
class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        int temp = 0;
        int before = 0;
        for(int i = 0; i < s.length();i++){
            if(s[i]=='I') temp = 1;
            else if(s[i]=='V') temp = 5;
            else if(s[i]=='X') temp = 10;
            else if(s[i]=='L') temp = 50;
            else if(s[i]=='C') temp = 100;
            else if(s[i]=='D') temp = 500;
            else if(s[i]=='M') temp = 1000;
            if(before >= temp ){
                sum += temp;
            }
            else{
                sum -= before;
                sum +=(temp-before);
            }
            before = temp;
        }
        return sum;
    }
};