/* ----------<문제 정의>----------
문제: 팰린드롬수(대칭)
*/
/* ----------<접근법>----------
i와 전체길이-i-1를 각각 비교하는데 i가 전체길이/2 까지만 비교한다.
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string input, result;
    int len;
    while(1){
        cin >> input;
        result = "yes";
        len = input.length();
        if(input == "0") break;
        for(int i = 0; i < len/2; i++){
            if(input[i] != input[len-i-1]){
                result = "no";
                break;
            }
        }
        cout << result << '\n';
    }
}