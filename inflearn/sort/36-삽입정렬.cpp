// 삽입정렬(오름차순)-차례대로 너 나와  
// 선택 정렬(오름차순)-내 뒤에서 가장 작은 사람 누구야? 나랑 바꿔
// 최악의 경우 o(n^2)으로 같지만 삽입 정렬이 약간 더 빠름

#include <iostream>
using namespace std;
int a[101];
int main(){
    int n, tmp, i , j;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    for(i = 1; i < n; i++){
        tmp = a[i];
        for(j = i-1; j >= 0; j--){
            if(a[j] > tmp){
                a[j+1] = a[j];  // 뒤로 당기기
            }
            else
                break;
        }
        a[j+1] = tmp;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}