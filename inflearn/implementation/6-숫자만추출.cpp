// ASCII 로 숫자추출, stoi로 맨앞 0 자동 탈락
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    char num[10];
    int p = 0;
    int cnt = 0;
    getline(cin, str);
    for(int i = 0; i <= str.length(); i++){
        if((int)str[i] >= 48 && (int)str[i] <=57)
            num[p++]=str[i];
    }
    cout << stoi(num) << endl;
    for(int i = 1; i <= stoi(num); i++){
        if(stoi(num) % i == 0)
            cnt++;
    }
    cout << cnt;

}