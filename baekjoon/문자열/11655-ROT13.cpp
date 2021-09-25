/* ----------<문제 정의>----------
문제: 알파벳 문자 13개씩 밀기
입력: 공백있는 문자열
*/
/* ----------<개선 접근법>----------
N개 선형 자료구조가 있을 때, 현재 위치+N/2 = 현재위치-N/2 이다.
*/
/* ----------<새롭게 안 것>----------
타입 캐스팅 문법
char('a'+13)❌
(char)('a'+13)⭕
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int len = s.length();
    for(int i = 0; i < len; i++){
        if((s[i] >= 'a' && s[i] <= 'a'+12) || (s[i] >= 'A' && s[i] <= 'A'+12)) {
            cout << (char)(s[i]+13);
        }
        else if(s[i] >= '0' && s[i] <= '9' || s[i] == ' ')
            cout << s[i];
        else
            cout << (char)(s[i]-13);
    }
}