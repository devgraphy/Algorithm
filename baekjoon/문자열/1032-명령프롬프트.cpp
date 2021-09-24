/* ----------<문제 정의>----------
문제: 여러 입력의 공통 패턴 찾기
입력: 문자열 개수, 모두 같은 길이의 문자열
*/
/* ----------<접근법>----------
입력 개수에 따른 문자열을 문자열 배열에 저장
for 각 인덱스 위치별로 비교(모든 문자열을 확인해야 함)
    for 하나라도 틀리면 ? 출력하고 break
    모두 같음이 확인되면 해당 원소 출력
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string s[55];
    char c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    // 여러 문자열들의 같은 인덱스 위치 비교
    int len = s[0].length();
    for(int i = 0; i < len; i++){
        c = s[0][i];
        for(int j = 0; j < n-1; j++){
            if(s[j][i] != s[j+1][i]){
                c = '?';
                break;
            } 
        }
        cout << c;
    }
}