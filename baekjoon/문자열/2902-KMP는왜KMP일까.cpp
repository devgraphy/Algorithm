/* ----------<접근법>----------
첫번째 원소 또는 '-' 다음 원소를 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(i == 0) cout << s[i];
        if(s[i] == '-') cout << s[i+1];
    }   
}