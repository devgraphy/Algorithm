/* ----------<문제 정의>----------
문제: 선택적 단어 뒤집기 - 스택
입력: 문자열
출력: 문자열
주의 사항: 구현
*/
/* ----------<리팩터드 알고리즘>----------
- stack pop 코드 중복 제거
- 문자 기준에서 flip true/false 기준 알고리즘으로 변경

flip = false인 경우
    그냥 출력
    < : 스택 요소 모두 pop, flip = false, 그대로 출력
    > : flip = true, 그대로 출력
flip = true인 경우
    stack에 푸시
    공백일 때 출력
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string str;
    bool flip = true;
    stack<char> st;
    getline(cin, str);
    str+=' ';
    for(auto c : str){
        if(flip == true){
            if(c == ' ' || c == '<'){
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
                cout << c;
                if(c == '<') flip = false;
            }
            else{   // 그 외 문자
                st.push(c);
            }
        }
        else if(flip == false){
            cout << c;
            if(c == '>') flip = true;
        }
    }
}