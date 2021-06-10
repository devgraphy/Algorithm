// 팩토리얼의 곱수마다 소인수분해: o(n*n)
// 입력 1000 -> 제한 시간 내 동작
#include <iostream>
#include <vector>
using namespace std;
int a[1001];
int main(){
    int n;
    int chk = 0;
    int temp;
    cin >> n;

    for(int i = 2; i <= n; i++){
        temp = i;
        for(int j = 2; j <= i; j++){
            while(temp > 0){    //소인수분해
                if(temp % j == 0){
                    temp/=j;
                    a[j]++;
                }
                else break;
            }
            if(temp == 0)
                break;
        }
    }
    cout << n << "! = ";
    for(int i = 2; i <= n; i++){
        if(a[i]!=0)
            cout << a[i] << " ";
    }
}