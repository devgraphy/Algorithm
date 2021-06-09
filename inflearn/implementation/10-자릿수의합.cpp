#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, x;
    int temp = 0;
    int max = -2147000000;
    int max_p = 0;
    int num[101];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    for(int i = 0; i < n; i++){
        x = num[i];
        while(x > 0){
            temp = temp + (x % 10);
            x/=10;
        } 
        if(max < temp){
            max = temp;
            max_p = i;
        }
        if(max == temp){
            if(num[max_p]<num[i])
                max_p = i;
        }
        temp = 0;
    }
    cout << num[max_p];
}