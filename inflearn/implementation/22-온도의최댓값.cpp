// 특정일에 대해 for loop 계산->nested loop: o((n-k+1)*k)
// 입력 n:10만, k:n
// 10만, 구간 1일 - 10만
// 10만, 구간 10일 - (10만-10)*10: 100만
// 10만, 구간 1000일 - (10만-1000)*1000: 1억 => time limit exceeded!
#include <iostream>
using namespace std;
int a[100001];
int main(){
    int n, k;
    int max = -2147000000;
    int temp = 0;
    cin >> n >> k;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0; i <= n-k; i++){
        temp = 0;
        for(int j = 0; j < k; j++){
            temp+=a[i+j];
        }
        if(max < temp)
            max = temp;
    }
    cout << max;
    
}