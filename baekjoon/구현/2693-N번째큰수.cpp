/* ----------<접근법>----------
정렬 후 뒤에서 3번 째 큰 수 출력
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t;
    int a[10];
    cin >> t;
    for(int i = 0; i < t; i++){
        for(int j = 0; j < 10 ; j++){
            cin >> a[j];
        }
        sort(a, a+10);
        cout << a[7] << '\n';
    }
}