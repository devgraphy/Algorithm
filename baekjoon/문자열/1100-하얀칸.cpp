/* ----------<문제 정의>----------
문제: 2차원 배열 순회, 패턴 규칙성 찾기
*/
#include <iostream>
using namespace std;
int main(){
    int cnt = 0;
    char temp;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> temp;
            if((i+j)%2==0 && temp == 'F') cnt++;
        }
    }
    cout << cnt;
}