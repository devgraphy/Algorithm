/* ----------<문제 정의>----------
문제: 소수 찾기
- 소수: 1과 자기 자신으로만 나눠지는 수
입력: 입력 개수(최대 100), 수(최대 1천)
출력: 소수 개수
시간 제한:2초
*/
/* ----------<알고리즘>----------
⭐O(N*M) 해도 문제 없긴 하나 제곱근(포함)까지만 확인하면 된다.

개수 입력
수 반복 입력
수 개수 만큼 반복하면서 소수 판단
    1과 자기 자신을 제외한 나머지 수로 나눠지지 않으면 그 수는 소수
*/

#include <iostream>
using namespace std;
int a[101];
int main(){
    int n, cnt = 0;
    bool isprime = true;
    cin >> n;   // 개수 입력
    // 수 입력
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // 각 수마다 소수 판별
    for(int i = 0; i < n; i++){
        isprime = true; // 반복 작업에 따른 초기화
        if(a[i] == 1) isprime = false;
        for(int j = 2; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                isprime = false;
                break;
            }
        }
        if(isprime) cnt++;
    }
    cout << cnt;
}