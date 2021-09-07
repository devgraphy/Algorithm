/* ----------<문제 정의>----------
문제: 1,2,3 조합하여 합했을 때 n이 되는 조합의 수
*/
/* ----------<접근법>----------
중첩 for문으로는 뎁스를 특정할 수 없으므로 어려움
재귀 풀이
*/
/* -----<알고리즘>-----
cnt = 0 정의

재귀함수(sum)
    sum >= n일 때 (⭐ 등호로 처리하면 불일치한 경우에 대해 거르지 못해 무한루프에 빠진다.)
        cnt++
        return
    반복문으로 3개 수 중에 선택
*/

#include <iostream>
using namespace std;
int a[3] = {1, 2, 3};
int n, cnt = 0;
void dfs(int sum){
    if(sum >= n){
        if(sum == n)
            cnt++;
        return;
    }
    for(int i = 0; i < 3; i++){
        dfs(sum+a[i]);
    }
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cnt = 0;
        cin >> n;
        dfs(0);
        cout << cnt << '\n';
    }
    
}