/* ----------<문제 정의>----------
문제: 순열(중복x)
입력: n, m (최대 8)
*/
/* ----------<접근법>----------
수열은 사전 순으로 증가하는 순서로 출력해야 한다. -> 우선 정렬 필요

dfs 브루트포스
    for i = 0 <-순열이므로 idx 정보 필요없음
        perm[i] <-방문 순서정보에 따라 순열 정보 저장
        visit   <- 중복 방지하기 위함
        dfs
        visit cancle
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[10];  // 입력된 수 저장 공간
int chk[10];    // 방문 확인용
int perm[10];   // 순열 구성 공간
void dfs(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++)
            cout << perm[i] <<" ";
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(chk[i] == 0){
            chk[i] = 1;
            perm[cnt] = a[i];
            dfs(cnt+1);
            chk[i] = 0;
        }
    }
}
int main(){
    cin >> n >> m;
    // 수 입력
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    dfs(0);
}