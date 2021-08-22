/* ----------<문제 정의>----------
문제: 문자열 중간 삽입, 삭제(연결리스트, 스택)
입력: 문자열, 명령 수, 각 명령어(문자열 최대 10만, 명령 수 최대 50만)
출력: 명령을 수행한 후 문자열
제한 시간: 0.3초
*/
/* ----------<알고리즘>----------
풀이시간: 30분
메모리: 2816KB
시간: 172ms

커서를 기준으로 가까운 문자를 하나씩 컨트롤해야 하므로 스택을 이용할 수 있다.
커서를 기준으로 두 개의 스택을 구성한다.
커서를 기준으로 바로 양 옆이 두 스택의 top이 된다.
*/
/* ----------<주의할 점>----------
스택 연산할 때, segmentation fault 발생하지 않도록 스택이 비어있는지 확인해야 한다.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    stack<char> st1;
    stack<char> st2;
    string str, comm; // 입력 문자열, 명령어
    char addchar;     // 추가 문자열
    int n;  // 명령어 수
    cin >> str >> n;
    for(int i = 0; i < str.length(); i++)
        st1.push(str[i]);
    // abcd
    for(int i = 0; i < n; i++){
        cin >> comm;
        // 커서 왼쪽 이동 - st1에서 st2로 이동
        if(comm == "L"){
            if(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        // 커서 오른쪽 이동 - st2에서 st1로 이동
        else if(comm == "D"){
            if(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        else if(comm == "B"){
            if(!st1.empty()){
                st1.pop();
            }
        }
        else if(comm == "P"){
            cin >> addchar;
            st1.push(addchar);
        }
    }
    // cout <<st1.size() << endl;
    while(st1.size() > 0){
        st2.push(st1.top());
        st1.pop();
    }
    // cout << temp.size() << endl;
    while(st2.size()>0){
        cout << st2.top();
        st2.pop();
    }
}