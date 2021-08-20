/* ----------<알고리즘>----------
문제: 스택으로 만들 수 있는 수열 판단
입력: n, n개의 수 (n은 10만 이하)
출력: 가능할 시 연산자/ NO
*/
/* ----------<알고리즘>----------
입력받은 수열을 하나씩 확인하면서 1~n 순서대로 stack 연산
즉, 입력받은 수열이 나오도록 스택 연산 시행
입력받은 수에 대해 현재 까지 스택에 넣은 수가 작으면 그 수가 나올 때까지 입력받기
*/
/* -----<예외 케이스>-----
입력받은 수열 각각에 대해 1~n을 순서대로 처리해주기 위해 for문으로 구현한다면 
n까지 도달했을 때 한번만 처리해주고 반복되는 스택 작업을 처리할 수 없게된다.
5
1
2
5
3
4
예상 결과: NO
실행 결과:
+
-
+
+
+
-

🧐그래서 do~while로 바꿔본다.
*/
/* -----<시간 초과>-----
알고리즘 복잡도를 계산하면 O(N)으로 추측됨.
따라서 무한 루프에 빠지는 예외 케이스가 존재한다고 생각됨
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    int n, num, p = 0;
    string op;
    int arr[100001];
    stack<int> st;
    // 수열 입력 받기
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        arr[i] = num;
    }
    int i = 1;
    do{
        if(i < arr[p]){
            st.push(i++);
            op+='+';
        }
        else if(i == arr[p]){
            st.push(i++);
            op+='+';
            st.pop();
            op+='-';
            p++;
        }
        else{
            if(st.top() == arr[p]){
                st.pop();
                op+='-';
                p++;
            } 
            else {
                cout << "NO";
                return 0;
            }
        }      
    }while(p < n);
    for(i = 0; i < op.length(); i++)
        cout << op[i] << endl;
}