// 음의 정수와 양의 정수를 구분하되, 같은 부호간에 입력순서는 유지되어야 한다.
// 버블정렬(bruteforce) 활용: 최악, 평균, 최선 모두 o(n^2)
// 정렬 알고리즘 중 가장 성능이 안 좋음
// 끝에서부터 정렬됨
// n - 1번 순회

#include <iostream>
using namespace std;
int a[101];
int main(){
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > 0 && a[j+1] < 0){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
}