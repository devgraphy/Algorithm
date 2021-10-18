/* ----------<문제 정의>----------
문제: 소수 찾기, 그 중 최솟값 찾기
입력: M,N (최대 1만, M은 N보다 작거나 같다)
주의 사항: M이상 N이하 자연수 중 소수가 없을 경우 -1 출력
*/
/* ----------<접근법>----------
M과 N 사이의 수를 순회
    소수 판단
    최솟값 갱신
--> (N-M)*sqr(N-M)
*/
#include <iostream>
using namespace std;
int main(){
    int m, n, sum = 0;
    int minval = 2147000000;
    bool prime;
    cin >> m >> n;
    // m부터 n까지 순회
    for(int i = m; i <= n; i++){
        //소수 판단
        prime = true;
        if(i == 1)
            prime = false;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                prime = false;
                break;
            }
        }
        if(prime == true){
            sum += i;
            if(minval > i)
                minval = i;
        }       
    }
    if(!sum)
        cout << -1;
    else
        cout << sum << '\n' << minval;
}