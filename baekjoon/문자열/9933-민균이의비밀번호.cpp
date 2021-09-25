/* ----------<문제 정의>----------
문제: 뒤집은 문자열이 같은 문자열 찾기, 중복 조합
입력: 비밀번호 수(최대 100) n, n개의 비밀번호 문자열(최대 13)
출력: 비밀번호 길이, 비밀번호의 가운데 문자
*/
/* ----------<접근법>----------
예시2처럼 뒤집은 문자열이 자기자신이 될 수 있으므로 자기자신을 포함하여 중복 조합을 구현한다.
*/
#include <iostream>
#include <string>
using namespace std;
int n;
string s[101];
string comb[2];
void dfs(int idx, int cnt){
    if(cnt == 2){
        string rev="";
        int len = comb[1].length();
        // 뒤집기
        for(int i = 0; i < len; i++){
            rev+=comb[1][len-i-1];
        }
        if(comb[0] == rev){
            cout << len << " " << comb[0][len/2];
        }
        return;
    }
    for(int i = idx; i < n; i++){
        comb[cnt] = s[i];
        dfs(i, cnt+1);
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    dfs(0, 0);
}