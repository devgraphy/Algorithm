/* ----------<문제 정의>----------
문제: DFS, BFS 구현
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
        cout << i << " ";
        dfs(i);
        chk[i] = 0;
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
    cout << v << " ";
    chk[v] = 1;
    dfs(v);
    chk[v] = 0;
    //bfs(v);
}