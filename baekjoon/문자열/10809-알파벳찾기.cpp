/* ----------<문제 정의>----------
문제: 알파벳 위치 찾기
*/
/* ----------<접근법>----------
접근법1. 알파벳(a-z)별로 존재를 파악하여 출력-o(26*n)
✅접근법2. 문자별로 해당되는 알파벳 키값에 위치 기록 -o(n)
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int c[26];
    cin >> s;
    fill_n(c, 26, -1);  // 인덱스 정보와 겹치지 않는 -1로 초기화
    for(int i = 0; i < s.length(); i++){
        if(c[s[i]-'a'] == -1)   // 처음 등장 위치에
            c[s[i]-'a'] = i;
    }
    for(int i = 0; i < 26; i++){
        cout << c[i] << " ";
    }

}