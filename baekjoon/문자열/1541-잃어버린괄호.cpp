/* ----------<문제 정의>----------
문제: 모든 괄호의 경우의 수를 고려한 연산의 최솟값
주의 사항: 괄호 영역을 정할 때, 부호 포함 여부에 따라 결과가 달라진다.
*/
/* ----------<접근법>----------
브루트포스이다.
(부호) 1.피연산자 (부호) 2.피연산자 (부호) 3.피연산자
경우의 수는
(1.피연산자 (부호) 2.피연산자) (부호) 3.피연산자
1.피연산자+((부호) 2.피연산자 (부호) 3.피연산자)
1.피연산자 (부호) (2.피연산자 (부호) 3.피연산자)

세 변수를 각각 정의하고 입력받는다.
첫번째와 마지막은 반드시 숫자. 숫자는 0으로 시작할 수 있다.
첫번째 부호와 두 번째 부호를 위한 변수를 각각 생성한다.
세 가지 경우의 수에 대해서 각각 계산한다.
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int main(){
    string exp;
    string operand[3];
    int op[2];  // 0: +, 1: -
    int operand_idx = 0;
    int operator_idx = 0;
    int min_val = INT_MAX;
    int tempsum = 0;
    cin >> exp;
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] >= '0' && exp[i] <='9'){
            operand[operand_idx]+=exp[i];
        }
        else{
            if(exp[i] == '+') op[operator_idx++] = 0;
            else op[operator_idx++] = 1;
            operand_idx++;
        }
    }
    //tempsum = operand[0]+ operand[1] operand[2]
    // 첫 번째 케이스
    if(op[0] == 0) tempsum +=(stoi(operand[0]) + stoi(operand[1]));
    else tempsum +=(stoi(operand[0]) - stoi(operand[1]));
    if(op[1] == 0) tempsum =(tempsum + stoi(operand[2]));
    else tempsum =(tempsum - stoi(operand[1]));
    if(tempsum < min_val) min_val = tempsum;
    tempsum = 0;
    // 두 번째 케이스
    if(op[0] == 0) tempsum = stoi(operand[0]) + stoi(operand[1]);
    else tempsum = stoi(operand[0]) - stoi(operand[1]);
    if(op[1] == 0) tempsum =(tempsum + stoi(operand[2]));
    else tempsum =(tempsum - stoi(operand[2]));
    if(tempsum < min_val) min_val = tempsum;
    tempsum = 0;
    // 세 번째 케이스
    if(op[1] == 0) tempsum = stoi(operand[1]) + stoi(operand[2]);
    else tempsum = stoi(operand[1]) - stoi(operand[2]);
    if(op[0] == 0) tempsum =(tempsum + stoi(operand[0]));
    else tempsum =(stoi(operand[0]) - tempsum);
    if(tempsum < min_val) min_val = tempsum;
    
    cout << min_val;
}

