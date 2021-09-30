/* ----------<문제 정의>----------
문제: 양쪽에서 봤을 때 보이는 트로피 찾아내기
입력: 트로피 개수 n(최대 50), n개의 트로피 높이
출력: 각 방향에서 보이는 트로피 개수
*/
/* ----------<접근법>----------
막대기 문제와 같음
왼쪽->오른쪽, 왼쪽<-오른쪽
한번씩 기존 최댓값보다 큰 개수 구하기
*/
#include <iostream>
using namespace std;
int main(){
    int n, cnt = 0;
    int max_val = -1;
    int trophy[51];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> trophy[i];
    }
    for(int i = 0; i < n; i++){
        if(trophy[i] > max_val){
            max_val = trophy[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
    max_val = -1;
    cnt = 0;
    for(int i = 0; i < n; i++){
        if(trophy[n-i-1] > max_val){
            max_val = trophy[n-i-1];
            cnt++;
        }
    }
        cout << cnt;
}