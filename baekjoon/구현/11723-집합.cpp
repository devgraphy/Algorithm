/* ----------<문제 정의>----------
문제: 집합 구현
입력: 명령어 숫자
출력: 명령어에 따른 값
*/
/* ----------<알고리즘>----------
시간 초과
n보다 적게 입력을 받고 끝남

set 라이브러리 사용 -> set.find() 메서드를 사용하여 조회하는데 O(N)
*/
/* -----<개선 방안>-----
- 조회시간을 줄이기 위해 배열을 사용할 수 있다.
- 여기서 공간까지 줄이기 위해서 비트마스킹을 사용할 수 있다.
*/

#include<iostream>
#include <string>
#include<set>
using namespace std;
int main(){
    set<int> s;
    int n;
    string comm;
    int input;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> comm;
        if(comm == "add"){
            cin >> input;
            s.insert(input);
        } 
        else if(comm == "remove"){
            cin >> input;
            s.erase(input);
        }
        else if(comm == "check"){
            cin >> input;
            if(s.find(input) != s.end()){
                cout << 1 << endl;
            }
            else cout << 0 << endl;
        }
        else if(comm == "toggle"){
            cin >> input;
            if(s.find(input) != s.end())
                s.erase(input);
            else
                s.insert(input);
        }
        else if(comm == "all"){
            for(int i = 1; i <= 20; i++){
                s.insert(i);
            }
        }
        else if(comm == "empty"){
            if(s.size()>0){
                for(auto &p : s)
                s.erase(p);
            }
            
        }
        else if(comm == "print"){
            for(auto &p : s){
                cout << p << endl;
            }
        }

    }
}