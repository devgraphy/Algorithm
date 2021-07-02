/* ----------<문제 정의>----------
문제: n 계단을 오르는 방법의 수(1개 또는 2개 계단씩 오를 수 있음)
입력: 1<=n<=45
출력: 방법 수
*/
/* ----------<알고리즘:o(n^2)>----------
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
/* ----------<유사 알고리즘:o(n^2)>----------
return을 이용한 recursive bruteforce

return값을 이용해서 recursion bruteforce를 구현할 수 있다.
이때는 최종 목적지에서 역으로 계산해 온다.
즉, 목적지3의 2로부터 오는 방법 수는 하나. 목적지3의 1로부터 오는 방법 수는 하나
n과 딱 맞아떨어질 때 1 반환, 초과하면 0 반환
*/

class Solution {
public:
    int dfs(int i, int n){
        if(i > n)
            return 0;
        else if(i == n)
            return 1;
        return dfs(i+1, n) + dfs(i+2, n);
    }
    int climbStairs(int n) {
        return dfs(0,n);
    }
};