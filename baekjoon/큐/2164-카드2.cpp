/* ----------<문제 정의>----------
문제: 카드 버리고 뒤에 삽입하는 작업 반복 시뮬레이션
입력: n(최대 50만)
출력: 제일 마지막에 남게 되는 카드 숫자
*/
/* ----------<접근법>----------
카드1과 문제 같음. 입력 크기가 훨씬 증가함.
50만 + 25만(절반은 다시 삽입해서 버리므로)
절대 1초 안 넘어간다고 예상
*/
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    queue<int> q;
    cin >> n;
    // 큐에 일련의 수 추가
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while(!q.empty()){
        if(q.size() == 1) cout <<q.front();
        q.pop();
        if(!q.empty()){
            q.push(q.front());
            q.pop();
        }
    }
}