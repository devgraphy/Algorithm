// 브루트포스: O(n)

#include <iostream>
using namespace std;
int a[105];
int main(){
    int n, max = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n-1; i++){
        for(int j = 1; j < n; j++){
            if(max < abs(a[i]-a[j]))
                max = abs(a[i]-a[j]);
        }
    }
    cout << max;
}

