/* ----------<문제 정의>----------
문제: N개의 정수 중에 최솟값, 최댓값 찾기
입력: N(최대 100만), N개의 정수
입력: 최솟값, 최댓값
*/
/* ----------<접근법>----------
배열을 순회하면서 최솟값과 최댓값을 갱신 -> O(N)
*/
#include <iostream>
using namespace std;
int main(){
    int n, temp;
    cin >> n;
    int maxval = -2147000000;
    int minval = 2147000000;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp < minval)
            minval = temp;
        if(temp > maxval)
            maxval = temp;
    }
    cout << minval << " " << maxval;
}