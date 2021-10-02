/* ----------<문제 정의>----------
문제: 회전하면서 k번째 사람 제거
*/
/* ----------<접근법>----------
큐에서 삽입해놓고 
while k 추출하고 큐가 빌 때까지 반복
    for k번째가 나올 때까지 큐 뒤에 추가
*/
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, k;
    int cnt = 1;
    queue<int> q;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    cout << "<";
    while(q.size() > 1){
        for(int i = 0 ; i < k-1; i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() <<", ";
        q.pop();
    }
    cout << q.front() << ">"; 
}