/* ----------<문제 정의>----------
문제: 문자열 내 단어의 개수
입력: 문자열
출력: 단어의 수
주의 사항: 공백으로 시작하거나 끝날 수 있다.
*/
/* ----------<접근법>----------
단어와 공백의 관계를 이용한다.
공백 앞에 단어가 있는지 확인한다.(단, out of index에 주의)
마지막에 공백을 추가해줌으로써 공백이 애초에 있든 없든 단어를 파악하게 된다.
(중복 공백은 아무리 많아도 무시하게된다.)
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int cnt = 0;
    getline(cin, s);
    s += ' ';
    for(int i = 0; i < s.length(); i++){
        if(i != 0 && s[i] == ' ' && s[i-1] != ' '){
            cnt++;
        }
    }
    cout << cnt;
}