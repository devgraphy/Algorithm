/* ----------<문제 정의>----------
문제: 올바른 괄호(괄호 종류 3개)
유사 문제: 프로그래머스 올바른 괄호(괄호 종류 1개)
입력: 길이가 1만인 괄호 문자열
출력: true/false
*/
/* ----------<알고리즘(스택용 변수)-o(n)>----------
결과: exception exists - 올바른 괄호는 대칭구조를 띈다. 대칭 구조를 판단하지 못한다.
괄호 종류가 하나이면 닫을 때 종류를 구분해서 대칭구조를 판단할 필요가 없다.
스택 역할 변수에 값이 존재한다는 것 자체가 닫을 때 대칭 구조를 띈다는 의미.
따라서, 괄호의 종류가 여러 개라면 종류를 구분하지 않는 변수가 아니라 스택 자료구조를 통해서 열린 괄호의 최신 우선순위를 top에 유지하면서 닫을 때 해당 괄호의 대칭적으로 없애줘야 한다.


각 괄호에 대한 스택용 변수 정의->괄호별로 따로 관리하겠다!
문자열 순회하면서
    열리면 스택변수 추가
    닫히면 스택변수 감소(단, 스택이 비어있을 때 닫히는게 들어오면 false 리턴)
*/
/* ----------<알고리즘(스택 자료구조 사용: 대칭이용-o(n))>----------
한개의 스택 자료구조 정의 -> 모든 괄호
문자열 순회하면서
    열리면 스택 push
    닫히면
        스택 top과 비교 후 일치하면
            pop
        일치하지 않으면 false 리턴
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for(int i = 0; i < s.length();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                paren.push(s[i]);
            else{
                if(paren.size() <= 0) return false;
                if(s[i] == ')' && paren.top() == '(')
                    paren.pop();
                else if(s[i] == ']' && paren.top() == '[')
                    paren.pop();
                else if(s[i] == '}' && paren.top() == '{')
                    paren.pop();
                else
                    return false;
                
            }
        }
        if (paren.size() == 0) return true;
        else return false;    
    }
};