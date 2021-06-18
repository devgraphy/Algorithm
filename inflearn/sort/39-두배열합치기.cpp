/* 모델링
1. 문제: 두 정렬된 배열을 하나의 정렬된 수열로 출력
2. 알고리즘(병합정렬)
method1.
두 포인터 모두가 입력 크기 동안(&&) 
    각 배열의 포인터 값을 비교해서 출력
아직 초과하지 않은 배열 나머지 출력

method2. (단, 두 배열 모두 INT_MAX로 초기화해주어야 함)
두 포인터 모두가 입력 크기를 초과할 때까지 (||)
        각 배열의 포인터 값을 비교해서 출력
*/
#include <iostream>
#include <climits>
using namespace std;
int a[101];
int b[101];
int main(){
    int na, nb;
    int pos_a = 0, pos_b = 0;
    cin >> na;
    fill_n(a,101,INT_MAX);
    for(int i = 0; i < na; i++){
        cin >> a[i];
    }
    cin >> nb;
    fill_n(b,101,INT_MAX);
    for(int i = 0; i < nb; i++){
        cin >> b[i];
    }
    while(pos_a < na || pos_b < nb){
        if(a[pos_a] >= b[pos_b])
            cout << b[pos_b++] << " ";
        else
            cout << a[pos_a++] << " ";
    }    
}