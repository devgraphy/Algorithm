/* ----------<���� ����>----------
����: �ùٸ� ��ȣ, ��ȣ�� ���
�Է�: ��ȣ ���ڿ�(�ִ� 30)
���: ��ȣ�� ��갪(�Է��� �ùٸ��� ���� ��ȣ���̸� �ݵ�� 0 ���)
*/
/* ----------<Ʋ�� ���ٹ�>----------
��ȣ �����̹Ƿ� ���� �ڷᱸ���� ���
�ùٸ��� ���� ������ �� ���
--> O(N)
*/
/* ----------<Ʋ�� �˰���>----------
���ڿ� ��ȸ
    (, [ �϶� push
    ), ] �϶� ������ top�� ��
        �Է��� ), ������ top�� (�̸� sum+=2, pop
        �Է��� ], ������ top�� [�̸� sum+=3, pop
        �� ���̸� 0 ����ϰ� ����
sum ���
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string str;
    stack<char> st;
    cin >> str;
    int sum = 0;
    int strlen = str.length();
    for(int i = 0; i < strlen; i++){
        if(str[i] == '(' || str[i] == '[')
            st.push(str[i]);
        else if(str[i] == ')'){
            if(st.top() == '('){
                sum+=2;
                st.pop();
            }
        }
        else if(str[i] == ']'){
            if(st.top() == '['){
                sum+=3;
                st.pop();
            }
        }
        else{
            cout << 0;
            return 0;
        }
    }
    cout << sum;
}