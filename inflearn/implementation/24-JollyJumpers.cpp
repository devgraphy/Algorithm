// 1 ~ N-1까지 중복없이 방문할 경우 YES, 한 번이라도 중복 방문하거나 범위 벗어난 방문하면 NO: o(n)
#include <iostream>
using namespace std;
int num[101];
int main(){
    int n, a, b, temp;
    int chk = 0;
    cin >> n;
    cin >> a;
    for(int i = 0; i < n-1; i++){
        cin >> b;
        temp = abs(b-a);
        if(temp >= 1 && temp < n){
            if(num[temp] == 0)
                num[temp] = 1;
            else{
                chk = 1;
                break;
            }
        }
        else{
            chk = 1;
            break;
        }
        a=b;
    }
    if(chk == 0)
        cout << "YES";
    else
        cout << "NO";
}