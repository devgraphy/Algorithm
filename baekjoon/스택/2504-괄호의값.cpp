/* ----------<문제 정의>----------
문제: 올바른 괄호, 괄호값 계산
입력: 괄호 문자열(최대 30)
출력: 괄호식 계산값(입력이 올바르지 못한 괄호열이면 반드시 0 출력)
*/
/* ----------<접근법>----------
괄호 문제이므로 스택 자료구조를 사용
실마리: 더하기와 곱하기를 구분하기
*/
/* ----------<알고리즘>----------

*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string str;
    stack<char> st;
    cin >> str;
    int result = 0;
    int strlen = str.length();
    for(int i = 0; i < strlen; i++){
        if(str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == '['){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            // ( 나올 때까지 모든 값 합함
            int temp = 0;
            while(st.top() != '('){
                if(st.top() == '['){  // 잘못 매칭된 경우
                    cout << 0;
                    return 0;
                }                
                temp+=st.top();
                st.pop();
            }
            st.pop();
            if(temp == 0) temp = 1;
            st.push(temp*2);  // 계산된 값을 그대로 char형 스택에 push, 추후 타입 캐스팅만 해서 출력<-두 자리 이상이기 때문
        }
        else if(str[i] == ']'){
            // ( 나올 때까지 모든 값 합함
            int temp = 0;
            while(st.top() != '['){
                if(st.top() == '('){  // 잘못 매칭된 경우
                    cout << 0;
                    return 0;
                }                
                temp+=st.top();
                st.pop();
            }
            st.pop();
            if(temp == 0) temp = 1; // 아무 것도 더해진 게 없다면
            st.push(temp*3);  // 계산된 값을 그대로 char형 스택에 push, 추후 타입 캐스팅만 해서 출력<-두 자리 이상이기 때문
        }
    }
    // 스택에 쌓인 숫자들 모두 합하기(같은 레벨의 괄호값들이 쌓인 경우)
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << result;
}