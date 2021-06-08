// 순회 시 공백이면 skip, 아니면 (char)tolower 출력

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> b;
int main(){
    string a;
    getline(cin, a);
    for(int i = 0; i < a.length();i++){
        if(a[i]!=' ')
            cout << (char)tolower(a[i]);
    }
    
}