/* ----------<문제 정의>----------
문제: 땅 그룹 개수
입력: 2차원 배열
출력: 땅 그룹 개수
*/
/* ----------<알고리즘>----------
DFS/BFS: 시간-O(M*N), 공간-O(M*N)
chk 추가 배열 사용 -> 추가 배열 없이 가능

4방향 배열 정의
chk 방문 여부를 판단하는 2차원 배열 정의
recur 함수
    for 4 방향에 대해서
        다음 원소가 1 && 다음 원소에 방문하지 않았으면
            다음 원소 chk
            recur 
            (chk 취소할 필요 없음)
main 함수
    2차원 배열 순회
        방문하지 않았으면
            체크
            recur
*/

class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int chk[301][301];
    int cnt;
    int row;
    int col;
    void dfs(int x, int y, vector<vector<char>>& grid){
        for(int i = 0; i < 4; i++){
            if(x+dx[i] >= 0 && y+dy[i] >= 0 && x+dx[i] < row && y+dy[i] < col){
                if(grid[x+dx[i]][y+dy[i]] != '1' || chk[x+dx[i]][y+dy[i]] != 0)
                    continue;
                chk[x+dx[i]][y+dy[i]] = 1;
                dfs(x+dx[i],y+dy[i],grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        row = grid.size();
        col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                
                if(grid[i][j] == '1' && chk[i][j] == 0){
                    chk[i][j] = 1;
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};