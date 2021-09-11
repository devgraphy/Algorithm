/* ----------<문제 정의>----------
문제: 중복 순열
입력: n, m (최대 7)
주의사항: 수열은 사전 순 증가하는 순서 출력
*/
/* ----------<접근법>----------
정렬, dfs bruteforce, for-0, no visit check
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[10];  // 입력 정보
int perm[10];   // 순열 정보
void dfs(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++)
            cout << perm[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        perm[cnt] = a[i];
        dfs(cnt+1);        
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    dfs(0);
}