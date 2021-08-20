/* ----------<문제 정의>----------
문제: 단어 단위 뒤집기
입력: 문자열
출력: 뒤집은 문자열
*/
/* ----------<고려 사항>----------
1. 공백있는 문자열 입력받기(문자열간 구분은 개행)

cin.ignore와 getline(cin,) 사용법
    두 번째 입력의 첫번째 단어를 출력하지 못함
    cin.ignore의 위치가 중요하다.
*/
/* ----------<알고리즘>----------
메모리:2024KB
시간:464ms
스택 이용 -> 단어 뒤집기
공백 외에 문자열 끝에 대한 처리도 해주어야 마지막 단어가 출력된다.
공백 단위로 뒤집으므로 공백인 경우와 공백이 아닌 경우로 구분하여 처리한다.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    int n;
    stack<char> st;
    string str, deststr;
    cin >> n;
    cin.ignore();
    // 케이스별
    for(int i = 0; i < n; i++){
        getline(cin, str);
        int strlen = str.length();
        // 문자열 순회
        for(int j = 0; j < strlen; j++){
            // 공백일 경우
            if(str[j] == ' '){
                // 스택에 쌓인 문자 모두 출력
                while(st.size()){
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else{
                st.push(str[j]);
            }
        }
        while(st.size()){
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}
