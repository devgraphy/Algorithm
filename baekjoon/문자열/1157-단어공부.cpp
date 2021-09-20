/* ----------<문제 정의>----------
문제: 가장 많이 사용된 알파벳
입력: 문자열(길이 100만)
출력: 가장 많이 사용된 알파벳 대문자, 값이 여러 개 존재하면 ? 출력
*/
/* ----------<접근법>----------
1. 알파벳별 개수 파악(대소문자 하나로 통일), 동시에 최댓값 파악
2. 끝까지 순회하면서 최댓값과 일치하는 인덱스 정보 찾기.
    3. 최댓값과 일치하는 인덱스 정보 기록 & 이때 이미 최댓값과 일치하는 알파벳이 있음을 의미하는 dup = true
    4. 다음에 또 최댓값과 일치하는 알파벳이 있고 이때 dup이 true 면 '?'출력 후 종료

*/

#include <iostream>
#include <string>
using namespace std;
int c[26];
int main(){
    string s;
    int max_cnt = -1;
    int max_char;
    bool dup = false;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            c[s[i] - 'a']++;
            if(c[s[i] - 'a'] > max_cnt) max_cnt = c[s[i] - 'a'];
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            c[s[i] - 'A']++;
            if(c[s[i] - 'A'] > max_cnt) max_cnt = c[s[i] - 'A'];
        }
        
    }
    // 알파벳 파악
    for(int i = 0; i < 26; i++){
        if(c[i] == max_cnt && !dup){
            max_char = i;
            dup = true;
        }
        else if(c[i] == max_cnt && dup){
            cout << '?';
            return 0;
        }
    }
    cout << (char)(max_char+'A');
}