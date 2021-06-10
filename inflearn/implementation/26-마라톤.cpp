// bruteforce: o(n^2)
// 입력 1만 ->  시간 초과 확인
#include <iostream>
using namespace std;
int a[10001];
int b[10001];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = 1;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j=0;j < i;j++){
            if(a[i] <= a[j])
                b[i]++;
        }
    }
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
}