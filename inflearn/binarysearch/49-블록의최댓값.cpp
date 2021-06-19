/* 모델링
문제: 정면, 오른쪽 측면 각각에서 본 블록의 높이로 블록 쌓는데 필요한 최대 개수 구하기
입력: 격자 크기 N, 정면 블록 N개, 측면 블록 N개. 3 <= N <= 10
출력: 최대 블록수
알고리즘(2차원배열 탐색): o(n^2)-solve myself
정면과 측면이 만나는 수 중 최솟값을 선택한다.
2 0 3 1
2 0 2 1
1 0 1 1
1 0 1 1
*/
#include <iostream>
#include <algorithm>
int a[11];
int b[11];
using namespace std;
int main(){
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum+=min(a[i],b[j]);
        }
    }
    cout << sum;
}
 