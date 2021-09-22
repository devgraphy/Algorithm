/* ----------<문제 정의>----------
문제: 문자열 10개 단위로 끊기
입력: 문자열(최대 100)
*/
/* ----------<접근법>----------
인덱스가 10의 배수이면 개행을 하고 문자열 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        // mod 10이 0(즉, 10번째 문자)일 때마다 개행. 단, 첫 번째는 무시
        if(i != 0 && (i % 10)==0)
            cout << '\n';
        cout << s[i];
    }
}