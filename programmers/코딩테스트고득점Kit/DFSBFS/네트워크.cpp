/* ----------<문제 정의>----------
문제: 직간접적으로 연결되어 있는 네트워크 그룹 개수 찾기
입력: 컴퓨터 대수 1<=n<=200(컴퓨터는 0부터 n-1까지 표현), 2차원 배열  
출력: 네트워크 그룹 개수
*/
/* ----------<알고리즘>----------
why dfs? 가능한한 연결된 모든 정보를 체크한다. 이를 위해 dfs 또는 bfs bruteforce로 그룹을 형성한다.

[dfs]
    basecase: 별도 설정없이 연결정보가 없으면 알아서 for문 끝나면 끝나도록 한다.
    computers 순회하면서
        해당 노드에서 연결된 정보 확인(연결되어 있으면)
            방문하지 않았으면
                방문 체크
                dfs(연결된 번호 전달)
                -방문 하고 나와서도 방문 체크 유지-
        
[main]
    그래프 세로 정보를 기준으로 가로의 연결된 정보를 순회
        연결된 정보가 있으면(자기 자신도 카운트에 포함)
            방문 여부 확인(방문하지 않았으면)
                방문 체크
                dfs(연결된 번호 전달)
                cnt++;(항상 시작점에서 네트워크 개수를 하나 추가한다.)
*/

#include <string>
#include <vector>

using namespace std;
int chk[202][202];
int cnt = 0;
void dfs(int x,int n, vector<vector<int>> computers){
    for(int i = 0; i < n; i++){
        if(computers[x][i] == 1){
            if(chk[x][i] == 1)
                continue;
            chk[x][i] = 1;
            dfs(i, n, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j] == 1){
                if(chk[i][j] == 1)
                    continue;
                chk[i][j] = 1;
                dfs(j, n, computers);
                cnt++;
            }
        }
    }
    return cnt;
}