/* ----------<문제 정의>----------
문제: 최초로 나타는 반복하지 않는 문자 찾기
입력: 문자열 1<=s.length<=10^5
출력: 최초로 나타는 반복하지 않는 문자의 인덱스
*/
/* ----------<알고리즘>----------
반복하지 않은지 확인하려면 모든 문자 순회는 불가피하다.
    각 문자에 대해서 반복횟수를 파악한다. (해시 이용)
다시 순회하면서 
    각 문자에 대해 해시값이 1(한번만 나타난다)이면
        인덱스 반환 후 종료
    안 나타나면
        -1 반환 후 종료
*/
/* ----------<궁금한 것>----------
1. map 초기화되어있나 ? 왜 오류가 안나지?
for(int i = 0; i < s.length(); i++)
    map[s[i]]++;

=>std:: map 종류의 operator[]는 항목이 없으면 자동 초기값 만든다.
초기값은 value type의 기본 초기값 (수 종류는 0으로 string은 "")
*/
class Solution {
public:
    
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++)
            map[s[i]]++;
        for(int i = 0; i < s.length(); i++){
            if(map[s[i]] == 1)
                return i;
        }
        return -1;    
    }
};