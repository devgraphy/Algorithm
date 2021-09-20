/* ----------<문제 정의>----------
문제: 숫자 문자열 정렬
입력: N(N은 1,000,000,000보다 작거나 같은 자연수)
출력: 자리수를 내림차순으로 정렬한 수를 출력
*/
/* ----------<접근법>----------
문자열의 문자 정렬을 위해 sort를 사용한다.
내림차순을 위해 greater<>() 를 인자로 넘긴다.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<>());
    cout << s;
}