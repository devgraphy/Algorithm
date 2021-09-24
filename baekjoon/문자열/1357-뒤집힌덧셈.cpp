/* ----------<문제 정의>----------
문제: 뒤집은 숫자와의 덧셈
*/
/* ----------<접근법>----------
숫자 뒤집기 문제를 활용한다.
문자열로 받을지 숫자로 받을지 고민해야 한다.
문자열로 받으면 stoi로 int형으로 변환 후 뒤집는 연산 코드 작성
int형으로 받으면 바로 연산 코드를 작성
따라서 int형으로 정의한다.
*/
#include <iostream>
using namespace std;
int rev(int a){
    int res = 0;
    while(a != 0){
        res = res * 10 + a % 10;
        a /= 10;
    }
    return res;
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << rev(rev(a)+rev(b));
}