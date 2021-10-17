/* ----------<문제 정의>----------
문제: n번째 피보나치 수 구하기
*/
/* ----------<접근법>----------
재귀 사용법 익힐 겸 재귀를 이용한다.
*/
/* ----------<알고리즘>----------
        3
    2       1
0       1   

    int fib(n)
    if(n==0 ||n == 1){
        return n;
    }
    return fib(n-2) + fib(n-1);

    main
    배열에 인덱스 0과 1의 원소에 각각 0, 1을 할당
*/
#include <iostream>
using namespace std;
int mem[100];
int fib(int n){
    if(n == 0 || n == 1) return n;
    else if(mem[n] != 0){
        return mem[n];
    }
    else
        return mem[n] = fib(n-2) + fib(n-1);
}
int main(){
    int n;
    cin >> n;
    cout << fib(n);
}
