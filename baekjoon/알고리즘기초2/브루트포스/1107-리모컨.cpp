/* ----------<문제 정의>----------
문제: 브루트포스, 최소 이동수 찾기
입력: 목적 채널(최대 50만), 고장난 채널 수, 고장난 채널
*/
/* ----------<접근법>----------
유사 문제:
이동 버튼 0~9, +, -

주의사항:
1. 0~9로 직접 접근하는 것이 항상 빠른 접근은 아니다.
2. n을 한참 초과하는 경우에 대해서 처리
*/
/* -----<알고리즘>-----
dfs(cnt, ch)    // cnt: 채널 이동수, ch: 햔재 채널
    basecase: 목적 채널에 도달

*/
#include <iostream>
#include <climits>
using namespace std;
int n, m;
int btn_able[10];
int chk[500001]; // 중복 방문 방지용
int min_val = INT_MAX;
void dfs(int cnt, int ch){
    if(ch == n){    // 목적 채널에 도달
        if(min_val > cnt)
            min_val = cnt;
        return;
    }
    else if(ch < n){    // 목적 채널 미달
        // 직접 접근 - 목적채널에서 가장 가까운 위 아래 값으로 이동
            // 큰 값부터 확인하면서 미도달이면 큰 값 누르고 break
            // 초과했을 때 미도달할 때까지 내려가기
                // 끝까지 미도달한 값이 안 나타날 수 있으므로 갱신해야함
        int stand;
        for(int i = 9; i >= 0; i--){
            if(btn_able[i] == 1){ // 클릭 가능한 버튼 중에서
                if(ch*10+i > n){    // 목적채널 초과
                    stand = i;
                }
                else if(ch*10 + i<= n){               // 목적채널 미달 순간
                    dfs(cnt+1, ch*10+i);
                    break;
                }    
            }
            if(i == 0 && chk[ch*10+stand] == 0){
                // 끝까지 else에 걸리지 못한 경우 무조건 한 번은 방문하도록
                dfs(cnt+1, ch*10+stand);
            }

        }
        // +
        dfs(cnt+1, ch+1);
    }
    else if(ch > n){ //목적 채널 초과-> 세부 조정(버튼 직접 접근은 제외)
        // -
        dfs(cnt+1, ch-1);
    }
}
int main(){
    int temp;
    cin >> n >> m;
    fill_n(btn_able, 10, 1);
    // 가능 버튼
    for(int i = 0; i < m; i++){
        cin >> temp;
        btn_able[temp] = 0;
    }
    chk[100] = 1;
    dfs(0, 100);
    cout << min_val << endl;
}