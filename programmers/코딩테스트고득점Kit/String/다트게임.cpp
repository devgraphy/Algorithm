/* ----------<문제 정의>----------
문제: 문자열 잘라서 점수 계산
입력: 점수와 계산 방식을 나타내는 문자열
출력: 점수
*/
/* ----------<알고리즘:O(n)>----------
(2020카카오인턴십/수식최대화 문제의 피연산자, 연산자 추출 로직과 유사)

숫자 문자가 나오면 string 변수에 추가하다가
S, D, T가 나오면 그동안 추출한 숫자 string을 int형으로 변환
S, D, T가 주어진 계산 방식대로 계산
*, #도 마찬가지로 주어진 계산 방식대로 계산
(단, *에서 이전 점수까지 계산 고려할 때 하나만 존재하는 배열에 할당 범위를 벗어나는 접근을 피하도록 예외 처리를 해주어야 한다.)
*/
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> term;
    string str_temp="";
    int int_temp;
    for(int i = 0; i < dartResult.length();i++){
        if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            int_temp = stoi(str_temp);  // 숫자로 변환
            if(dartResult[i] == 'S')
                term.push_back(int_temp);
            else if(dartResult[i] == 'D')
                term.push_back(pow(int_temp,2));
            else if(dartResult[i] == 'T')
                term.push_back(pow(int_temp,3));
            str_temp="";    // 피연산자 문자열 초기화
        }
        else if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            str_temp += dartResult[i];
        }
        else if(dartResult[i] == '*' || dartResult[i] == '#'){
            if(dartResult[i] == '*'){
                term[term.size()-1] = term[term.size()-1]*2;    // 현재 점수 2배
                if(term.size() > 1)                             // 이전 점수 존재하면 2배
                    term[term.size()-2] = term[term.size()-2]*2;
            }
            else if (dartResult[i] == '#'){
                term[term.size()-1] = term[term.size()-1]*(-1);    // 현재 점수는 마이너스
            }
        }
    }
    //cout << term.size() << endl; //   항상 3개
    for(int i = 0; i < term.size();i++){    // 점수 계산
        answer+=term[i];
    }
    
    return answer;
}