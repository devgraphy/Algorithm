/* ----------<문제 정의>----------
문제: 올바른 괄호, 괄호값 계산
입력: 괄호 문자열(최대 30)
출력: 괄호식 계산값(입력이 올바르지 못한 괄호열이면 반드시 0 출력)
*/
/* ----------<틀린 접근법>----------
괄호 문제이므로 스택 자료구조를 사용
올바르게 닫을 때마다 값 계산
--> O(N)
*/
/* ----------<틀린 알고리즘>----------
문자열 순회
    (, [ 일때 push
    ), ] 일때 스택의 top과 비교
        입력이 ), 스택의 top이 (이면 sum+=2, pop
        입력이 ], 스택의 top이 [이면 sum+=3, pop
        그 외이면 0 출력하고 종료
sum 출력
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string str;
    stack<char> st;
    cin >> str;
    int sum = 0;
    int strlen = str.length();
    for(int i = 0; i < strlen; i++){
        if(str[i] == '(' || str[i] == '[')
            st.push(str[i]);
        else if(str[i] == ')'){
            if(st.top() == '('){
                sum+=2;
                st.pop();
            }
        }
        else if(str[i] == ']'){
            if(st.top() == '['){
                sum+=3;
                st.pop();
            }
        }
        else{
            cout << 0;
            return 0;
        }
    }
    cout << sum;
}