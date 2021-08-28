/* ----------<문제 정의>----------
문제: 최소공배수
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