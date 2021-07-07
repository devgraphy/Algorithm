/* ----------<문제 정의>----------
문제: 각 작업마다 요청부터 종료까지 걸린 시간의 평균의 최솟값
입력: 2차원 배열
출력: 총 작업의 최소 평균 시간
*/
/* ----------<알고리즘>----------
우선순위가 높은 작업을 먼저 처리한다. -> 우선순위 큐 필요
문제 정의에 따라, 우선순위가 높은 작업 = 현재 처리되고 있는 작업이 끝나는 시간보다 먼저 들어온 작업 중에 수행시간이 가장 짧은 것

핵심: 각 작업에 대해서 조건에 만족하는 나머지 작업들을 우선순위큐에 추가
한 사이클에 대해 처리할 작업을 명확하게 정의
job 순회와 pq에서 꺼내는 시점을 정하는게 관건

각 작업에 대한 처리와 우선순위큐가 병렬로 운영된다. => OR!

1. while - jobs를 모두 pq에 도달하지 않는한||pq가 비어있지 않는 한 => 둘 다 만족하지 못 했을 때 작업을 멈춘다.
    // 현재 작업에 대해 계산한 시간을 기준으로 다른 작업을 추가해준다.
    2. if - jobs[i][0] <= 현재 처리되는 작업의 끝나는 시간(time) 
        pq.push(jobs[i++]);
        continue;
    3. if - pq가 empty가 아니면 현재 진행할 작업(pq.top()) 에 대해 시간을 계산해준다.
        finish_time
        process_time
        pq.pop()
    4. else - empty면 바로 다음 작업을 넣어준다.
        현재 작업을 pq에 추가
*/
/* ----------<궁금한 것>----------
1. 2차원 벡터의 minheap 구현 방법
2. (문제 정의와 관련)
- 현재 처리되는 작업은 어떻게 알고, 어떻게 현재 처리하는 작업의 끝나는 시간을 계산하지?
- 평균 작업 시간은 어떻게 계산해 나가는지?

3. minheap 구현하기 위한 정렬 방법 -> 2차원 배열로 정의된 우선순위큐는 첫번째 원소를 기준으로 정렬한다. 그래서 한 참조글에서는 pq에 작업을 추가할 때, 원소의 위치를 바꾼다. 2차원 형태의 우선순위 큐도 greater, less 함수를 사용할 수 있다.
*/

#include <string> 
#include <vector> 
#include <iostream> 
#include <queue> 
#include <algorithm> 
using namespace std; 
int solution(vector<vector<int>> jobs) { 
    int answer = 0; 
    sort(jobs.begin(), jobs.end()); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    int i = 0, finish_time = 0, process_time = 0;
    while(i <= jobs.size() || !pq.empty()){
        if(finish_time >= jobs[i][0]){
            pq.push(make_pair(jobs[i][1], jobs[i][0]));
            i++;
            continue;
        }
        if(pq.empty())
            pq.push(make_pair(jobs[i][1], jobs[i][0]));
        else{
            finish_time += pq.top().first;
            process_time += (finish_time-pq.top().second)+pq.top().first;
            pq.pop();
        }
    }
    return process_time / jobs.size(); 
}