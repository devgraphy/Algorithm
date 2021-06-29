/* ----------<문제정의>----------
문제: 각 스테이지의 실패율을 찾아 실패율과 스테이지 번호 기준으로 정렬하기
입력: 전체 스테이지 수, 유저들마다 도달한 스테이지 배열
출력: 실패율이 높은 스테이지순으로 정렬된 배열(단, 실패율이 같을 경우 스테이지 번호가 작은 순)
*/
/* ----------<알고리즘>----------
누적합(Prefix sum) > 2for bruteforce
누적합을 이용한 실패율 계산: a[i] / 전체 stages 사이즈 중에 dp[i-1] (분모 의미:바로 전 스테이지까지 누적되어 도달한 사람들 이외의 사람들은 해당 스테이지를 도달한 것으로 본다.)
실패율(내림차순), 스테이지 번호(실패율 같을 경우 오름차순) 기준 스테이지 번호 정렬 (이 문제의 핵심!)
*/
/* ----------<궁금한 것>----------
다중 조건 정렬(c++ pair sort로 검색) -> 별도 함수 제작하여 sort 인자로 넘긴다.
*/
/* ----------<예외 케이스>----------
"스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0으로 정의한다"
-> 0으로 나누는 경우이기 때문에 반드시 처리해주어야 함
*/
/* ----------<배운 점>----------
사소한 제한사항 하나 놓치지 말자.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200002];  // 스테이지별 도달한 사람
float dp[505];  // 해당 스테이지까지 도달한 사람 누적합
bool compare(const pair<float, int>& a, const pair<float, int>& b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float,int>> fail_order;
    for(int i = 0; i < stages.size();i++){  // 각 스테이지에 도달한 사람 수 파악
        a[stages[i]]++;
    }
    for(int i = 1; i <= N;i++){             // 누계 스테이지 도달한 사람 수 파악
        dp[i] = dp[i-1] + a[i];
    }
    for(int i = 1; i <= N;i++){             // 실패율 구하기
        if(stages.size()-dp[i-1] == 0)
            fail_order.push_back(make_pair(0, i));
        else
            fail_order.push_back(make_pair(a[i]/(stages.size()-dp[i-1]), i));
        //cout << i << " : " << a[i]/(stages.size()-dp[i-1]) << "  " << stages.size()-dp[i-1]<< endl;
    }   
    // 실패율이 같은 경우는 스테이지 번호가 낮은 것으로 출력한다.
    // 2개가 같을 수도 3개가 같을 수도 있다.
    sort(fail_order.begin(),fail_order.begin()+N,compare);
    for(int i = 0; i < fail_order.size();i++){
        answer.push_back(fail_order[i].second);
    }        
    return answer;
}