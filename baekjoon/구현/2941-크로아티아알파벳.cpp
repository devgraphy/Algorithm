/* -----<문제 정의>-----
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
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> tf[30];
int main(){
    // a는 ascii 코드로 97
    tf['c'-97].push_back("c=");
    tf['c'-97].push_back("c-");
    tf['d'-97].push_back("dz=");
    tf['d'-97].push_back("d-");
    tf['l'-97].push_back("lj");
    tf['n'-97].push_back("nj");
    tf['s'-97].push_back("s=");
    tf['z'-97].push_back("z=");
    string temp;
    int cnt = 0;
    int p = 0;      // 포인터
    int chk = 0;
    cin >> temp;    // 문자열 입력
    // 
    while(p < temp.length()){
        // 가리키는 문자에 대해 변환된 크로아티아 알파벳이 존재하면
        //cout<< p << endl;
        chk = 0;
        if(tf[temp[p]-97].size()>0){
            //cout << temp[p]-97 << endl;
            for(int i = 0; i < tf[temp[p]-97].size(); i++){
                if(temp.substr(p, tf[temp[p]-97][i].length()) == tf[temp[p]-97][i]){
                    //cout << tf[temp[p]-97][i] << endl;
                    cnt++;
                    p+=tf[temp[p]-97][i].length();
                    chk = 1;
                }
            }
            // tf에 시작 문자가 존재는 하지만 정확히 일치하지 않는 경우
            if(chk == 0){
                cnt++;
                p++;
            }
        }
        // tf에 시작 문자가 존재도 안 하는 경우
        else{   
            cnt++;
            p++;
        }
    }
    cout << cnt << endl;
    //cout << p << endl;
    //cout << tf['c'-97].size() << endl;
}