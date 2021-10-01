/* ----------<문제 정의>----------
문제: 카드를 한 장씩 버리고, 그 다음 윗 장을 아래로 옮기는 작업을 반복한다.
*/
/* ----------<접근법>----------
한 쪽에선 빼고, 한 쪽에선 넣는 자료구조인 큐를 이용한다.

한 번은 빼면서 출력
큐가 비어있지 않다면 윗장의 카드를 맨 아래에 옮기는 작업을 마지막 카드가 남을 때까지 반복한다.
*/

#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    queue<int> q;
    cin >> n;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
        if(!q.empty()){
            q.push(q.front());
            q.pop();
        }
    }
}