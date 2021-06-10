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
        cout << temp << endl;
        while( temp > 0 ){
            if(temp % 2 == 0){
                cnt2++;
                temp/=2;
            }
            if(temp % 5 == 0){
                cnt5++;
                temp/=5;
            }
        }
    }
    res = min(cnt2, cnt5);
    cout << res;
}