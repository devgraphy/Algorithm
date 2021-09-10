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
using namespace std;
int n, m, v;
int a[1001][1001];
int chk[1001];
void dfs(int v){
    for(int i = 1; i <= n; i++){
        if(a[v][i] == 0) continue;  // 연결 정보 확인
        if(chk[i] == 1) continue;
        chk[i] = 1;
        // cout << v << " : " << i << endl; // dfs 흐름을 알 수 있는 테스트 코드
        cout << i << " ";
        dfs(i);
    }
}
void bfs(int tv){

}
int main(){
    cin >> n >> m >> v;
    int temp1, temp2;
    for(int i = 0; i < m; i++){
        cin >> temp1 >> temp2;
        a[temp1][temp2] = 1;
        a[temp2][temp1] = 1;
    }
    chk[v] = 1;
    cout << v << " ";
    dfs(v);
    //bfs(v);
}