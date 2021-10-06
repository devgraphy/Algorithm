/* ----------<문제 정의>----------
문자열에 포함된 숫자를 가지고 가장 큰 30의 배수 찾기
*/
/* ----------<접근법>----------
30의 배수 특징이 뭐가 있을까...
3 2 5가 반드시 포함되어 있어야 함
3 2 5가 없으면 -1 출력
3 2 5가 있다면 나머지 수를 모두 곱하면 됨
단, 0은 10을 간주

3 2 5를 인자로 갖는 수라는 것을 어떻게 판단할까?
임의의 수를 만들고 나서 3, 2, 5 인자를 갖는 수인지 판단하는 것은 매우 비효율적이다.

5의 배수이면서 2의 배수이려면 0으로 끝나야 한다.
나머지 수로 3의 배수로 만들어지는 최대의 수를 찾으면 됨.
그렇다면 3의 배수의 특징은?(힌트 참고)
각 자리 숫자의 합이 3의 배수이면 3의 배수이다.

그렇다면 나머지 숫자를 조합하여(nCn nCn-1 ... nC2 nC1) 만든 수에서 3의 배수를 찾아내면 종료하면 출력하고 종료하면 될 것 같다.
가장 큰 숫자를 조합해야 하므로 정렬한다.
*/
/* ----------<알고리즘>----------
0 없으면 -1 출력하고 종료
    (입력받으면서 0이 등장하면 체크, 추후 체크되지 않았으면 종료)
조합해서 가장 큰 숫자 찾기(중복을 허용하지 않는 조합)
    (큰 숫자를 먼저 조합해야하므로 정렬한다.)
    for문 돌면서 nCn부터 nC1을 구하기 위한 dfs를 실행한다.
    
dfs를 통해 basecase를 만족했을 때 3으로 나누어 떨어지는지 확인한다.
    나누어 떨어지면 10을 곱하여 출력한다.
    출력 여부 변수를 체크하고 dfs가 끝난후 확인해서 출력했으면 프로그램을 아예 종료한다.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string num;
int numlen;
int combNum;
bool prtchk = false;    // 출력 여부
void dfs(int base, int cnt, int idx){
    // basecase
    if(cnt == base){
        //cout << combNum << endl;
        if(combNum % 3 == 0){
            combNum *= 10;
            cout << combNum;
            prtchk = true;
        }
        return;
    }
    for(int i = idx; i < numlen; i++){
        //cout << (int)(num[idx]-'0') << endl;
        combNum = combNum*10 + (int)(num[idx]-'0');
        dfs(base, cnt+1, i+1);
        combNum = combNum/10;
        if(prtchk == true) return;
    }
}

int main(){
    cin >> num;
    sort(num.begin(), num.end(), greater<>());  // 정렬
    numlen = num.length();
    if(num[numlen-1] != '0'){    // 0은 2와 5 인자 포함을 나타냄
        cout << -1;
        return 0;
    }
    num = num.substr(0, numlen-1);  // 0은 기본으로 포함하므로 삭제
    numlen--;
    // nCn ... nC1 DFS
    for(int i = numlen; i >= 1; i--){
        dfs(i, 0, 0);
        if(prtchk == true) return 0;
    }
}