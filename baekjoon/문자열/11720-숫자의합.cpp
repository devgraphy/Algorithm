#include<iostream>
#include<string>
using namespace std;
int main(){
    int n, sum = 0;
    string temp;
    cin >> n;
    cin >> temp;
    for(int i = 0; i < n; i++){
        sum+=temp[i]-'0';
    }
    cout << sum << endl;
}