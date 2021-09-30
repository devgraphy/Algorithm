/* ----------<문제 정의>----------
문제: 한 쪽에서 보이는 막대기 골라내기
입력: 막대기 개수 n, n개의 막대기 높이
*/
/* ----------<접근법>----------
입력 순과 반대로 확인을 해야하므로 스택을 이용해본다.
최댓값보다 크면 cnt를 증가한다. 그리고 최댓값을 갱신한다.
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n, temp, cnt = 0;
    int max_val = -1;
    stack<int> st;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        st.push(temp);
    }
    while(!st.empty()){
        if(st.top() > max_val) {
            max_val = st.top();
            cnt++;
        }
        st.pop();
    }
    cout << cnt;
}
