/* ----------<궁금한 것>----------
- 연산자의 우선순위 순열 구현법 -> {0, 1, 2}와 next_permutation으로 순열 만들고 연산자 배열과 대응시킴
- (연산자가 섞인)문자열의 숫자화, 피연산자와 연산자 구분 -> '0'&&'9' 활용하여 숫자 추출
- 중위표기 문자열에서 우선순위별 계산 방법 -> 우선순위별 brutefoce 계산 
*/

/* ----------<새롭게 안 것>----------
- vector에 중간 삭제, 중간 삽입 가능하다! (단, iterator로 접근해야 한다.)
    - 동적 배열로 구현되어 있다.
    - 그래서 컨테이너 끝이 아닌 곳에 삽입/제거 시 성능히 현저히 떨어진다.
    - 동적이라 확장/축소가 편하나 확장 시 비용이 크다.
*/
/* ----------<모델링>----------
문제: 연산자의 우선순위 경우의 수에 따라 수식을 계산하여 최댓값 찾기
입력: 피연산자+연산자 문자열(100이하)
출력: 계산값
알고리즘(bruteforce): o(3!*(n^2))
2개의 스택 정의(연산자, 피연산자)
피연산자, 연산자 구분하여 vector에 푸시
연산자 순열 구성 후, 경우의 수마다 연산자 우선순위별로 반복 계산
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calc(long long a, long long b, char op){
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    else
        return a * b;
}


long long solution(string expression) {
    long long answer = 0;
    vector<char> base_operator;
    vector<long long> base_operand;
    vector<char> temp_operator;
    vector<long long> temp_operand;
    string temp;
    // 피연산자와 연산자 추출
    for(int i = 0; i < expression.length();i++){
        if(expression[i] >= '0' && expression[i] <='9'){
            temp+=expression[i];
        }
        else{
            base_operator.push_back(expression[i]);
            base_operand.push_back(stoll(temp));
            temp="";
        }
    }
    base_operand.push_back(stoll(temp));
    
    vector<int> perm = {0, 1, 2};
    string op="+-*";
    do{
        temp_operator = base_operator;
        temp_operand = base_operand;
        long long res;
        for(int i = 0; i < perm.size();i++){
            for(int j = 0; j < temp_operator.size();){
                if(temp_operator[j] == op[perm[i]]){
                    res = (temp_operand[j], temp_operand[j+1], op[perm[i]]);
                    temp_operator.erase(temp_operator.begin()+j);
                    temp_operand.erase(temp_operand.begin()+j);
                    temp_operand.erase(temp_operand.begin()+j+1);
                    temp_operand.insert(temp_operand.begin()+j,res);
                }
                else
                    j++;
            }
        }
        answer = max(answer, abs(temp_operand[0]));
        
    }while(next_permutation(perm.begin(), perm.end()));
    return answer;
}