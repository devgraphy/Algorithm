/* ----------<문제 정의>----------
문제: DFS, BFS 구현
입력: (입력으로 주어지는 간선은 양방향이다.)
*/
/* -----<반례>-----
더 이상 방문할 수 있는 점이 없는 경우 종료한다.
- 종료 시점을 정해주지 않았다.
- 또는 계속 해제하기 때문에 또 다시 방문하는 것이다.
*/
#include <iostream>
#include <queue>
using namespace std;
int n, m, v;
int a[1001][1001];
int chk[1001];
queue<int> q;
void dfs(int v){
    chk[v] = 1;
    cout << v << " ";
    for(int i = 1; i <= n; i++){
        if(a[v][i] == 0) continue;  // 연결 정보 확인
        if(chk[i] == 1) continue; 
        // cout << v << " : " << i << endl; // dfs 흐름을 알 수 있는 테스트 코드
        dfs(i);
    }
}
void bfs(int v){
    q.push(v);
    chk[v] = 1;
    int temp;
    while(!q.empty()){
        // v와 연결된 정점 추가
        temp = q.front();
        q.pop();
        cout << temp << " ";
        for(int i = 1; i <= n; i++){
            if(a[temp][i] == 1 && chk[i] == 0){
                q.push(i);
                chk[i] = 1; // q에 넣는 시점에 방문 체크(O) vs q에서 꺼내는 시점에 방문 체크(X)-꺼내는 동안 다른 정점에 의해 중복방문
            }
        }
    }
}
int main(){
    cin >> n >> m >> v;
    int temp1, temp2;
    for(int i = 0; i < m; i++){
        cin >> temp1 >> temp2;
        a[temp1][temp2] = 1;
        a[temp2][temp1] = 1;
    }
    dfs(v);
    cout << "\n";
    for(int i = 0; i <= n; i++){    // 초기화
        chk[i] = 0;
    }
    bfs(v);
}