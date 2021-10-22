/* ----------<���� ����>----------
����: ������ ������� ���� ä�� 2���� �迭 ����
�Է�: ������ ���� n(�ִ� 999), ã���� �ϴ� �� k
���: n*n ũ���� 2���� �迭�� k�� ��ǥ
*/
/* ----------<���ٹ�>----------
0,0���� �����ؼ� ������ ũ�⸦ �ʰ��ϰų� 0�� �ƴ� ���� ������ ������ ��ȯ�Ѵ�.
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