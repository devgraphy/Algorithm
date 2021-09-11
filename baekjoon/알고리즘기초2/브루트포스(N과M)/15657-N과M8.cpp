/* ----------<문제 정의>----------
문제: 중복조합
입력: n, m(최대 8)
*/
/* ----------<접근법>----------
정렬, dfs bruteforce, for-idx, no visit check
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[10];
int comb[10];
void dfs(int cnt, int idx){
    if(cnt == m){
        for(int i = 0; i < m; i++)
            cout << comb[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = idx; i < n; i++){
        comb[cnt] = a[i];
        dfs(cnt + 1, i);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    dfs(0, 0);
}