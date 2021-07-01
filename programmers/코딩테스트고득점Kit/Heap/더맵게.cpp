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
/* ----------<시간개선 알고리즘>----------
우선순위큐 사용하여 삽입, 삭제 시 정렬하는데 소요되는 비용을 줄인다.
*/
/* ----------<새롭게 안 것>----------
우선순위 큐는 평범한 큐나 스택과 비슷한 축약 자료형
그러나 각 원소들은 우선순위를 갖고 있다.
우선순위 큐에서, 높은 우선순위를 가진 원소는 낮은 우선순위를 가진 원소보다 먼저 처리된다. 만약 두 원소가 같은 우선순위를 가진다면 그들은 큐에서 그들의 순서에 의해 처리된다.

우선순위 큐가 힙이라는 것은 널리 알려진 오류이다. 우선순위 큐는 "리스트"나 "맵"과 같이 추상적인 개념이다; 마치 리스트는 연결 리스트나 배열로 구현될 수 있는 것과 같이, 우선순위 큐는 힙이나 다양한 다른 방법을 이용해 구현될 수 있다.
heap은 최댓값 및 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안된 완전이진트리를 기본으로 한 자료구조
힙 속성: A가 B의 부모노드이면, A의 키값과 B의 키값 사이에는 대소관계가 성립한다.

*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++){
       pq.push(scoville[i]);
    }
    while(pq.size() > 1 && pq.top() < K){
        int a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push(a+b*2);
        answer++;
        
    }    
    if(pq.top() >= K)
        return answer;
    else
        return -1;
}