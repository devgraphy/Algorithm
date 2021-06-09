// 같은 수, 1 큰수, 2 큰수 규칙성
#include <iostream>
using namespace std;
int main(){
    int n, a[101], b[101];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] == b[i])
            cout << 'D' << endl;
        else if(a[i] == b[i]+1)
            cout << 'A' << endl;
        else if(a[i]+1 == b[i])
            cout << 'B' << endl;
        else if(a[i] > b[i])
            cout << 'B' << endl;
        else
            cout << 'A' << endl;
    }
}