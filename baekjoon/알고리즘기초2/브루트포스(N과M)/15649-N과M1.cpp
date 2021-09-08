/* ----------<문제 정의>----------
문제: 순열 구하기
*/
/* ----------<접근법>----------
dfs 브루트포스
*/
/* -----<알고리즘>-----
chk 배열
dfs 함수(cnt)
    if cnt == m
        return
    for int i = 0;  i < n; i++
        if not visit
            chk i = 1
            dfs
            chk i = 0
*/
#include <iostream>
using namespace std;
int n, m;
int chk[10];
void dfs(int cnt){
    if(cnt == m){
        for(int i = 1; i <= n; i++){
            if(chk[i] == 1)
                cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(chk[i] == 0){
            chk[i] = 1;
            dfs(cnt + 1);
            chk[i] = 0;
        }
    }
}
int main(){
    cin >> n >> m;
    dfs(0);
}