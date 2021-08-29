/* ----------<문제 정의>----------
문제: 2차원 배열 조합 구하기(이 문제는 인접한 두칸), 연속값 길이 구하기
입력: 보드 크기(최대 50), 보드판 입력값(C,P,Z,Y)
출력: 가장 긴 연속 부분(행 또는 열)의 길이
주의 사항: 2차원 배열 주소 전달 방법, 꼭 한번 바꿔야 하는건지?
*/
/* ----------<알고리즘>----------
풀이 시간: 40분 초과
두 개의 칸을 선택하면 되므로 이중 for문으로 브루트포스를 구현할 수 있다.

두 개의 칸 선택 후 교환
    각 행 또는 열마다 연속값이 가장 큰 값을 구한다.
        (다른 문자가 나오거나 보드판이 끝날 경우에 최댓값과 비교한다.)
    교환한 칸 초기화
*/
/* 새롭게 안 것
    - swap 함수 의 존재
    - 2차원배열을 매개변수로 전달할 때 함수가 넘겨받은 변수 자체로부터 배열 차원들을 알아낼 수 있는 방식으로 전달해주어야 한다.
*/
#include <iostream>
#include <climits>
using namespace std;
char a[55][55]; // 공백
int sz;
int maxlen = INT_MIN;
void countColumnCandy(char (*a)[55]){
    for(int m = 0; m < sz; m++){
        int templen = 0;
        for(int n = 0; n < sz; n++){
            if(a[m+1][n] != ' '){  // 그 다음이 공백이 아닌 경우
                if(a[n][m] == a[n+1][m]){ // 그 다음 칸과 값이 같다.
                    templen++;
                }
                else{               // 다음 칸과 다른 경우
                    if(maxlen < templen){
                        maxlen = templen;
                    }
                    templen = 1;    // 다음값의 다음값이 공백일 경우
                }
            }
            else{   // 그 다음이 공백인 경우
                    // 현재가 언제 부터 지속되어 왔는지 모르므로 이전에 값이 결정되어야 한다.
                    if(maxlen < templen) maxlen = templen;
            }
        }
    }
}
void countRowCandy(char (*a)[55]){
    for(int m = 0; m < sz; m++){
        int templen = 1;
        for(int n = 0; n < sz; n++){
            if(a[m][n+1] != ' '){  // 그 다음이 공백이 아닌 경우
                if(a[m][n] == a[m][n+1]){ // 그 다음 칸과 값이 같다.
                    templen++;
                }
                else{               // 다음 칸과 다른 경우
                    if(maxlen < templen){
                        maxlen = templen;
                    }
                    templen = 1;    // 초기화
                }
            }
            else{   // 그 다음이 공백인 경우
                // 현재가 언제 부터 지속되어 왔는지 모르므로 이전에 값이 결정되어야 한다.
                if(maxlen < templen) maxlen = templen;
            }
        }
    }
}

int main(){
    cin >> sz;
    // 보드 입력
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            cin >> a[i][j];
        }
    }
    // 두 칸 선택
    for(int i = 0; i < sz; i++){    // 
        for(int j = 0; j < sz-1; j++){
            // 행 단위 두 칸 교환. 행은 sz끝까지 가야함
            if(a[i][j] != a[i][j+1]){
                //cout << "row " << i << ":" << j<< endl;
                swap(a[i][j], a[i][j+1]);
                // 행단위 길이 파악
                countRowCandy(a);
                // 열단위 길이 파악
                countColumnCandy(a);
                swap(a[i][j], a[i][j+1]);
            }  
        }
    }
    for(int i = 0; i < sz; i++){    // 
        for(int j = 0; j < sz-1; j++){
            // 열 단위 두 칸 교환. 행은 sz끝까지 가야함
            if(a[j][i] != a[j+1][i]){
                //cout << "col " << j << " : " << i<< endl;
                swap(a[j][i], a[j+1][i]);
                // 행단위 길이 파악
                countRowCandy(a);
                // 열단위 길이 파악
                countColumnCandy(a);
                swap(a[j][i], a[j+1][i]);
            }
        }
    }
    cout << maxlen;
}
