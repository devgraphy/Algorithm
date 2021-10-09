/* ----------<문제 정의>----------
문제: 빙고를 외치는 순간(3개의 선을 그을 때)의 숫자 알아내기
입력: 5*5 보드, 수
출력: 빙고를 외치는지 수의 타이밍
*/
/* ----------<접근법>----------
선은 5개의 수가 한줄로 이어졌을 때 그어짐
수직, 수평, 대각 방향 모두 선이 그어질 수 있음
외치는 수가 어디에 있는지 찾아야 하므로 -> 1 + 2 + ... + 25 = 25 * 26 / 2
15번째 외치는 수부터 빙고를 외쳐야 하는지 판단하기 시작함
이렇게 하면 추가적으로 최대 10 * 12 번 확인함
(또한 한번 확인한 선은 다시 확인하지 않도록 처리하면 중복 연산을 피할 수 있음)
*/

#include <iostream>
using namespace std;
int a[25][25];
int chk[25][25];
int callnum[25];
int chkbingo(){
    int cnt = 0;
    bool contin = true; 
    // 가로
    for(int i = 0; i < 5; i++){
        contin = true;
        for(int j = 0 ;j < 5; j++){
            if(chk[i][j] == 0){
                contin = false;
                break;
            }
        }
        if(contin == true) cnt++;
    }
    // 세로
    for(int i = 0; i < 5; i++){
        contin = true;
        for(int j = 0 ;j < 5; j++){
            if(chk[j][i] == 0){
                contin = false;
                break;
            }
        }
        if(contin == true) cnt++;
    }
    // 왼위, 오른아래 대각
    contin = true;
    for(int i = 0; i < 5; i++){
        if(chk[i][i] == 0){
            contin = false;
            break;
        }
    }
    if(contin == true) cnt++;
    // 오른위, 왼아래 대각
    contin = true;
    for(int i = 0; i < 5; i++){
        if(chk[i][4-i] == 0){
            contin = false;
            break;
        }
    }
    if(contin == true) cnt++;
    return cnt;
}

int main(){
    // 빙고 판 생성
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> a[i][j];
        }
    }
    // 사회자가 부르는 수
    for(int k = 0; k < 25; k++){
        cin >> callnum[k];
    }
    // 빙고판에서 위치 찾기
    bool find = false;
    for(int k = 0; k < 25; k++){
        find = false;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(a[i][j] == callnum[k]){
                    chk[i][j] = 1;
                    find = true;
                    break;
                } 
            }
            if(find == true) break;
        }
        if(k >= 14){
            if(chkbingo() >= 3){
                cout << k+1;
                return 0;
            }
        }
    }  
}