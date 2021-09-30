/* ----------<문제 정의>----------
문제: 로그를 통해 현재 회사에 있는 사람 찾기
입력: 로그 기록의 수 n, 이름 enter 또는 leave 
출력: 현재 회사에 있는 사람 이름 출력
*/
/* ----------<접근법>----------
이름으로 고유 사람을 식별하는 것을 o(1)에 수행하는 해시 자료구조를 이용한다. 
map<string, string>
enter면 등록
leave면 기존 map에서 삭제
*/
/* ----------<모르는 것>----------
1. 해시맵에 저장한 데이터 정렬하기 
    hash_map(unordered_map): 해시맵은 정렬하지 않은 채 해시 테이블을 통해 자료를 넣는다.
    -> map 자료구조 이용
    map: 자동으로 정렬(key를 기준으로 정렬하며 오름차순 정렬)
2. iterator 역순 순회
    역방향 반복자를 이용
3. map에서 key값 출력하기
    it->first, it->second 형식으로 값 반환
*/
/* -----<알고리즘>-----
이름 enter/leave 입력
이름 enter이면 먼저 존재하는지 확인하고 없으면 insert
이름 leave이면 먼저 존재하는지 확인하고 있으면 삭제
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    int n;
    string a, b;
    map<string, string> m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;  // 이름 enter/leave
        if(b == "enter" && m.find(a) == m.end()){
            m.insert(make_pair(a,b));
        }
        if(b == "leave" && m.find(a)!= m.end()){
            m.erase(m.find(a));
        }
    }
    // 순회하면서 사전순 역순으로 출력
    map<string, string>::reverse_iterator rit;
    for(rit = m.rbegin(); rit!= m.rend(); rit++){
        cout << rit->first << '\n';
    }
}