/* ----------<문제 정의>----------
문제: 문제에서 정의한대로 구현
입력: N
출력: N의 사이클 길이
주의 사항: 반드시 돌아올 수 있다고 가정한다.
*/
/* ----------<알고리즘>----------
n 입력
temp = n
while
    if 10 미만
        0 붙임
    두 자리를 더함
    일의 자리와 합한 수의 일의 자리를 더함
    cnt++
    이것이 n과 같으면 종료
*/
#include <iostream>
using namespace std;
int main(){
    int n, temp1, temp2, sum, cnt = 0;
    cin >> n;
    temp1 = n;
    while(1){
        sum = 0;
        temp2 = temp1;
        if(temp1 < 10)
            temp1*=10;
        while(temp1 != 0){
            sum += temp1 % 10;
            temp1/=10;
        }
        temp1 = temp2 % 10;
        temp1 = temp1 * 10 + sum % 10;
        cnt++;
        if(temp1 == n)
            break;
    }
    cout << cnt;
}