// 입력 순 석차 출력
// ref to answer
// bruteforce: o(n^2)
// 입력 100 - 시간 초과 X
#include <iostream>
using namespace std;
int a[101];
int b[101];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] < a[j]) b[i]++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }

}