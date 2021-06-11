// 입력 1000 - factorial을 먼저 구하면 최대 20!에서 overflow 발생
// 곱수마다 0을 구하려면 소인수분해하여 5와2의 개수를 파악하면 됨
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, res, temp;
    int cnt2 = 0;
    int cnt5 = 0;
    cin >> n;
    for(int i = 2; i <= n; i++){
        temp = i;
        while( temp > 0 ){
            if(temp % 2 == 0){
                cnt2++;
                temp/=2;
            }
            else if(temp % 5 == 0){ // 모든 2의 배수는 temp가 0으로 끝나는데, 마지막에 0도 5에서 추가해주게 되므로 else 처리
                cnt5++;
                temp/=5;
            }
            else                    // 2와 5에서 나누어 떨어지지 않는 경우 무한 루프 발생, 이 경우 루프 탈출
                break;
        }
    }
    res = min(cnt2, cnt5);
    cout << res;
}