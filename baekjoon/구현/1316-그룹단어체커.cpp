/* -----<문제 정의>-----
그룹 단어-단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 의미

문제: 연속하지 않은 문자 찾기
입력: 문자열 수와 문자열(모두 소문자)
출력: 그룹단어의 개수
*/
/* ----------<알고리즘>----------
풀이시간: 30분
메모리: 2024KB
시간:0ms
연속한 것과 연속하지 않은 것을 구분해야 한다.
문자마다 방문 체크 배열을 만든다.
입력
    문자열 순회
        방문하지 않은 문자이면
            방문 체크를 한다.
            포인트 증가
        방문한 문자이면
            이전 문자와 같은 지 비교
                같지 않으면(그룹 단어가 아니므로)
                    다음 입력 문자열로 넘어간다.
    (모두 문자열 순회했다는 것은 그룹 단어라는 것이 보장되므로)
    cnt를 증가한다.
cnt를 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;
int chk[30];
int main(){
    int n;
    int cnt = 0;
    bool nogroup = false;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        fill_n(chk, 30, 0);
        nogroup = false;
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            if(chk[str[j]-97] == 0){    // 방문하지 않았으면
                chk[str[j]-97] = 1;
            }
            else{                       // 이미 방문했다면
                if(str[j-1] != str[j]){      // 연속하지 않으면
                    nogroup = true;
                    break;
                }
            }
        }
        if(nogroup == false) cnt++;
    }
    cout << cnt;
}