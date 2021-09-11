/* ----------<문제 정의>----------
문제: 순열 + 중복 선택 가능 = 중복 순열
- 중복순열: n 개의 서로 다른 원소 중에서 중복을 허용하여 r개를 뽑아서 한 줄로 나열하는 경우의 수
유사 문제: N과M1(순열) + 중복해서 선택 가능
입력: n, m(최대 7)
*/
/* ----------<접근법>----------
dfs로 브루트포스를 구현한다.
for문으로 순차적으로 방문하되 순열이기 때문에 idx 정보는 필요없다.
중복 선택이 가능하기 때문에 visit 정보 필요없다.
방문한 순서 정보는 가지고 있어야 하기 때문에 방문 순서 정보가 담긴 cnt로 별도의 배열에 값을 담는다.
*/
/* -----<알고리즘>-----
dfs(cnt)
    if cnt == m        <-basecase
        for i=0; i<m;i++
            cout perm[i]

    for i = 1; i <= n; i++
        perm[cnt] = i   // 방문 순서 정보를 알기 위해 별도의 공간을 사용한다.
        // 중복 선택 가능하므로 방문 고려하지 않는다.
        dfs(cnt+1)
*/
#include <iostream>
using namespace std;
int n, m;
int perm[10];
void dfs(int cnt){
    if(cnt == m){   // basecase
        for(int i = 0; i < m; i++)
            cout << perm[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        perm[cnt] = i;
        dfs(cnt+1);
    }
}
int main(){
    cin >> n >> m;
    dfs(0);
}