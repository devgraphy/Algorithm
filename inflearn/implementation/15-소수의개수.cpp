// time limit exceeded
// n은 최대 20만
// 1부터 최대 20만의 절반인 10만 번까지 연산 => 100억번
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int chk = 1;
    for(int i = 2; i <= n; i++){
        chk = 0;
        for(int j = 2; j*j <= i; j++ ){
            if( i % j == 0){
                chk = 1;
                break;
            }
        }
        if(chk == 1)
            continue;
        else{
            //cout << i << " ";
            cnt++;
        }
    }
    cout << cnt;
}