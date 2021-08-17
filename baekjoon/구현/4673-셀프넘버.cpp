/* -----<문제 정의>-----
문제: 정의된 셀프 넘버 찾기
셀프 넘버: n + n의 각 자리수 합으로 x가 만들어질 수 있을 때, 이렇게 만들 수 있는 n이 존재하지 않는 수
입력: x
출력: 10,000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 증가하는 순서로 출력한다.
*/
/* -----<알고리즘>-----
풀이시간: 35분
메모리: 2060KB
시간: 44ms

1부터 10000까지 각각 10000까지 d(n)무한수열 만들면서 체크
단, 효율성을 위해 다음 생성자에선 이미 방문한 수에 대해선 방문하지 않는다.
어차피 그 이후는 반복될 것이기 때문이다.
*/

#include <iostream>
using namespace std;
int chk[10001];
void drk(int i){
    if(i > 10000)
        return;
    if(chk[i] == 1) // 30ms 단축
        return;
    int d = i;
    while(i){
        d += (i % 10);
        i/=10;
    }
    // chk[d] = 1; // drk 들어가자마자 basecase 조건에 걸림
    drk(d);
    chk[d] = 1; 
}
int main(){
    for(int i = 1; i <= 10000; i++){
        drk(i);
    }
    for(int i = 1; i <= 10000; i++){
        if(chk[i] == 0)
            cout << i << endl;
    }
}