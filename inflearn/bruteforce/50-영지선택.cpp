/* 모델링
문제: 큰 격자판에서 최대 나무 개수를 얻을 수 있는 작은 격자 위치 정하기
입력: 큰 격자판 크기, 큰 격자판 원소, 작은 격자판 크기 5<=H,W<=50
출력: 최대 나무 개수
알고리즘(2차원 배열 탐색-Bruteforce) - solve myself
2차원 배열 순회: O((h-m)*(w-n)*m*n):  시간초과X 예상 
    하사받을영지크기만큼 순회    
*/

#include <iostream>
#include <climits>
using namespace std;
int a[55][55];
int main(){
    int h1, w1, h2, w2;
    int sum = 0, res = INT_MIN;
    cin >> h1 >> w1;
    for(int i = 1; i <= h1; i++){
        for(int j = 1; j <= w1;j++){
            cin >> a[i][j];
        }
    }
    cin >> h2 >> w2;
    for(int i = 1; i <= h1-h2+1; i++){
        for(int j = 1; j <= w1-w2+1;j++){
            sum = 0;
            for(int m = i; m < i+h2; m++){      // i+h2에서 i 빠트리지 않도록 주의
                for(int n = j; n < j+w2; n++){  // 그리고 m+h2가 아님에 주의
                    sum+=a[m][n];
                    // cout << a[m][n] << " ";
                }
                // cout << endl;
            }
            if(sum > res)
                res = sum;
        }
    }
    cout << res;
}