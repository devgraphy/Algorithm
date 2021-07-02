/* ----------<문제 정의>----------
문제: n 계단을 오르는 방법의 수(1개 또는 2개 계단씩 오를 수 있음)
입력: 1<=n<=45
출력: 방법 수
*/
/* ----------<알고리즘>----------
1과 2의 조합.
1+1+...+1
1+1+...+2
...
1+2+2+2
=> 1과 2 Recursion Bruteforce -> 2^27=1억3천이므로 최악의 경우 시간초과
*/
/* ----------<궁금한 것>----------
2진 recursion bruteforce의 복잡도는?
최대 recursion depth가 트리의 높이(n)가 되고 이진 트리이므로
트리 노드의 개수의 개수는 2^n이다.
따라서, 시간 복잡도는 o(2^n)이다.
*/

class Solution {
public:
    int cnt = 0;
    void dfs(int a, int n){
        if(a == n){
            cnt++;
            return;
        }
        if(a+1 <= n)
            dfs(a+1,n);
        if(a+2 <= n)
            dfs(a+2,n);
    }
    int climbStairs(int n) {
        dfs(0, n);
        return cnt;
    }
};