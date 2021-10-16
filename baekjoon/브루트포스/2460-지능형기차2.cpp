/* ----------<문제 정의>----------
문제: 기차에 최대 인원이 될 때의 수
입력:1번역~10번역 순서대로 내린 사람의 수, 탄 사람의 순
출력: 최대 인원
*/
/* ----------<접근법>----------
누적값의 최댓값을 찾는다. -> O(N)
*/

#include <iostream>
using namespace std;
int main(){
    int a, b;
    int sum = 0;
    int maxval = -1;
    for(int i = 0; i < 10; i++){
        cin >> a >> b;
        sum = sum - a + b;
        if(sum > maxval)
            maxval = sum;
    }
    cout << maxval << '\n';
}