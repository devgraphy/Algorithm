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
/* -----<새롭게 안 것>----
iterator는 대소 비교연산자를 사용하지 못한다. 등호와 같지 않음 기호만 사용 가능
list의 insert 메서드는 iterator가 가리키는 이전 원소에 삽입을 한다. (다음 원소x)
    The container is extended by inserting new elements before the element at the specified position.
*/
#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(){
    string str, comm;
    char addchar;
    list<char> ll(str.begin(), str.end());
    cin >> str;
    // 문자열을 연결리스트에 추가
    for(int i = 0; i < str.length(); i++)
        ll.push_back(str[i]);
    int n;  // 명령어 수
    auto cursor = ll.end();   // 문자열 끝에서 시작
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> comm;    // 명령어 입력
        if(comm == "L"){
            if(cursor != ll.begin()) cursor--;
        }
        else if(comm == "D"){
            if(cursor != ll.end()) cursor++;
        }
        else if(comm == "B"){
            //erase 메서드 이용. 0부터 시작
            if(cursor != ll.begin()) {
                ll.erase(--cursor); // 앞 문자 하나 삭제 되었으므로 커서 1 줄인다.
            }
        }
        else if(comm == "P"){
            cin >> addchar;    
            ll.insert(cursor, addchar);   // 문자 추가했으므로 커서를 1 키워야 하는 거 아닌가? NO

        }
    }
    for(auto it = ll.begin(); it != ll.end(); it++)
        cout << *it;
}