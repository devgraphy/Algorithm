// 자릿수 구간을 파악하여 수학적으로 계산: O(input number length)
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int len = 0;
    int pos = to_string(n).length();   // 자릿수 파악
    // 1~9, 10~99, 100~999 ...
    if (pos == 1)
        len = n;
    else{
        for(int i = 1, j = 1; j < pos; i*=10, j++){
            len += i * 9 * j;
        }
        len += (n - pow(10, pos-1)+1) * pos;
    }
    cout << len;
}