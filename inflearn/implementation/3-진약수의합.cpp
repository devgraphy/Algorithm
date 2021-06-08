#include <iostream>
using namespace std;
int main(){
    int a, sum = 1;
    cin >> a;
    cout << '1';
    for(int i = 2; i < a; i++){
        if( a % i == 0){
            cout << "+" << i;
            sum += i;
        }
    }
    cout << "=" << sum;
}