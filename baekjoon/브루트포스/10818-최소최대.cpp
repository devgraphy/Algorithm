/* ----------<���� ����>----------
����: N���� ���� �߿� �ּڰ�, �ִ� ã��
�Է�: N(�ִ� 100��), N���� ����
�Է�: �ּڰ�, �ִ�
*/
/* ----------<���ٹ�>----------
�迭�� ��ȸ�ϸ鼭 �ּڰ��� �ִ��� ���� -> O(N)
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