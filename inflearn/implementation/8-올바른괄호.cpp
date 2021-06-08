// stack 개념 활용

#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    int cnt = 0;
    cin >> str;
    for(int i = 0; i < str.length();i++){
        if(str[i] == '(')
            cnt++;
        else
            cnt--;
        if(cnt < 0){
            cout << "NO";
            return 0;
        }
    }
    if(cnt > 0){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}