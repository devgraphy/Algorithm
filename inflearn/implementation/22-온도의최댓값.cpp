// 입력과 동시에 sliding window 계산: o(n+n)
// 입력 n:10만, k:n
#include <iostream>
using namespace std;
int a[100001];
int main(){
    int n, k;
    int max = -2147000000;
    int window = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){     // 0부터 할 경우, max와 비교 시점에 문제 발생
        if(i < k)
            window+=a[i];
        else{   // k와 같거나 커지면... 같을 때부터 max와 비교해야함
            window+=(a[i]-a[i-k]);
            if(max < window)
                max = window;
        }
    }
    cout << max;  
}