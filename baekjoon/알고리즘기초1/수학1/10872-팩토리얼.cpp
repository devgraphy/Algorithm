/* ----------<문제 정의>----------
문제: N! 구하기
입력: N(최대 12)
출력: N! 결과 출력
고려 사항: overflow - 1*2*...*12(4억)가 int범위 내에 들어오지만 그 이상은 overflow가 발생한다.
*/
/* ----------<알고리즘>----------
for문으로 일일이 곱한다.
<복잡도>
시간-O(N)
*/

#include <iostream>
using namespace std;
int main(){
    int n;
    int fact = 1;
    cin >> n;
    if(n == 0) {
        cout << 1;
        return 0;
    }
    else{
        for(int i = 2; i <= n; i++){
            fact*=i;
        }
    }
    cout << fact;
}