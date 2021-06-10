#include <iostream>
using namespace std;
int a[11];
int b[11];
int main(){
    int sum_a = 0;
    int sum_b = 0;
    char update = 'D';
    for(int i = 0; i < 10; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 10; i++){
        cin >> b[i];
    }
    for(int i = 0; i < 10; i++){
        if(a[i] > b[i]){
            sum_a+=3;
            update = 'A';
        }
        else if(a[i] < b[i]){
            sum_b+=3;
            update = 'B';
        }
        else{
            sum_a+=1;
            sum_b+=1;
        }
    }
    cout << sum_a << " " << sum_b << endl;
    if(sum_a > sum_b)
        cout << 'A';
    else if(sum_a < sum_b)
        cout << 'B';
    else
        cout << update;
    
}