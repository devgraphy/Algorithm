/* ----------<문제정의>----------
문제:모든 배열의 값을 어떤 연산을 통해 K 이상을 만족하게 한다.
입력: 배열, K
출력: 최소 계산 횟수
*/
/* ----------<알고리즘:O(n * nlogn)>----------
(참고: 정렬알고리즘의 시간 복잡도는 nlogn이다.)

내림차순으로 계속 정렬하면서 가장 작은 두 개의 값을 스코빌 지수 계산
계산에 사용한 원소 팝
계산한 결과 값 푸시

while(scoville.size() > 1)
    정렬(내림차순-pop back을 해야하므로)
    if(배열[0] >= K)
        return cnt;
    배열[0], 배열[1] 섞은 스코빌 지수 계산
    배열[0], 배열[1] pop back
    계산값 푸시
    cnt++;
if(scoville[0] >= K)
    return cnt;
else
    return -1;
*/
/* ----------<채점 결과>----------
정확성: 76.2 (TC 16/16)
효율성: 0.0
합계: 76.2 / 100.0
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int temp;
    while(scoville.size() > 1){
        sort(scoville.begin(), scoville.end(), greater<int>());    
        if(scoville[scoville.size()-1] >= K)
            return answer;
        temp = scoville[scoville.size()-1] + scoville[scoville.size()-2]*2;
        scoville.pop_back();
        scoville.pop_back();
        scoville.push_back(temp);
        answer++;
    }   
    if(scoville[0] >= K)
        return answer;
    else
        return -1;
}