/* ----------<문제 정의>----------
문제: 검은색 영역의 넓이 구하기
입력: 색종이 수 n(최대 100), 각 색종이 별 왼쪽 변과 거리, 아래 변과 거리
출력: 검은색 영역의 넓이
주의 사항: 색종이가 도화지 밖으로 나가는 경우는 없다.
*/
/* ----------<접근법>----------
색종이 크기는 고정(가로, 세로 10)
색종이 영역을 색칠하는 브루트포스 구현
색종이마다 칠한다.
검은 영역의 총 개수를 구한다.(작은 영역 하나당 크기는 1로 계산)
*/
#include <iostream>
using namespace std;
int board[101][101];
void coloring(int l, int b){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            board[l+i][b+j] = 1;
        }
    }
}

int main(){
    int n, a, b, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        coloring(a, b);
    }
    // 검은색 영역의 총 개수 구하기
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(board[i][j] == 1) cnt++;
        }
    }
    cout << cnt;
}
