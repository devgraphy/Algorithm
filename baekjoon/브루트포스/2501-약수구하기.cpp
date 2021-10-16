/* ----------<문제 정의>----------
문제: 약수 구하기
입력: N(최대 1만), K
/* ----------<접근법>----------
약수 일때마다 카운트하여 K와 같아질 때 출력하고 종료
단, k번째의 약수가 존재하지 않은 경우가 있으므로 이를 처리해주어야 한다.
*/
#include <iostream>
using namespace std;
int main(){
    int n, k, cnt = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cnt++;
        }
        if(cnt == k){
            cout << i;
            return 0;
        }
    }    
    cout << 0;
}