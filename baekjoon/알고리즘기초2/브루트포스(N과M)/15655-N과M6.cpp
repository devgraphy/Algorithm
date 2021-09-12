/* ----------<문제 정의>----------
문제: 조합(중복x)
입력: n, m(최대 10)
*/
/* ----------<접근법>----------
dfs bruteforce, for-idx, visit check
dfs(cnt, idx)
    cnt - 선택 개수이면서 방문 순서 정보를 가짐
    for idx 정보 사용 <- 앞선 정보를 기준으로 만들 수 있는 모든 경우의 수를 만들어 나가므로 제외
        dfs(cnt+1, i+1) // 중복 방문을 피하기 위한 i+1
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[10];  // 입력 정보
int comb[10];   // 반복문 횟수 절감 목적
void dfs(int cnt, int idx){
    if(cnt == m){
        for(int i = 0; i<m;i++){
            cout << comb[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = idx; i < n;i++){
        comb[cnt] = a[i];
        dfs(cnt+1, i+1);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    dfs(0, 0);
}