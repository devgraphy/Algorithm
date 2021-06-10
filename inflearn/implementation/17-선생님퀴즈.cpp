// array, math
#include <iostream>
using namespace std;
int main(){
    int n;
    int sum;
    int a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;  // 수와 정답 입력
        sum = a * (a + 1) / 2;
        if(sum == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }
}