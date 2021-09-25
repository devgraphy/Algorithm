/* ----------<문제 정의>----------
문제: 2차원 배열 브루트포스, 각 행과 열에서 2개 이상의 연속된 공간이 있는지 파악
입력: n(최대 100), 길이 n인 2차원 배열
출력: 가로, 세로 각각 길이 2가 되는 공간의 수
주의 사항: 각 행과 열에서 2개 이상의 연속된 공간이 여러 개 존재할 수 있음. 길이가 2이상이라면 길이가 어떻든 하나의 공간으로 간주
*/
/* ----------<접근법>----------
연속된 공간은 DFS로 구현하여 하나의 공간으로 파악
*/
#include <iostream>
using namespace std;
int n, hor = 0, ver = 0;
int dx[2] = {0, 1};
int dy[2] = {1, 0};
char a[105][105];
int chk[105][105];

void dfs(int x, int y, int dir, int cnt){
    // basecase
    int temp_x = x + dx[dir];
    int temp_y = y + dy[dir];
    // 짐이 있거나 방을 넘어가면 리턴
    if(a[temp_x][temp_y] == 'X' || temp_x >= n || temp_y >= n || chk[temp_x][temp_y] == 1){
        if(dir == 0 && cnt >= 1) hor++;
        else if(dir == 1 && cnt >= 1) ver++;
        return;
    }
    chk[temp_x][temp_y] = 1;
    dfs(temp_x, temp_y, dir, cnt+1);
}
int main(){   
    cin >> n;
    // 2차원 배열 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    // 원소 하나씩 순회하며 가로, 세로 누울 공간 파악
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           if(a[i][j]=='.' && chk[i][j] == 0) {
               chk[i][j] = 1;
               dfs(i, j, 0, 0);
           }
        }
    }
    for(int i = 0; i < n; i++)
        fill_n(chk[i], n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           if(a[i][j]=='.' && chk[i][j] == 0) {
               chk[i][j] = 1;
               dfs(i, j, 1, 0);
           }
        }
    }
    cout << hor << " " << ver;
}
