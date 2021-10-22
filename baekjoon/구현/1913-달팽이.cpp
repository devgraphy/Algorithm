/* ----------<문제 정의>----------
문제: 달팽이 모양으로 수를 채운 2차원 배열 생성
입력: 보드판 길이 n(최대 999), 찾고자 하는 수 k
출력: n*n 크기의 2차원 배열과 k의 좌표
*/
/* ----------<접근법>----------
0,0부터 시작해서 보드판 크기를 초과하거나 0이 아닌 수가 나오면 방향을 전환한다.
*/
#include <iostream>
using namespace std;
int n, k, y, x, dir, rety, retx;
int board[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(){
    cin >> n >> k;
    for(int i = n*n; i >= 1; i--){
        board[y][x] = i;
        if(i == k) {
            rety = y+1;
            retx = x+1;
        }
        if(x + dx[dir] < 0 || y + dy[dir] < 0 || x + dx[dir] >= n || y + dy[dir] >= n || board[y+dy[dir]][x+dx[dir]] != 0){
            dir = (dir + 1) % 4;
        }
        x = x + dx[dir];
        y = y + dy[dir];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << rety << " " << retx;
}