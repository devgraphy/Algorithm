/* ----------<문제 정의>----------
문제: 특정 순열의 다음 순열
입력: n(최소1, 최대 1만)
출력: 순열(사전순으로 마지막에 오는 순열인 경우에는 -1 출력)

주의사항: 수열의 특정 위치를 임의로 바꾼다고해서 해결되지 않음.
*/
/* ----------<접근법>----------
순열 완성 여부 확인
    일치한 순열이 만들어진 상황 이후 바로 다음 순열인 경우 그 순열 출력
    순열 일치 여부 확인
        방법1.매번 다 완성하고 확인(최악의 경우 만*만=억. 예상대로 시간 초과)
        방법2.백트래킹  <- 개선 시도
일치하면 체크
그다음 순열 찾으면서 체크되어있으면 출력하고 종료
*/

#include <iostream>
using namespace std;
int n;
int a[10001];
int perm[10001];
int chk[10001]; // 중복 방지
bool cor = false;   // 0: 불일치 1: 일치
bool prt = false;   // 프린트 유무
void dfs(int cnt){
    if(cnt == n){
        if(cor == true){   // 그다음 순열에서 바로 출력
            prt = true;
            for(int i = 0; i < n; i++)
                cout << perm[i] << " ";
            cor = false;
            return;
        }
        for(int i = 0; i < n; i++){
            if(a[i] != perm[i]) return; // 함수 리턴 
        }
        cor = true;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(chk[i] == 0){
            chk[i] = 1;
            perm[cnt] = i;
            dfs(cnt+1);
            chk[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0);
    if(prt == false)
        cout << -1;
}