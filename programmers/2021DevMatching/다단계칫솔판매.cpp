/* ----------<문제 정의>----------
문제: 각 판매원마다 상향식으로 일정한 비율의 이익 배분
입력: 판매원 <= 1만 , 추천인 <= 1만, 셀러 <= 10만   -> o(seller*log(판매원))
출력: 판매원마다 배분된 이익금 총합(enroll 명시 순서대로)
*/
/* ----------<알고리즘: o(10만*log(1만))>----------
* 탐색 시간을 줄이기 위해 hash를 사용
마지막에 enroll 순서로 출력할 때, 해쉬로 탐색해서 출력

* 정방향으로 값을 넘기는 구조로 밖에 구현이 안 된다고 판단(여기선 아래->위가 정방향)
= dfs로 역방향으로 값 반환하면서 돌아올 수 없다고 판단

* dfs 흐름
자신의 판매 수익금 90%는 해쉬에 저장(X)-> 다른 자식 판매원에 의해 중복 계산이 될 수 있으므로
한명의 판매수익금에 대해 수수료만 처리하는 방식(V)
*/
/* -----<예외 케이스>-----
* mary가 1원을 더 얻음. 10% 계산과 관련
young(1080)->edward(108)->mary(11)->center(1) 이 정상
young(1080)->edward(108)->mary(12) 내 경우
if(int(fee*0.1) <= 1 ){   // 판매원으로부터 받은 수수료가 1원 이하!
    enr_fee[enr] += fee;
-> if(int(fee*0.1) < 1 )
    
* mary가 1원을 덜 얻음. 10% 계산과 관련
young(1080)->edward(108)->mary(10)->center(1) 내 경우
10%는 절사하므로 90%는 반올림하여 처리(문제에는 명시되어있지 않음)
-> 여기서 치명적인 계산 오류가 발생함. 하나는 임의 절사하고 다른 하나도 별도의 연산을 하면 오차가 발생함. 따라서 명시된 절사 연산한 것과 이것을 전체에서 빼줘서 나머지 값을 구한다.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> enr_fee;
unordered_map<string, string> enr_ref;

void dfs(string enr, int fee, vector<string>& enroll, vector<string>& referral, vector<string>& seller, vector<int>& amount){
    //basecase
    if(fee < 10 || enr == "-" ){   // 판매원으로부터 받은 수수료가 1원 미만인 경우
        enr_fee[enr] += fee;
        //cout << "last fee: " << fee << endl;
        return;
    }
    /*  두 개의 if를 하나의 조건문에 OR로 묶음
    if(enr == "-")return;
    */
    int ss = fee * 0.1;
    enr_fee[enr] += (fee-ss);
    dfs(enr_ref[enr], ss,  enroll, referral, seller, amount);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    // 각 seller 에 대해 dfs로 tree를 타고 올라간다.
    int seller_size = seller.size();    // amount 크기와 같음
    int enroll_size = enroll.size();
    int referral_size = referral.size();
    
    for(int i = 0; i < enroll_size; i++){
        enr_fee[enroll[i]] = 0;
        enr_ref[enroll[i]] = referral[i];
    }
    for(int i = 0; i < seller_size; i++ ){
        // enroll, referral, seller, amount는 얕은 복사
        dfs(seller[i], amount[i]*100, enroll, referral, seller, amount);
    }
    for(int i = 0; i < enroll_size; i++){
        answer.push_back(enr_fee[enroll[i]]);
    }
    return answer;
}