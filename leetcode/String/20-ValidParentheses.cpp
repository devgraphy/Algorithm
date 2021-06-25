/* ----------<문제 정의>----------
문제: 올바른 괄호(괄호 종류 3개)
유사 문제: 프로그래머스 올바른 괄호(괄호 종류 1개)
입력: 길이가 1만인 괄호 문자열
출력: true/false
*/
/* ----------<알고리즘>----------
결과: exception exists

각 괄호에 대한 스택용 변수 정의->괄호별로 따로 관리하겠다!
문자열 순회하면서
    열리면 스택변수 추가
    닫히면 스택변수 감소(단, 스택이 비어있을 때 닫히는게 들어오면 false 리턴)
*/

class Solution {
public:
    bool isValid(string s) {
        int a = 0, b = 0, c= 0;
        for(int i = 0; i < s.length();i++){
            if(s[i] == '(')
                a++;
            else if(s[i] == '[')
                b++;
            else if(s[i] == '{')
                c++;
            else{
                if(s[i] == ')'){
                    if(a<=0) return false;
                    a--;
                }
                else if (s[i] == ']'){
                    if(b<=0) return false;
                    b--;
                }
                else if(s[i] == '}'){
                    if(c<=0) return false;
                    c--;
                }
            }
        }
        if (a == 0 && b == 0 && c == 0)
            return true;
        else return false;
    }
};