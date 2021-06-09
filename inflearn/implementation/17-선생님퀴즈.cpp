// array, math
#include <iostream>
int a[10][2];
using namespace std;
int main(){
    int n;
    int sum;
    cin >> n;
    for(int i = 0; i < n; i++){ // 입력
        cin >> a[i][0] >> a[i][1];
    } 
    for(int i = 0; i < n; i++){
        sum = a[i][0] * ( a[i][0] + 1) / 2;
        if(sum == a[i][1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }
}