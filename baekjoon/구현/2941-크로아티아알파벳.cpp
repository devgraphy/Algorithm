/* ----------<문제 정의>----------
문제:문자 재정의
입력:문자열
출력:크로아티아 알파벳 개수
*/
/* ----------<알고리즘>----------
풀이시간:45분
메모리:2024KB
시간:0ms

변환된 시작 문자열에 대해 키, 값 자료구조를 만든다.
단, 같은 시작 문자에 대해서는 하나의 키에 대해 여러 값을 갖는 구조이다.
그러므로 2차원 배열을 만든다.

변환된 크로아티아 알파벳을 시작 문자열에 대해 키, 값 구조로 입력해둔다.
입력된 문자열을 순회하면서 tf의 시작 문자의 일치 여부를 확인한다.
일치하면 그 중에서 정확히 문자열까지 일치하는지 tf를 순회하면서 확인한다.
    정확히 일치하면 cnt 1증가, 해당 문자열 길이만큼 포인터 증가
    일치하지 않으면 cnt 1증가, 포인터 1증가
일치하지 않으면 cnt 1증가, 포인터 1증가
*/
/* ----------<알고리즘>----------
find, replace

문자열에서 원하는 문자열을 찾기 위해 find 사용
문자 재정의를 위해 replace 사용
*/
/* -----<새롭게 안 것>-----
find를 통해 못 찾은 반환값은 -1이다.
조건문은 반환값이 -1 이나 string::pos 와 같은지로 구성할 수 있다.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> croa[30];
int main(){
    vector<string> croa={"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};  // 벡터 초기화
    string str;
    cin >> str;
    int p = 0;
    for(int i = 0; i < croa.size(); i++){
        while(1){
            p = str.find(croa[i]);
            if(p == string::npos)
                break;
            str.replace(p, croa[i].length(),"#");
        }
    }
    cout << str.length();
}