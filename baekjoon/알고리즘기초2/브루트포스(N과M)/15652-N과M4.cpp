/* ----------<문제 정의>----------
문제: 조합 + 중복 선택 가능 = 중복 조합
- 중복 조합: 서로 다른 {\displaystyle n}n개의 원소에서 중복을 허락하여 k개를 뽑는 경우의 수이다. 이는 크기가 {\displaystyle n}n인 집합에서, 크기가 {\displaystyle k}k인 중복집합을 고를 수 있는 가짓수와 같다.
그 값은 n_H_k = k+(n-1)_C_k이다.
유사 문제: N과M(2) + 중복 선택(방문 체크 필요X)
입력: n, m (최대 8)
*/
/* ----------<접근법>----------
조합 알고리즘(dfs bruteforce)에 중복 선택 가능(no visit check)
조합은 오름차순 정렬했을 때 맨 앞에서부터 하나씩 선택 대상에서 제외하기 위해 for문에 idx 정보가 쓰이는게 핵심
dfs의 파라미터
- cnt: 조합 구성 개수
- idx: 앞에서 선택한 것은 선택 대상에서 제외하기 위함

basecase 처리
    for문으로 방문 순서 상관 없이 출력.
    앞에 것이 항상 크게 방문하게 되어 있음
    선택된 수를 담기 위해 별도 공간은 반드시 필요하다.
        chk 배열->반복 많음
        perm 배열->반복 없음. 순서 의미를 가짐
*/
#include <iostream>
using namespace std;
int n, m;
int comb[10];
void dfs(int cnt, int idx){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << comb[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = idx; i <= n; i++){
        comb[cnt] = i;
        dfs(cnt+1, i);
    }
}
int main(){
    cin >> n >> m;
    dfs(0, 1);
}