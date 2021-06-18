/* 모델링
1. 문제: 정렬되지 않은 두 배열의 교집합 출력
2. 알고리즘(투포인터 알고리즘)
두 포인터 모두 입력 크기동안(&&)
    작으면 포인트 증가, 큰 쪽은 포인터 유지
    같으면 출력하고 동시에 포인터 증가
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[30001];
int b[30001];
int main(){
    int na, nb;
    int pos_a = 0, pos_b = 0;
    cin >> na;
    for(int i = 0; i < na; i++)
        cin >> a[i];
    sort(a, a+na);
    cin >> nb;
    for(int i = 0; i < nb; i++)
        cin >> b[i];
    sort(b, b+nb);
    while(pos_a < na && pos_b < nb){
        if(a[pos_a] > b[pos_b]) pos_b++;
        else if(a[pos_a] < b[pos_b]) pos_a++;
        else {
            cout << a[pos_a] << " ";
            pos_a++;
            pos_b++;
        }
    }
}
