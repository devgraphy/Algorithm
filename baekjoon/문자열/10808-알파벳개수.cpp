/* ----------<문제 정의>----------
문제: 알파벳별 개수 파악
입력: 소문자로만 이루어진 단어
*/
/* ----------<접근법>----------
알파벳을 배열의 고정 인덱스와 일치시켜서 해당 알파벳별 배열 원소 파악을 o(1)에 수행한다.
o(단어 길이)
*/
#include <iostream>
#include <string>
using namespace std;
int a[26];
int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        a[s[i]-'a']++;
    }
    for(int i = 0; i < 26; i++)
        cout << a[i] << " ";
}