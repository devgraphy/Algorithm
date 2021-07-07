/* ----------<알고리즘>-----
while begin == target 일 때 까지
    words를 순회하면서
        begin과 일치하는 문자의 개수를 파악한 후
        그걸 다시 비긴에 다시 넣어
    
이 알고리즘은 문자열 2개가 일치하는 것 먼저 처리하는 걸 선택하기 때문에 여러 경우의 수를 고려하지 못한다.
*/
/* 예외 케이스
target이 words에 있어도 만들 수 없는 경우는?
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
int cnt[55];
int solution(string begin, string target, vector<string> words) {
    unordered_map<string, int> map;
    int answer = 0;
    for(int i = 0; i < words.size(); i++){
        map[words[i]]++;
    }
    if(map.find(target) == map.end())
        return 0;
    while(begin != target){
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length();j++){
                if(begin[j] == words[i][j])
                    cnt[i]++;
            }
            if(cnt[i] == 2){
                begin = words[i];
                answer++;
                break;
            }
        }
    }
    return answer;
}