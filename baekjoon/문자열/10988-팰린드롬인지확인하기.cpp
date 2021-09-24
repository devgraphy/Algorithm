/* ----------<문제 정의>----------
문제: 팰린드롬(대칭)
입력: 문자열(최대 100)
*/
/* ----------<접근법>----------
팰린드롬수 문제와 같다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int len, result = 1;
    cin >> s;
    len = s.length();
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len-i-1]){
            result = 0;
            break;
        }
    }
    cout << result;
}