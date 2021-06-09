// 경계값 넘는 최대 구간 길이 구하기
// wrong answer
#include <iostream>
using namespace std;
int main(){
    int n, m, temp;
    int cnt = 0, max = -2147000000;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp > m){
            //cout << temp << " ";
            cnt++;
            //cout << cnt << " ";
        }
        if(max < cnt){
            max = cnt;
            //cout << max << " ";
        }
        if(temp <= m)
            cnt = 0;
    }
    if(max > 0)
        cout << max;
    else
        cout << -1;
}