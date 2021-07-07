/* ----------<알고리즘>----------
while begin == target 일 때 까지
    words를 순회하면서
        begin과 일치하는 문자의 개수를 파악한 후
        그걸 다시 비긴에 다시 넣어
    
이 알고리즘은 문자열 2개가 일치하는 것 먼저 처리하는 걸 선택하기 때문에 여러 경우의 수를 고려하지 못한다.
*/
/* ----------<예외 케이스>----------ㄴ
target이 words에 있어도 만들 수 없는 경우는?
*/
/* ----------<알고리즘>----------
DFS를 해야하는 이유: 모든 경우의 수 고려하기(또 다른 bruteforce), 최소 경로 찾기

dfs(depth, begin, target, words){
    basecase: begin == target
        depth 최솟값 갱신
    words 순회하면서
        방문한 단어는 스킵 
        문자열 비교
        하나 빼고 모두 일치하면
            방문 표시
            dfs(depth+1, words[i], target, words)
            방문 해제
}

*/
#include <string>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
int visit[55];
int minval = INT_MAX;
void dfs(int num, string begin, string target, vector<string> &words){
    if(begin == target){
        if(minval > num)
            minval = num;
        return;
    }
    int cnt;
    for(int i = 0; i < words.size(); i++){  // words를 순회하면서
        cnt = 0;
        if(visit[i]!=0)
            continue;
        for(int j = 0; j < words[i].length(); j++){ // begin과 words[i]의 문자열을 일일이 비교
            if(begin[j] == words[i][j])
                cnt++;
        }
        if(cnt == words[i].length()-1){ 
            visit[i] = 1;
            dfs(num+1, words[i], target, words);
            visit[i] = 0;
        }
    }   
}
int solution(string begin, string target, vector<string> words) {
    dfs(0, begin, target, words);
    if(minval == INT_MAX)
        return 0;
    else
        return minval;
}