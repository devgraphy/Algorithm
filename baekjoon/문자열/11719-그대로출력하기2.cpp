/* ----------<문제 정의>----------
문제: 공백, 개행까지 그대로 입력받고 출력하기
입력: 문자열(최대 100줄)
주의 사항: 입력 개수를 알 수 없다. 따라서 프로그램의 종료를 정의해야 한다.
*/
/* ----------<접근법(ref)>----------
공백까지 입력받는 getline()을 사용한다.
(ref)무조건 100번은 입력받도록 한다. 단, 입력이 100개 이하면 계속 입력 대기한다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    for(int i = 0; i < 100; i++){
        getline(cin, s);
        cout << s << '\n';
    }
}