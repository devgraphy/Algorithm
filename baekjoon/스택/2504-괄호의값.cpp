/* ----------<���� ����>----------
����: �ùٸ� ��ȣ, ��ȣ�� ���
�Է�: ��ȣ ���ڿ�(�ִ� 30)
���: ��ȣ�� ��갪(�Է��� �ùٸ��� ���� ��ȣ���̸� �ݵ�� 0 ���)
*/
/* ----------<���ٹ�>----------
��ȣ �����̹Ƿ� ���� �ڷᱸ���� ���
�Ǹ���: ���ϱ�� ���ϱ⸦ �����ϱ�
*/
/* ----------<�˰���>----------

*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string str;
    stack<char> st;
    cin >> str;
    int result = 0;
    int strlen = str.length();
    for(int i = 0; i < strlen; i++){
        if(str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == '['){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            // ( ���� ������ ��� �� ����
            int temp = 0;
            while(st.top() != '('){
                if(st.top() == '['){  // �߸� ��Ī�� ���
                    cout << 0;
                    return 0;
                }                
                temp+=st.top();
                st.pop();
            }
            st.pop();
            if(temp == 0) temp = 1;
            st.push(temp*2);  // ���� ���� �״�� char�� ���ÿ� push, ���� Ÿ�� ĳ���ø� �ؼ� ���<-�� �ڸ� �̻��̱� ����
        }
        else if(str[i] == ']'){
            // ( ���� ������ ��� �� ����
            int temp = 0;
            while(st.top() != '['){
                if(st.top() == '('){  // �߸� ��Ī�� ���
                    cout << 0;
                    return 0;
                }                
                temp+=st.top();
                st.pop();
            }
            st.pop();
            if(temp == 0) temp = 1; // �ƹ� �͵� ������ �� ���ٸ�
            st.push(temp*3);  // ���� ���� �״�� char�� ���ÿ� push, ���� Ÿ�� ĳ���ø� �ؼ� ���<-�� �ڸ� �̻��̱� ����
        }
    }
    // ���ÿ� ���� ���ڵ� ��� ���ϱ�(���� ������ ��ȣ������ ���� ���)
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << result;
}