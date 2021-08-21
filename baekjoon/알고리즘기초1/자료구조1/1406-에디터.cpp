/* ----------<문제 정의>----------
문제: 에디터 구현
입력: 문자열, 명령 수, 각 명령어(문자열 최대 10만, 명령 수 최대 50만)
출력: 명령을 수행한 후 문자열
제한 시간: 0.3초
*/
/* ----------<알고리즘>----------
string 문자열에 insert와 erase를 사용한다.

B: concat 또는 erase메서드 사용
*/
/* -----<새롭게 안 것>-----
string.substr(start pos, 문자 수)
*/
/* -----<시간 초과>----
@ 복잡도 계산
    최대 10만 길이의 문자열을 다 삭제했다가 삽입하는 과정에서
    2 * (1 + ... + 10만) 연산 발생한다. = O(n^2)
    =>문자열, 배열, 벡터로 삽입, 삭제 모두 O(N)이기 때문에 이 시간을 줄여줄 필요가 있다.
    ☝연결 리스트로 해결할 수 있다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str, comm, addstr;
    cin >> str;
    int n, cursor = str.length();   // 문자열 끝에서 시작
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> comm;
        if(comm == "L"){
            if(cursor>0) cursor-=1;
        }
        else if(comm == "D"){
            if(cursor < str.length()) cursor+=1;
        }
        else if(comm == "B"){
            //erase 메서드 이용. 0부터 시작
            if(cursor > 0) {
                str.erase(--cursor,1); // 앞 문자 하나 삭제 되었으므로 커서 1 줄인다.
            }
        }
        else if(comm == "P"){
            cin >> addstr;
            str.insert(cursor++, addstr);   // 문자 추가했으므로 커서를 1 키운다.
        }
    }
    cout << str;
}