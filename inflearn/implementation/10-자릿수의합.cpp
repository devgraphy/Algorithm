#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    int temp = 0;
    int max = -2147000000;
    int max_p = 0;
    string str[101];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> str[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < str[i].length();j++){
            temp+= (str[i][j]-'0');
        }
        if(max < temp){
            max = temp;
            max_p = i;
        }
        if(max == temp){
            if(stoi(str[max_p])<stoi(str[i]))
                max_p = i;
        }
        temp = 0;
    }
    cout << str[max_p];
}