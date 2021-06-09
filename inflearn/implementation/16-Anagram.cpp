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
    }
    else{                               // 길이 같으면
        for(int i = 0; i < str1.length(); i++){ // 요소 파악
            a[str1[i]] += 1;
            b[str2[i]] += 1;
        }

        for(auto it = a.begin(); it != a.end(); it++){
            if(it->second != b[it->first]){
                chk = 1;
                cout << "NO";
                return 0;
            }
        }
        if(chk == 0){
            cout << "YES";
        }
    }

}