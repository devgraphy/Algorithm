#include <iostream>
#include <string>
using namespace std;
int main(){
    int cnt = 1, result = 0;
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        result = 0;
        cnt = 1;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == 'O'){
                result+=cnt;
                cnt++;
            }
            else cnt = 1;
        }
        cout << result << endl;
    }
}