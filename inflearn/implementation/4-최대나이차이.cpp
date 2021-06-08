// 최댓값 - 최댓값 : O(n)

#include <iostream>
using namespace std;
int a[105];
int main(){
    int n, max = -2147000000, min = 2147000000;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        if(max < a[i]) max = a[i];
        if(min > a[i]) min = a[i];
    }
    cout << max - min;
}

