/* ----------<모델링>----------
문제: 괄호가 올바른지 판단하기
입력: 10만, 괄호 1종류
출력: true/false
알고리즘:O(n)
스택용 변수 정의
입력 문자열 순회하면서
    열리면 변수 증가
    닫히면 변수 감소(단, 스택에 아무 것도 없는데 닫는게 들어오면 바로 false)
*/
/* ----------<채점 결과>----------
정확성: 69.5
효율성: 30.5
합계: 100.0 / 100.0
*/
#include<string>
#include <iostream>

using namespace std;
bool solution(string s)
{
    int stack = 0;
    for(int i = 0; i < s.length();i++){
        if(s[i] == '(')
            stack++;
        else{
            if(stack <= 0)
                return false;
            stack--;
        }
    }
    if(stack == 0)
        return true;
    else
        return false;
}