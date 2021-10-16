/* ----------<문제 정의>----------
문제: 10진수 n을 2진수로 바꿨을 때 1의 위치 파악
입력: 테스트 케이스 n, n개의 숫자
출력: 1의 인덱스
*/
/* ----------<접근법>----------
10진수를 2진수로 변환하는 방법을 그대로 이용한다.
2로 나누어가면서 나머지가 1인 경우의 인덱스를 출력한다.
*/
#include <iostream>
using namespace std;
int main(){
    int t;
    int temp;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> temp;
        int idx = 0;
        int k = 0;
        while(temp!= 0){
            k = temp % 2;
            if(k == 1){
                cout << idx <<" ";
            }
            idx++;
            temp/=2;
        }
    }
}