/* ----------<문제 정의>----------
문제: 스택 자료구조 구현하기
입력: 명령어(최대 1만)와 수
출력: 명령어에 따른 값
*/
/* ----------<자료구조 선택 근거>----------
배열(명령어가 최대 10만이므로 최대 입력 10만개로 가정해서 배열 크기를 잡는다.)
*/
/* ----------<자료구조 변경>----------
배열의 고정 크기로 인한 문제를 해결하기 위해 벡터로 바꾼다.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    vector<int> st;
    string comm;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin.clear();
        cin >> comm;
        if(comm == "push"){
            cin >> num;
            st.push_back(num);
        }
        else if(comm == "pop"){
            if(!st.empty()){
                cout << st.at(st.size()-1) << endl;
                st.pop_back();
            }
            else cout << -1 << endl;

        }
        else if(comm == "size"){
            cout << st.size() << endl;
        }
        else if(comm == "empty"){
            if(!st.empty()) cout << 0 << endl;
            else cout << 1 << endl;

        }
        else if(comm == "top"){
            if(!st.empty()) cout << st.at(st.size()-1) << endl;
            else cout << -1 << endl;
            
        }
    }
}
