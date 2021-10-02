/* ----------<문제 정의>----------
문제: 동일한 숫자의 카드 개수
입력: 입력 개수 n(최대 50만), n개의 수(최소 -천만, 최대 천만), 개수 확인할 수의 개수 m(최대 50만), m개의 수
출력: m개의 수에 대한 각각의 개수
*/
/* ----------<접근법>----------
마이너스 범위와 플러스 범위를 고려하여 2천개의 배열 자료구조를 이용할 수 있지만(O(1)에 접근)
공간 복잡도를 줄이기 위해 해시맵을 사용한다.
O(N+M+M)
*/
#include <iostream>
#include <map>
using namespace std;
int main(){
    int n, m, temp;
    map<int, int> card_m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        card_m[temp]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> temp;
        cout << card_m[temp] << ' ';
    }
}