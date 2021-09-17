/* ----------<문제 정의>----------
문제: 중복된 수가 포함된 n개의 수 + 순열(중복된 수는 다른 수로 취급하여 하나의 수열에 표현할 수 있지만, 똑같은 수열이 중복해서 나타날 수 없다.) 
입력: n, m(최대 8)
출력: 중복 수열 없이 출력

주의사항: 중복된 수는 다른 수로 취급하여 하나의 수열에 표현할 수 있지만, 똑같은 수열이 중복해서 나타날 수 없다.
*/
/* ----------<접근법(ref)>----------
정렬된 상태의 입력 수열에서 현재 인덱스의 수와 이전 인덱스와 비교하여 같으면 제외한다.
즉, "한 번 나오는 수는 해당 수열에서 나오지 않도록 한다." 는 아이디어이다.
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
        for(int i = 0; i < m;i++){
            cout << perm[i] << " ";
        }
        cout << '\n';
        return;
    }
    int x = 0;                          // ☝접근법 핵심
    for(int i = 0; i < n; i++){
        if(chk[i] == 0 && a[i] != x){   // ☝접근법 핵심
            chk[i] = 1;
            perm[cnt] = a[i];
            x = perm[cnt];              // ☝접근법 핵심
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