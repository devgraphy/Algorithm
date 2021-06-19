/* 모델링
1. 문제: 2차원 배열을 행단위로 탐색하면서 평균을 구하고 평균과 가장 가까운 값 찾기
2. 입력: 9*9 격자판. 원소는 100보다 작다.: 
3. 출력: 평균(소수점 첫자리에서 반올림), 평균과 가장 가까운 값(2개 이면 그 중 큰 값)
4. 알고리즘(두번의 격자판 탐색):o(n^2)-solve myself
*/

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int a[10][10];
int main(){
    float sum = 0;  // 피연산자의 자료형은 연산 결과에 영향을 준다.
    int avg = 0;
    int mindifelem = INT_MAX;
    for(int i = 0; i < 9; i++){     // 격자판 입력
        for(int j = 0; j < 9; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < 9; i++){
        sum = 0;
        mindifelem = INT_MAX;
        for(int j = 0; j < 9; j++){
            sum+=a[i][j];
        }
        avg = round(sum / 9);
        cout << avg << " ";
        for(int j = 0; j < 9; j++){
            if(abs(avg-mindifelem) > abs(avg-a[i][j]))
                mindifelem = a[i][j];
            else if(abs(avg-mindifelem) == abs(avg-a[i][j])){
                if(a[i][j] > mindifelem)
                    mindifelem = a[i][j];
            }

        }
        cout << mindifelem << endl;
    }
}