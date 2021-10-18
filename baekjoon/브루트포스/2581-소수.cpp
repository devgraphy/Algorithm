/* ----------<���� ����>----------
����: �Ҽ� ã��, �� �� �ּڰ� ã��
�Է�: M,N (�ִ� 1��, M�� N���� �۰ų� ����)
���� ����: M�̻� N���� �ڿ��� �� �Ҽ��� ���� ��� -1 ���
*/
/* ----------<���ٹ�>----------
M�� N ������ ���� ��ȸ
    �Ҽ� �Ǵ�
    �ּڰ� ����
--> (N-M)*sqr(N-M)
*/
#include <iostream>
using namespace std;
int main(){
    int m, n, sum = 0;
    int minval = 2147000000;
    bool prime;
    cin >> m >> n;
    // m���� n���� ��ȸ
    for(int i = m; i <= n; i++){
        //�Ҽ� �Ǵ�
        prime = true;
        if(i == 1)
            prime = false;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                prime = false;
                break;
            }
        }
        if(prime == true){
            sum += i;
            if(minval > i)
                minval = i;
        }       
    }
    if(!sum)
        cout << -1;
    else
        cout << sum << '\n' << minval;
}