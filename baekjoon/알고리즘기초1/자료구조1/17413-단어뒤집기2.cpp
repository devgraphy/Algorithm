/* ----------<문제 정의>----------
문제: 선택적 단어 뒤집기 - 스택
입력: 문자열
출력: 문자열
주의 사항: 구현
*/
/* ----------<알고리즘>----------
bool tag 정의 해서 <가 들어왔을 때, tag = true
    tag가 true이면 문자열 단순 출력
>가 들어오면 tag = false

뒤집기를 해야 하는 시점 판단은 공백 또는 <
*주의: 문자열 끝은 공백이 아니므로 임의로 추가해줘야 한다.

문자가 
< 인 경우, 그대로 출력 tag=true
> 인 경우, 그대로 출력 tag=false
이 외의 문자가 들어온 경우
    tag = true인 경우 - 문자든 공백이든 그대로 출력
    tag = false인 경우 - 문자면 스택에 푸시, 공백이면 스택에 있는 것 모두 출력

메모리:2268KB
시간:8ms
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
    int strlen = str.length();
    // cout << strlen << endl;
    for(int i = 0; i < strlen; i++){
        if(str[i] == '<') {
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            flip = false;
            cout << '<';
        }
        else if(str[i] == '>') {
            flip = true; 
            cout << '>';
        }
        else{  // 그 외 문자
            if(flip == true){   // 괄호와 상관없는 문자
                if(str[i] == ' '){
                    while(!st.empty()){
                        cout << st.top();
                        st.pop();
                    }
                    cout << ' ';
                }
                else    st.push(str[i]);
            }
            else{               // <>괄호 안의 문자
                cout << str[i];
            }
        }
    }
}