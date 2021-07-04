/* ----------<문제 정의>----------
문제: 1부터 N까지 문자로 이어붙일 때 자릿수 계산
입력: 1<=N<=1억
출력: 계산한 자릿수
시간제한: 0.15초
*/
/* ----------<알고리즘>----------
문제 유형: math, implementation
runtime: 0ms
구현 소요 시간: 30분

일일이 붙이기 -> 시간초과
1의 자리수, 10의 자리수 ... math로 한번에 계산

N이 몇자리수인지 파악 -> 문자열 length로 파악
싸잡아서 계산하는 부분과 직접 계산하는 부분을 어떻게 구분하지?
-자기 자신의 자릿수에서는 직접 계산
-나머지 자릿수에서는 싸잡아서 계산
-한자리수든 여러 자리수든 전체 길이와 같을 땐 주어진 값에서 그 길이의 최솟값을 빼준다.

즉, 자릿수가 M일때
M-1까지는 그 자릿수에서 최댓값에서 최댓값을 뺌으로써 개수를 구한다.
M자릿수에서는 N - 10*(M-1) +1로 계산

ex) 120이면
1자리수 1~9 9개  9*10^0-10^0+1
2자리수  10~99  90개  9*10^1-10^1+1
3자리수 100~120 21개

ex) 8
1자리수 1~8 8개 1~8 8개 -> 8-10^0+1
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    string n;
    cin >> n;
    int len = n.length();
    int val = stoi(n);
    int total_len = 0;
    int endnum = 9;
    for(int i = 1; i <= len; i++){
        if( i == len ){
            total_len += (val - pow(10, len-1)+1)*len;        }
        else{
            total_len += (endnum - pow(10, i-1) + 1)*i;
        }
        endnum = endnum * 10 + 9;
    }
    cout << total_len;
}
