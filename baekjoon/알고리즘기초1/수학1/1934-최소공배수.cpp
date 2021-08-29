/* ----------<문제 정의>----------
문제: 최소공배수
입력: 테스트 케이스 개수, 각 케이스마다 최소 공배수를 구할 두 개의 수
출력: 각 케이스마다의 최소 공배수
*/
/* ----------<알고리즘>----------
배수의 대소를 비교하면서 배수를 구해 나간다.

메모리:2020KB
시간:100ms
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    int a, b, tempa, tempb;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        tempa = a, tempb = b;
        while(tempa != tempb){
            if(tempa > tempb) tempb+=b;
            else tempa+=a; 
        }
        cout << tempa << '\n';
    }
}