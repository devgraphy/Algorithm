/* ----------<���� ����>----------
����: �ִ�, �ּڰ� ã��
�Է�: n(�ִ� 100��), n���� ���ڿ�
���: �ּڰ��� �̸�, �ִ��� �̸�
*/
/* ----------<���ٹ�>----------
�� ���ο� �̸� �� �� ������ ������ �������� ���´�.
�� ���ڿ����� �̸� �� �� ������ ��ġ�� �ٸ���.
������ �迭 �Ǵ� �迭�� �迭�� �����Ѵ�.
�������� ���ؾ��ϹǷ� ��Ʈ �������� ���� ����� �˰� �־�� �Ѵ�.
for n
    for 4
        �ּڰ� ��(��, ��, ���� ��� �۴ٸ�)
        �ִ� ��(��, ��, ���� ��� ũ�ٸ�)
*/
/* ----------<�𸣴� ��>----------
�迭�� ���� ���� ���
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    int arr[100][4];
    string maxname;
    string minname;
    int maxidx=0;
    int minidx=0;
    int maxbirth[3]={-1,-1,1900};
    int minbirth[3]={40,13,2020};
    cin >> n;
    int tempdd;
    int tempmm;
    int tempyy;
    string tempname;
    for(int i = 0; i < n; i++){
        // �� ������ ���� �Է� �ޱ�
        cin >> tempname >> tempdd >> tempmm >> tempyy;
        // �ּڰ� ����
        //cout << tempname << tempdd << tempmm << tempyy << endl;
        if(tempyy <= minbirth[2] && tempmm <= minbirth[1] && tempdd <= minbirth[0]){
            minbirth[0] = tempdd;
            minbirth[1] = tempmm;
            minbirth[2] = tempyy;
            minname = tempname;
            cout << minname << endl;
        }
        if(tempyy >= maxbirth[2] && tempmm >= maxbirth[1] && tempdd >= maxbirth[0]){
            minbirth[0] = tempdd;
            minbirth[1] = tempmm;
            minbirth[2] = tempyy;
            maxname = tempname;
        }      
    }
    cout << maxname << '\n' << minname;
}