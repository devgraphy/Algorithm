/* ----------<���� ����>----------
����: n��° �Ǻ���ġ �� ���ϱ�
*/
/* ----------<���ٹ�>----------
��� ���� ���� �� ��͸� �̿��Ѵ�.
*/
/* ----------<�˰���>----------
        3
    2       1
0       1   

    int fib(n)
    if(n==0 ||n == 1){
        return n;
    }
    return fib(n-2) + fib(n-1);

    main
    �迭�� �ε��� 0�� 1�� ���ҿ� ���� 0, 1�� �Ҵ�
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
