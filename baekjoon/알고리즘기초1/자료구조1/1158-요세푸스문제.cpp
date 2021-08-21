/* ----------<문제 정의>----------
문제: 입력 순서를 유지하면서 중간 요소를 삭제하는 문제(queue)
입력: N, K
출력: (N,K) 요세푸스 순열 출력
*/
/* ----------<알고리즘>----------
풀이 시간: 20분
메모리:2020KB
시간:68ms

큐를 이용해서 입력 순서를 유지하면서 중간 요소 삭제하기
큐에 1 ~ n 삽입
(큐를 하나만 이용해보자)
첫 번째 - k-1 번째 수까지 큐에 다시 삽입, k 번째는 pop (4 5 6 7 1 2)
두 번째 - 첫번째 큐상태에서 k-1번째 수까지 큐에 다시 삽입, k 번째는 pop (7 1 2 4 5)
...
*/
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, k;
    queue<int> q;
    cin >> n >> k;
    // 1 ~ n 순서대로 큐에 삽입
    for(int i = 1; i <= n; i++)
        q.push(i);
    cout << '<';
    // 문자열 형식 때문에 어쩔 수 없는 코드 중복
    for(int j = 0; j < k-1; j++){
            q.push(q.front());
            q.pop();
        }
    cout << q.front();
    q.pop();
    for(int i = 0; i < n-1; i++){   // 앞에서 한번 수행했으므로 n-1번
        // 앞에서부터 k-1번째 수까지 큐 뒤에 삽입
        for(int j = 0; j < k-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout << ", "<< q.front();
        q.pop();
    }
    cout << '>';
}