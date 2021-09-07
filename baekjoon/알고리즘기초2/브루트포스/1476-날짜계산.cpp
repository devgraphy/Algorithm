/* ----------<문제 정의>----------
문제: 브루트포스
입력: 지구, 해, 달(15 * 28 * 19)
출력: 날짜 계산 결과 값
*/
/* ----------<접근법>----------
규칙성을 못 찾겠음
일일이 수를 높여가면서 확인
*/
/* ----<알고리즘>----
while(1)
    3개 원소 1씩 증가 및 초기화
    3개 원소 모두 일치하는지 확인
        break

이 풀이 방법의 시간 복잡도는 E S M 연도의 모든 경우를 다 구해보는 것일 것이다. 
e, s, m이라는 각각의 변수를 두고 각각 증가시키면 되기때문에 시간복잡도는 O(N)이다. 
그리고 E S M 연도를 모두 구해보는 경우의 수는 15 x 28 x 19 = 7,980이다.
*/
#include <iostream>
using namespace std;
int main(){
    int a[3] = {0,};
    int b[3];
    bool comp = false;
    int cnt = 1;
    for(int i = 0; i < 3; i++){
        cin >> b[i];
    }
    while(1){
        comp = false;
        // 1 1 1 부터 시작
        for(int i = 0; i < 3; i++){
            a[i]++;
            if(a[0] == 16) a[0] = 1;
            if(a[1] == 29) a[1] = 1;
            if(a[2] == 20) a[2] = 1;
        }
        for(int i = 0; i < 3; i++){
            if(a[i] != b[i]) {
                comp = true;
                break;
            }
        }
        if(comp == false) break;
        cnt++;
    }
    cout << cnt;
}