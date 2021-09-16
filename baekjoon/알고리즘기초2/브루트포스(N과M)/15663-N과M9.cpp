/* ----------<문제 정의>----------
문제: 중복된 수가 포함된 n개의 수 + 순열(중복된 수는 다른 수로 취급하여 하나의 수열에 표현할 수 있지만, 똑같은 수열이 중복해서 나타날 수 없다.) 
입력: n, m(최대 8)
출력: 중복 수열 없이 출력

주의사항: 중복된 수는 다른 수로 취급하여 하나의 수열에 표현할 수 있지만, 똑같은 수열이 중복해서 나타날 수 없다.
*/
/* ----------<접근법(ref)>----------
이전 수열의 마지막 원소를 비교해서 중복 수열인지 확인
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[10];
int chk[10];
int perm[10];
int pre[10];   // 바로 직전 수열
void dfs(int cnt){
    if(cnt == m){
        if(pre[m-1] != perm[m-1]){
            for(int i = 0; i < m;i++){
                cout << perm[i] << " ";
            }
            pre[m-1] = perm[m-1];
            cout << '\n';
        }
        
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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    dfs(0);
}