/* ----------<문제 정의>----------
문제: 콤마와 개행으로 입력 구분하여 받기
주의 사항: getline은 문자열로 라인을 가져온다.
*/
/* ----------<접근법>----------
테스트 케이스 마다 getline을 통해 콤마 기준 입력과 개행 기준 입력 두번을 받는다.
getline은 스트림에서 문자열로 라인을 가져온다.
그래서 stoi()함수를 통해 입력받은 문자열을 숫자로 바꿔주는 과정이 필요하다.
문제에서는 피연산자가 한 자릿 수로 제한되어 있지만 그렇지 않은 경우에도 처리할 수 있도록 처리한다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int t;
    cin >> t;
    string a, b;
    for(int i=0; i<t; i++){
        getline(cin,a,',');
        getline(cin,b,'\n');
        cout << stoi(a) + stoi(b) << '\n';
    }
}