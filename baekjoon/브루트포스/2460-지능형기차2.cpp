/* ----------<���� ����>----------
����: ������ �ִ� �ο��� �� ���� ��
�Է�:1����~10���� ������� ���� ����� ��, ź ����� ��
���: �ִ� �ο�
*/
/* ----------<���ٹ�>----------
�������� �ִ��� ã�´�. -> O(N)
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