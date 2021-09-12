/* ----------<문제 정의>----------
문제: 조합(오름차순)
입력: n, m(최대 8)
*/
/* ----------<접근법>----------
DFS의 인자로 idx를 넘겨서 이전 방문은 방문하지 않게함
*/
/* -----<알고리즘>-----
dfs(cnt, idx){
    if(cnt == m) <-basecase
        for i : 1~n     <- 방문 순서 무시. 오름차순 조합
            if chk[i] == 1
                cout
        return;
    for(int i = idx; i <= n; i++) // 중복 방문을 피하기 위해 idx(이전의 i에 +1)부터
        comb[cnt] = a[i];
        dfs(cnt+1, i+1) // 중복 방문을 피하기 위한 i+1
}
main
    dfs(0, 1)
*/

#include <iostream>
using namespace std;
int n, m;
int comb[10];
void dfs(int cnt, int idx){
    if(cnt == m){
        for(int i = 0; i < m; i++ ){
            cout << comb[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = idx; i<=n;i++){
        comb[cnt] = i;
        dfs(cnt+1, i+1);
    }
}
int main(){
    cin >> n >> m;
    dfs(0, 1);
}