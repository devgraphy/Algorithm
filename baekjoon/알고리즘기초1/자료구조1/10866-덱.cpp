/* ----------<문제 정의>----------
문제: 뒤로도 pop이 가능한 덱 구현(deque stl)
입력: 명령어 수(최대 10만), 명령어, 입력값
출력: 명령에 대한 결과
*/
/* ----------<아이디어>----------
배열로 구현하면 삽입 O(N)
맨 앞에 삽입하는 경우 O(1)이 가능하려면 연결리스트 필요
deque stl을 그대로 사용하면 무슨 소용이 있어...
*/
/* ----------<알고리즘>----------
덱 = 스택 + 큐
대부분 솔루션이 deque를 활용함.
일단 deque stl 사용법 익히기

풀이시간:15분
메모리:2024KB
시간:356ms
*/
#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
    int n, num;
    deque<int> dq;
    string comm;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cin >> comm;
        if(comm == "push_front"){
            cin >> num;
            dq.push_front(num);
        }
        else if(comm == "push_back"){
            cin >> num;
            dq.push_back(num);
        }
        else if(comm == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
                cout << -1 << '\n';
        }
        else if(comm == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
                cout << -1 << '\n';
        }
        else if(comm == "size"){
            cout << dq.size() << '\n';
        }
        else if(comm == "empty"){
            cout << dq.empty() << '\n';
        }
        else if(comm == "front"){
            if(!dq.empty()){
                cout << dq.front() << '\n';
            }
            else
                cout << -1 << '\n';
        }
        else if(comm == "back"){
            if(!dq.empty()){
                cout << dq.back() << '\n';
            }
            else
                cout << -1 << '\n';
        }
    }
}