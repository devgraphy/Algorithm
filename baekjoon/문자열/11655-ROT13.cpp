/* ----------<문제 정의>----------
문제: 알파벳 문자 13개씩 밀기
입력: 공백있는 문자열
*/
/* ----------<접근법>----------
13을 더하면서 26번째 알파벳을 넘어가는 경우 다시 처음으로 돌아가는 처리를 해주어야 한다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(s[i] >= 'a' && s[i] <= 'z') {
            cout << char(((s[i]-'a')+13)%26+'a');
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            cout << char(((s[i]-'A')+13)%26+'A');
        }
        else cout << s[i];
    }
}