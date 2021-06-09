
#include <iostream>
using namespace std;
int a[105];
int chk[105];
int main(){
    int n;
    cin >> n;
    int x;
    int temp=0;
    for(int i = 0; i < n; i++){
        cin >> a[i];    
    }    
    for(int i = 0; i < n; i++){
        //뒤집기
        x = a[i];
        temp = 0;
        while(x > 0){
            temp*=10;
            temp+=(x % 10);
            x/=10;
        }
        a[i] = temp;
        //소수판별
        if(a[i] == 1)
            chk[i] = 1;
        for(int j = 2; j < a[i]; j++){
            if(a[i] % j == 0){
                chk[i] = 1;
                break;
            }
        }
        //cout << a[i] << " ";
        if(chk[i] == 0)
            cout << a[i] << " ";
    }
    
}