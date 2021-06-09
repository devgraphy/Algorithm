// 브루트포스 O(n^2) - 최대 입력 100 - 1만번 연산 ok
#include <iostream>
using namespace std;
int a[101];
int main(){
    int n;
    int chk = 0;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        chk = 0;
        for(int j = i + 1; j < n;j++){
            if(a[i] <= a[j]){
                chk = 1;
                break;
            }
        }
        if(chk == 0)
            cnt++;
    }
    cout << cnt;
}