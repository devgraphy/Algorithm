/* 모델링
1. 문제: Inversion sequence를 통해서 원래의 수열 찾기
2. Inversion Sequence 정의: 1~n순서로 자기보다 앞선 수 중에 큰 수 개수
3. 흐름
    - 1보다 작은 수는 없기 때문에 첫번째 원소값으로 1의 위치가 결정된다.
    - 2보다 작은 수는 1 하나, 1을 제외하고 4번째 위치에 있으면 된다.
    - 3보다 작은 수는 1, 2. 2개를 제외하고 5번째 위치에 있으면 된다.
4. 알고리즘: o(n^2)
    - 별도 배열 하나(b)를 만든다. 배열은 n으로 초기화한다.
    - Inversion Sequence(이하 IS)의 원소 값을 pos에 할당
    - pos가 음수가 될 때까지
        IS의 인덱스가 보다 큰 수가 나오면 pos--
*/

#include <iostream>
using namespace std;
int is[102];
int b[102];
int main(){
    int n, pos;
    cin >> n;
    fill_n(b,n+1,n);    // 배열 초기화: n+1크기만큼 n으로 초기화
    for(int i = 1; i <= n; i++){    // IS입력
        cin >> is[i];
    }
    for(int i = 1; i < n; i++){ // n은 자동 결정
        pos = is[i];
        for(int j = 1; j <= n; j++){
            if(b[j] > i)
                pos--;
            if(pos < 0){
                b[j] = i;
                break;
            }
        }
    }
    for(int i = 1; i <= n ;i++)
        cout << b[i] << " ";    
}
