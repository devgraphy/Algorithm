/* 모델링
1. 문제: 2차원 배열에서 봉우리(상하좌우보다 높은 곳) 찾기
2. 입력: 1 <= N(열,행 길이) <= 50
3. 알고리즘
- 1행 1열부터 행, 열 각각 N만큼 입력을 받는다.(테두리에 0으로 채워진 한 줄이 필요하다.-최대 길이 52)
- 각 원소마다 봉우리인지 체크한다.(봉우리이면 cnt를 증가시킨다.)
*/

#include <iostream>
using namespace std;
int a[52][52];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = { 0, 1, 0, -1};
int main(){
    int n;
    int chk = 0, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){    // 2차원 배열 입력
        for(int j = 1; j <=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){    // 봉우리 탐색
        for(int j = 1; j <=n; j++){
            chk = 0;
            for(int k = 0; k < 4; k++){
                if(a[i+dr[k]][j+dc[k]] >= a[i][j]){
                    chk = 1;
                    break;
                }
            }
            if(chk == 0)
                cnt++;
        }
    }
    cout << cnt;
}