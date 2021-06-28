/* ----------<문제 정의>----------
문제: 키패드 트래킹
입력: 키패드 클릭 순서를 담은 배열, 주손잡이 정보를 담은 변수
출력: 키패드 클릭 시 사용 손
*/
/* ----------<알고리즘>----------
1,4,7은 무조건 왼손
3, 6, 9는 무조건 오른손
2, 5, 8, 0은 왼손과 오른손 중 가까운 손으로
*/
/* ----------<궁금한 것>----------
거리계산 방법 -> 키패드를 2차원 배열로 나타냄 -> x,y 좌표 거리 계산
벡터 복사 stl 모름 -> copy() 사용
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int keypad[13][2] = 
    {{4,2},
     {1,1},{1,2},{1,3},
     {2,1},{2,2},{2,3},
     {3,1},{3,2},{3,3},
     {4,1},{0,0},{4,3}};
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left[2] = {4,1};    // * 좌표로 왼손 위치 초기화
    int right[2] = {4,3};   // # 좌표로 오른손 위치 초기화
    for(int i = 0; i < numbers.size();i++){
        if(numbers[i] == 1 ||numbers[i] == 4||numbers[i] == 7){         // 1, 4, 7이 눌린 경우
            copy(keypad[numbers[i]],keypad[numbers[i]]+2,left);             // 왼손의 위치를 입력 키패드 좌표로 이동(좌표 길이:2)
            answer+="L";
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){ // 3, 6, 9가 눌린 경우
            copy(keypad[numbers[i]],keypad[numbers[i]]+2,right);
            answer+="R";
        }
        else{                                                           // 2, 5, 8, 0이 눌린 경우
            int temp_left = abs(keypad[numbers[i]][0]-left[0])+abs(keypad[numbers[i]][1]-left[1]);
            int temp_right = abs(keypad[numbers[i]][0]-right[0])+abs(keypad[numbers[i]][1]-right[1]);
            if(temp_left < temp_right){         // 왼손이 가까우면
                copy(keypad[numbers[i]],keypad[numbers[i]]+2,left);
                answer+="L";
            }
            else if(temp_left > temp_right){    // 오른손이 가까우면
                copy(keypad[numbers[i]],keypad[numbers[i]]+2,right);
                answer+="R";
            }
            else{
                if(hand == "left"){
                    copy(keypad[numbers[i]],keypad[numbers[i]]+2,left);
                    answer+="L";
                }
                else{
                    copy(keypad[numbers[i]],keypad[numbers[i]]+2,right);
                    answer+="R";
                }               
            }
        }
        
    }
    return answer;
}