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
������ ���� ��� �ٸ� ��츦 �����ؾ� �Ѵ�.
    �� ���� ���� ��� �ٸ� ��츦 �����ؾ� �Ѵ�.
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
        // ���̰� ���� ��� ����
        //cout << tempname << tempdd << tempmm << tempyy << endl;
        if(tempyy == minbirth[2]){
            if(tempmm == minbirth[1]){   // ������ ���� ���
                if(tempdd < minbirth[0]){
                    minbirth[0] = tempdd;
                    minbirth[1] = tempmm;
                    minbirth[2] = tempyy;
                    minname = tempname;
                }
            }
            else if(tempmm < minbirth[1]){
                minbirth[0] = tempdd;
                minbirth[1] = tempmm;
                minbirth[2] = tempyy;
                minname = tempname;
            }
            
        }
        else if(tempyy < minbirth[2]){
            minbirth[0] = tempdd;
            minbirth[1] = tempmm;
            minbirth[2] = tempyy;
            minname = tempname;
        }
        // ���̰� ���� ��� ����
        if(tempyy == maxbirth[2]){
            if(tempmm == maxbirth[1]){   // ������ ���� ���
                if(tempdd > maxbirth[0]){
                    maxbirth[0] = tempdd;
                    maxbirth[1] = tempmm;
                    maxbirth[2] = tempyy;
                    maxname = tempname;
                }
            }
            else if(tempmm > maxbirth[1]){
                maxbirth[0] = tempdd;
                maxbirth[1] = tempmm;
                maxbirth[2] = tempyy;
                maxname = tempname;
            }
            
        }
        else if(tempyy > minbirth[2]){
            maxbirth[0] = tempdd;
            maxbirth[1] = tempmm;
            maxbirth[2] = tempyy;
            maxname = tempname;
        }
            
    }
    cout << maxname << '\n' << minname;
}