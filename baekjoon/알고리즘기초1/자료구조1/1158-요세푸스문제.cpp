/* ----------<문제 정의>----------
문제: 입력 순서를 유지하면서 중간 요소를 삭제하는 문제(queue, circular linked list)
입력: N, K
출력: (N,K) 요세푸스 순열 출력
*/
/* ----------<아이디어>----------
환형 순서의 데이터에서 중간 삭제가 빠른 자료구조 -> 환형 연결 리스트로 구현 가능?
*/
/* ----------<알고리즘>----------
환형연결리스트로 순서 유지하면서 삽입, 삭제 O(1) 구현
메모리:2152KB
시간:96ms
*/
/* -----<주의할 점>-----
환형 연결리스트를 구현하고 싶을 때,
    (X) if(pos == ll.end()) pos++;
    (O) if(pos == ll.end()) pos = ll.begin();

위 작업을 iterator를 증가할 때마다 반드시 해줘야 한다.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    int n, k;
    list<int> ll;
    cin >> n >> k;
    // 1~n 수열로 리스트 만들기
    for(int i = 1; i <= n; i++)
        ll.push_back(i);
    auto pos = ll.begin();  // 첫 번째 원소를 가리킨다.
    cout << '<';
    // 형식에 맞게 반복 출력
    while(ll.size() > 1){
        for(int i = 0; i < k-1; i++){
            pos++;
            if(pos == ll.end()) pos = ll.begin();   // 환형리스트 구현 시, end->begin으로 대체
        }
        cout << *pos << ", " ;
        pos = ll.erase(pos);
        if(pos == ll.end()) pos = ll.begin();
    }
    cout << *pos << '>';
}
