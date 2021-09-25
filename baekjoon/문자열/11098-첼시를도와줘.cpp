/* ----------<문제 정의>----------
문제: 최댓값 찾기
입력: 테스트 케이스 t, 선수 수 n, 선수 가격(최대 20억, 가격은 모두 다르다), 선수명
*/
/* ----------<접근법>----------
입력받을 때마다 최댓값을 계속 갱신한다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int t;
    int n;
    int a;
    string b;
    int max_val = -1;
    string max_name;
    cin >> t;
    while(t--){
        cin >> n;
        max_val = -1;
        while(n--){
            cin >> a >> b;
            if(max_val < a){
                max_val = a;
                max_name = b;
            }
        }
        cout << max_name << '\n';
    }
}