/* ----------<���� ����>----------
����: ��� ���� ������ �ѷ�
�Է�: H, W, W���� ������ ��� ����
���: ���� �ѷ�
*/
/* ----------<���� ���ٹ�>----------
�� ������ ������ �� ��ġ�� �������� ���� �� ���� ū ���� ���� �� �� ���� ū ���� ���Ѵ�.
�� �� �� ���� ���� �����Ͽ� �� ������ �ڱ� ���̸� ���� ������ ���� �ȴ�. 
*/
/* ----------<�˰���>----------
���� ���� �Է�
�� ������ �����ϰ� �� ������ ���� ū ���� ã�´�.
�� ���� ���Ͽ� ���� ���� �����Ѵ�.
�ش� ��ġ�� ���̰��� ���� ���� �ѷ� ������ ���Ѵ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int h, w, maxleft = -1, maxright = -1;
    int result = 0;
    int arr[501];
    cin >> h >> w;
    for(int i = 0; i < w; i++)
        cin >> arr[i];
    for(int i = 1; i < w-1; i++){
        maxleft = -1;
        maxright = -1;
        for(int j = i-1; j >= 0; j--){
            if(maxleft < arr[j])
                maxleft = arr[j];
        }
        for(int j = i+1; j < w; j++){
            if(maxright < arr[j])
                maxright = arr[j];
        }
        if(min(maxleft, maxright)-arr[i] < 0) continue; // �ڱ⺸�� ���� ���� ���� ��� �� ���� -1 �Ǵ� ���ܸ� ó���ؾ� �Ѵ�.
        result = result + min(maxleft, maxright)-arr[i];
    }
    cout << result;
}
