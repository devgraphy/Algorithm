// map
// 알파벳 26개
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char, int> a;
map<char, int> b;
int main(){
    string str1, str2;
    int chk = 0;
    cin >> str1 >> str2;
    if(str1.length() != str2.length()){ // 길이 다르면
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < str1[i] != '\0'; i++){
        if(str1[i]>=65 && str1[i]<=90){
            a[str1[i]-65]++;
        }
        else{
            a[str1[i]-71]++;
        }
        if(str2[i]>=65 && str2[i]<=90){
            b[str2[i]-65]++;
        }
        else{
            b[str2[i]-71]++;
        }
    }
    for(int i = 0; i < 52; i++){
        if(a[i] != b[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}