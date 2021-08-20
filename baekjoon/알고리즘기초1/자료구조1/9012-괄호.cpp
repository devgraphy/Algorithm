/* ----------<문제 정의>----------
문제: 올바른 괄호
입력: 테스트케이스 수, 괄호 문자열
출력: YES/NO
*/
/* ----------<주의할 점>----------
테스트 케이스 반복하는 코드를 작성할 때, 초기화에 신경쓴다.
*/
/* ----------<알고리즘>----------
풀이시간:23분
메모리:2024KB
시간:4ms

괄호 종류가 하나이므로 변수 하나로 구현할 수 있다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int t;
    int st = 0;
    string ps;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> ps;
        st = 0;
        // 문자열 순회
        for(int j = 0; j < ps.length(); j++){
            if(ps[j] == '(') st++;
            else{
                if(st>0) st--;
                else{
                    st--;
                    break;
                }
            }
        }
        if(st > 0 || st < 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}