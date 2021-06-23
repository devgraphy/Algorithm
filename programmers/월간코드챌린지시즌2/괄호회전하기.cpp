/* 모델링
문제:문자열 입력시 회전하면서 올바른 괄호 문자열인지 판단
입력:길이 1000 문자열
출력:올바른 괄호 문자열 개수
알고리즘:O(n^2)
문자 하나씩 뒤로 옮겨가면서 올바른 괄호 문자열인지 확인한다.
for i가 시작 위치를 가리키고 정해진 문자 길이동안 확인한다. 
입력 문자열의 길이는 최대 1000이기 때문에 회전길이까지 포함하여 2000개 이상으로 정의한다.
*/
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <stack>

using namespace std;
char a[2005];
int solution(string s) {
    stack<char> st;
    int answer = 0;
    bool chk = false;
    int len = s.length();
    
    for(int i = 0; i < len;i++){
        chk = false;
        while(st.size() !=0){st.pop();} // stack 비우기
        for(int j = i; j < i+len; j++){ // 시작 pos부터 정해진 길이까지 올바른 괄호 문자열 확인
            if(s[j]==')' || s[j]=='}' || s[j]==']'){    // 닫히면
                if(st.size() <= 0){
                    chk = true;
                    break;
                }
                else{
                    if(s[j] == ')' ){
                        if(st.top()=='(')
                            st.pop();
                        else{
                            chk = true;
                            break;
                        }
                    }
                    else if(s[j] == ']'){
                        if(st.top()=='[')
                            st.pop();
                        else{
                            chk = true;
                            break;
                        }
                    }
                    else{
                        if(st.top()=='{')
                            st.pop();
                        else{
                            chk = true;
                            break;
                        }
                    }
                }
            }
            else{   // 열리면
                st.push(s[j]);
                if(st.size() > len/2){  // 성능 목적
                    chk = true;
                    break;
                }
            }
        }   
        if(chk == false && st.size()==0)
            answer++;
        s += s[i];    // 회전
    }
    return answer;
}