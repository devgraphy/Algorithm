#include <iostream>
using namespace std;
int num[50001];
int main(){
    int a;
    cin >> a;
    for(int i = 1; i <= a; i++){
        for(int j = i; j <= a; j = j + i){
            num[j]++;
        }
    }
    for(int i = 1; i <= a; i++)
        cout << num[i] << " ";
}