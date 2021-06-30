/* ----------<문제 정의>----------
문제: 말 그대로 행렬 테두리 회전하기
입력: 행렬 크기, 영역 범위 배열
출력: 각 회전마다의 최소값
*/
/* ----------<알고리즘>----------
simulation (행렬 원소를 직접 이동하는 방법 빼고는 방법이 떠오르지 않음)
(값을 밀어내는 방식, 끌어오는 방식 모두 가능)

행렬 생성
회전하면서 최솟값 갱신(x1,y1,x2,y2)
    (상단 가로, 하단 가로, 오른쪽 세로, 왼쪽 세로 방향을 구분해서 회전)
    (이전 값을 따로 저장해놓고 현재 값을 이전 값으로 갱신)
    상단가로(오른쪽방향)
    오른쪽 세로(하향)
    하단 가로(왼쪽방향)
    왼쪽 세로(상향)
회전마치면 최솟값 push
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int a[105][105];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int temp;
    int static_pos;
    int num = 1;
    int minval;
    //행렬 생성
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            a[i][j] = num++;
        }
    }
    for(int c = 0; c < queries.size(); c++){
        int before = a[queries[c][0]][queries[c][1]]; // 왼쪽상단으로 초기화
        int minval = before;
        // 상단가로(x1 고정, y1->y2)
        for(int i = queries[c][1]+1; i <= queries[c][3]; i++){
            static_pos = queries[c][0];
            /*이동*/
            temp = a[static_pos][i];   
            a[static_pos][i] = before;
            before = temp;
            if(minval > temp)
                minval = temp;
        }
        // 오른쪽세로(y2 고정, x1->x2)
        for(int i = queries[c][0]+1; i <= queries[c][2];i++){
            static_pos = queries[c][3];
            /*이동*/
            temp = a[i][static_pos];   
            a[i][static_pos] = before;
            before = temp;
            if(minval > temp)
                minval = temp;
        }       
        // 하단가로(x2 고정, y2-> y1)
        for(int i = queries[c][3]-1; i>= queries[c][1]; i--){
            static_pos = queries[c][2];
            /*이동*/
            temp = a[static_pos][i];   
            a[static_pos][i] = before;
            before = temp;
            if(minval > temp)
                minval = temp;
        }   
        // 왼쪽세로(y1 고정, x2->x1)
        for(int i = queries[c][2]-1; i>= queries[c][0]; i--){
            static_pos = queries[c][1];
            /*이동*/
            temp = a[i][static_pos];   
            a[i][static_pos] = before;
            before = temp;
            if(minval > temp)
                minval = temp;
        }
        answer.push_back(minval);
    }
    return answer;
}