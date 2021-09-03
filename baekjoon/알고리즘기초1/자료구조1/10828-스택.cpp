/* ----------<문제 정의>----------
문제: 스택 자료구조 구현하기
입력: 명령어(최대 1만)와 수
출력: 명령어에 따른 값
*/
/* ----------<자료구조 선택 근거>----------
배열(명령어가 최대 10만이므로 최대 입력 10만개로 가정해서 배열 크기를 잡는다.)
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, top = -1;
    int st[10001]={0,};
    string comm;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin.clear();
        cin >> comm;
        if(comm == "push"){
            cin >> num;
            st[++top] = num;
        }
        else if(comm == "pop"){
            if(top>=0){
                cout << st[top] << endl;
                st[top--] = 0;
            }
            else cout << -1 << endl;

        }
        else if(comm == "size"){
            cout << top + 1 << endl;
        }
        else if(comm == "empty"){
            if(top >= 0) cout << 0 << endl;
            else cout << 1 << endl;

        }
        else if(comm == "top"){
            if(top >= 0) cout << st[top] << endl;
            else cout << -1 << endl;
            
        }
    }
}
