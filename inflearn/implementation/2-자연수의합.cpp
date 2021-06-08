#include <iostream>
using namespace std;

int main(){
    int a, b, sum = 0;
    cin >> a >> b;
    cout << a;
    sum = a;
    for(int i = a+1; i <= b; i++){
        cout << "+" << i;
        sum +=i;
    }
    cout << "=" << sum;
}

