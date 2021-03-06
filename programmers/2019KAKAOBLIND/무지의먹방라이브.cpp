/* ----------<문제 정의>----------
문제: 배열 1초씩 깎아서 중단 이후의 배열 인덱스
입력: 1<=k<=10조
출력: k 초 후 섭취할 음식의 인덱스, 없으면 -1 반환(단, 인덱스는 1부터)
*/
/* ----------<알고리즘: o(k)>----------
가장 기본적인 알고리즘 - 시간 초과
하나씩 1씩 깎아나가기(0인 곳은 건너뛰기)
다음 음식은 바로 다음이 아니라 현재 음식을 찾아 번호 출력
한번만 순회해도 효율성 테스트 실패

전체 음식이 k보다 큰 경우 -> 섭취해야할 음식이 없다고 미리 판단할 수 있다. 그러나 전체 순회해야 할 수 있다. 


while k > 0: //k초 동안 음식 섭취
-> 1 이상의 음식들만 깎는다.
-> 이미 음식 소진 다 했을 경우 무한 루프에 빠지게 된다.
-> basecase: 음식이 하나도 안 남음을 인지하고 빠져나가야 한다.
    -> 미리 한번 순회해서 파악해놔야겠다. sum < k 판단하여 시작 전에 바로 결과 반환
    
이후 섭취할 수 있는 음식 탐색
    1 이상의 음식이 발견되면 바로 인덱스 정보 얻고 break
*/
/* -----<주의할 것>-----
반복문에서 항상 basecase를 고려해야 한다.
조건에 쓰인 변수가 반복문 내부에서 basecase에 닿도록 처리문을 써줘야 한다.
*/
/* -----<새롭게 안 것>-----
세그멘테이션 폴트는 무한루프가 발생할 때도 오류를 뱉는다.
*/
/* -----<채점 결과>-----
정확성: 32/32
효율성: 0/8
*/

/* ----------<시간개선 알고리즘:o(nlogn)>----------
* 유형 힌트: 정렬, 벡터|우선순위큐
* 이유:
 - 음식의 크기를 기준으로 정렬하면 맨 앞의 음식양은 최솟값이므로 최솟값을 기준으로 섭취가능한 음식양을 초과할 일 없이 한번에 k를 계산하는게 가능해진다.
 
 - 처리한 음식마다 pretime 변수를 계속 갱신하면서 이전 음식의 높이를 앎으로써 현재 음식 높이와 차이를 구해 현재 남은 음식의 양을 알 수 있다.
 그래서 일일이 전체 음식의 양을 깎을 필요가 없다. -> 여기서 일일이 깎게 될 경우 시간 초과다.

* 정렬 기준: (2번의 정렬(nlogn)이 필요 -> 240만번*2 -> 충분!)
1. 음식양(음식양을 기준으로 오름차순 정렬) 
2. 인덱스 정보(마지막에 인덱스 정보를 출력해야하고, 다른 기준으로 먼저 정렬할 경우 인덱스 정보를 잃기 때문에 함께 저장)
*/
/* -----<궁금한 것>-----
* 정렬까지 ok. 어떻게 음식을 섭취해서 연산 속도를 줄일 것인지?
 - 최소 음식의 양을 기준으로 한 번에 음식을 제거해 나간다.

* 남은 음식 가지 수를 알기 위해 매번 순회해서 크기 알아내야 하는지?
 - 한번의 순회로 끝나기 때문에 처음 크기를 구한 것을 하나의 음식을 처리할 때마다 하나씩 깎아주어 파악할 수 있다.

* 남은 음식의 양을 알기 위해 원소 하나씩 방문하여 차감해야 하는지?
 - pretime 변수가 그 역할을 한다. (현재음식양-pretime)*n 일일이 원소를 방문하는게 아니라 점프하게 된다.

* pair<int, int>> 타입의 vector 정렬 comp 작성법
 - 파라미터로는 타입인 pair<int, int>가 들어간다.
*/
/* -----<새롭게 안 것>-----
pair 타입은 아무런 조작이 없으면 처음 값을 기준으로 정렬한다.
같은 타입의 곱하기 연산의 경우, 해당 타입의 최대 허용값을 넘는 것에 대비해 처리해주어야 한다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    int n = food_times.size();
    // 정렬하기 위해 (음식양, 인덱스 정보)로 vector 생성
    vector<pair<int, int>> foods;
    for(int i = 0; i < n; i++)
        foods.push_back(make_pair(food_times.at(i), i + 1));
    
    // pair 중 첫번째(음식양)을 기준으로 정렬
    sort(foods.begin(), foods.end());
    
    // 벡터 한 번 순회하면서, 첫번째 음식을 기준으로 k를 한번에 계산
    vector<pair<int, int>>::iterator iter;
    int pretime = 0;    // 이전 음식의 양과 차이를 구하여 존재 여부 확인 및 남은 양 확인
    for(iter = foods.begin(); iter != foods.end(); ++iter, --n){
        // int끼리의 곱은 오버플로우가 초래할 수 있음
        long long spend = (long long)(iter->first-pretime)*n;   
        if(spend == 0) continue;
        else{
            // 최소 음식의 양을 기준으로 모든 음식을 먹을 때, 섭취해야할 양보다 작은 경우
            if(spend <= k){ 
                k-= spend;
                pretime = iter->first;
            } else{         // 그렇지 않은 경우엔 
                
                k %= n;
                // 처음 인덱스 정보를 기준으로 재정렬.
                // 기존 음식들은 삭제되지 않았기 때문에 반드시 현재까지 처리된 iterator 정보를 넣어줘야 한다.
                sort(iter, foods.end(), comp); 
                // 처음 인덱스 정보를 i + 1로 저장했으므로 인덱스를 그대로 출력한다.
                return (iter + k)->second;
            }   
        }
    }
    // k 안에 이미 모든 음식을 섭취한 경우 = 더 이상 섭취할 음식이 없는 경우 = for-else-return에 걸리지 못한 경우
    return -1;
}