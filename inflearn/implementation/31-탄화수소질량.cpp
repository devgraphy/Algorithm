// 순회하며 C뒤에 문자 추출, H뒤에 문자 추출
// 입력은 한 자리수가 아닐 수 있다.
// weakpoint: 문자의 숫자화
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    int c=0, h=0, i, pos;
    cin >> str;
    if(str[1]=='H'){
        c=1;
        pos=1;
    }
    else{
        for(i = 1; str[i]!='H';i++){
            c=c*10+(str[i]-48);
        }
        pos = i;
    }
    if(str[pos+1]=='\0') h = 1;
    else{
        for(i=pos+1;str[i]!='\0';i++){
            h=h*10+(str[i]-48);
        }
    }
    cout << c*12+h;
}
