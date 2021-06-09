// array 역순으로 최댓값 갱신 - O(n)
// 1차원 배열의 필요성
#include <iostream>
using namespace std;
int a[101];
int main(){
    int n;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max = a[n-1];
    for(int i = n-2; i >= 1; i--){
        if(a[i] > max){
            max = a[i];
            cnt++;
        }
    }
    cout << cnt;
}