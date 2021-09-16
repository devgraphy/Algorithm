/* ----------<문제 정의>----------
문제: 브루트포스(BFS), 구현
입력: l(최대 300)
*/
/* ----------<접근법>----------
최소 이동 수 이므로 DFS보단 BFS가 적합해 보임. 큐 이용
*/
/* -----<알고리즘>-----
BFS의 거리를 기록하는 별도의 체스판 생성 필요. 시작점은 0으로 초기화

시작점 큐에 삽입
while 큐가 빌때 까지
    temp = q.top()
    q.pop()
    for i = 0; i < 8    // 8방향 탐색
        체스판을 넘지 않으면
            목적지라면 temp의 거리기록판 +1값을 출력하고 종료
            아닐면 계속 기록하면서 진행
*/
#include <iostream>
#include <queue>
using namespace std;
int dx[8] = {1, 2, 2 , 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2 ,-1 , 1, 2};
int main(){
    int t, l;   // 테스트케이스 수, 한 변이 길이
    int a, b;   // 나이트 위치
    int x, y;   // 목적지
    int dist[305][305];
    bool prt = false;   // 해당 케이스에서 출력 여부
    queue <pair<int, int>> q;
    
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> l;
        cin >> a >> b >> x >> y;    // 시작점, 목적지 입력
        prt = false;
        for(int i = 0; i < l; i++){
            fill_n(dist[i], l, -1);    // 거리기록판 -1로 초기화. 0은 시작점으로써 방문의미도 가져야 함
        }
        // q 초기화
        while(!q.empty()) q.pop();
        if(a==x && b==y){
            cout << 0 << '\n';
            continue;
        }
        q.push(make_pair(a, b));
        pair<int, int> temp;
        dist[a][b] = 0;
        int temp_x, temp_y;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            // 8방향 탐색
            for(int i = 0; i < 8; i++){
                temp_x = temp.first+dx[i];
                temp_y = temp.second+dy[i];
                // 이동한 곳이 체스판 크기를 넘어가면 다른 방향 탐색
                if(temp_x < 0 || temp_y < 0 || temp_x >= l || temp_y >=l) continue;
                // 이동한 곳이 목적지라면 거리 출력하고 종료
                if(temp_x == x && temp_y == y){
                    cout << dist[temp.first][temp.second]+1 << '\n';
                    prt = true;
                    break;
                }
                // 그게 아니라면
                else{
                    // 거리 기록
                    dist[temp_x][temp_y] = dist[temp.first][temp.second] + 1;
                    q.push(make_pair(temp_x, temp_y));
                }
            }
            if(prt == true) break;
        }
        
    }
}