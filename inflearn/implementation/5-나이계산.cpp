// 뒷자리의 첫번째 숫자로 연대와 성별을 파악
// 앞자리 두 개 숫자로 정확한 연도를 구한다. 나이는 올해 2019에서 빼준다.

#include <iostream>
#include <string>
using namespace std;
int main(){
    string id;
    char sex;
    int birth, age;
    cin >> id;
    if((id[7]-'0') % 2 == 0){
        sex = 'W';
        if(id[7] == '2')
            birth = 1900;
        else if(id[7] == '4')
            birth = 2000;
    }
    else if((id[7]-'0') % 2 == 1){
        sex = 'M';
        if(id[7] == '1')
            birth = 1900;
        else if(id[7] == '3')
            birth = 2000;
    }
    birth += stoi(id.substr(0,2));
    age = 2019 - birth + 1;
    cout << age << " " << sex << endl;
}
