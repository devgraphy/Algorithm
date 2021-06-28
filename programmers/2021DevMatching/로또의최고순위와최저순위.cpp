/* ----------<문제 정의>----------
문제: 로또의 최고 순위와 최저 순위 찾기
입력: lottos-구매번호, win-nums-당첨번호 모두 길이 6인 정수 배열
출력: 최고 순위와 최저 순위를 담은 배열
*/
/* ----------<알고리즘>----------
(당첨 번호, 당첨 아닌 번호, 알아볼 수 없는 번호 3가지 유형 존재)
당첨번호 순회하면서
    당첨 번호 체크(배열 또는 해쉬 이용)
로또구매번호 순회하면서
    당첨번호와 알 수 없는 번호의 개수를 파악
당첨번호로 최저 순위 결정 후, 알 수 없는 번호로 최고 순위 결정
*/ 
/* ----------<예외 케이스>----------
하나도 안 맞고 0도 없는 경우
-> 하나도 안 맞으면 최저 6위 0의 개수에 따라 최고 순위가 달라짐
-> 당첨번호가 0개일 때와 당첨번호가 1개 이상일 때 순위 변화가 달라진다.
-> 또한, 당첨번호가 0개일 때, 알 수 없는 번호의 개수가 0개이면 변화가 없어야 하고, 1개이어도 변화가 없어야 한다. 2개부터 변화가 생긴다.
-> 따라서, 알 수 없는 번호의 개수도 0개와 1개이상의 경우로 구분해야 한다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int win_cnt = 0;
    int zero_cnt = 0;
    unordered_map<int, int> winmap;
    for(int i = 0; i < 6;i++){
        winmap[win_nums[i]] = 1;
    }
    for(int i = 0; i < 6;i++){
        if(lottos[i] != 0){
            if(winmap.end() != winmap.find(lottos[i]))    // 당첨번호 개수 파악
                win_cnt++;
        }
        else   zero_cnt++;        // 알아볼 수 없는 번호 파악
    }
    if(win_cnt <= 1) answer.push_back(6);   // 당첨 번호 개수 - 최저 순위 결정
    else answer.push_back(7-win_cnt);
   
    if(win_cnt == 0){
        if(zero_cnt == 0)                   // 알아볼 수 없는 번호 개수 - 최고 순위 결정
            answer.push_back(answer[0]-zero_cnt);
        else
            answer.push_back(answer[0]-zero_cnt+1);
    }      
    else if(win_cnt >= 1)
        answer.push_back(answer[0]-zero_cnt);
    sort(answer.begin(), answer.end());     // 최고순위, 최저순위 순 정렬
    return answer;
}