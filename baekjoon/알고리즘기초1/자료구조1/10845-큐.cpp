/* ----------<문제 정의>----------
문제: 큐 구현(배열)
입력: 명령어 수(최대 10만), 명령어와 수(수는 1보다 크다)
출력: 명령어에 따른 결과
*/
/* ----------<Queue 자료구조 개념>----------
먼저 들어간 것이 먼저 나오는 구조
큐는 입구와 출구가 다르다.
중간 삽입이 없다.
*/
/*----------<알고리즘>----------
최대 명령어 수가 10만이므로 최대 10만개가 큐의 사이즈가 된다.
이후에 들어오는 것에 대해서 신경을 쓰지 않는다면 배열로 만들어도 괜찮을 듯하다.
front = 0 - pop시 증가
back = 0 - push시 증가
size = back - front
항상 back >= front임에 주의
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, num, front = 0, back = 0;
    int arr[100001]={0,};
    string comm;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cin >> comm;
        if(comm == "push"){
            cin >> num;
            arr[back++] = num;
        }
        else if(comm == "pop"){
            if(front < back)
                cout << arr[front++] << '\n';
            else
                cout << -1 << '\n';
            
        }
        else if(comm == "size"){
            cout << back-front << '\n';
        }
        else if(comm == "empty"){
            if(back-front <= 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(comm == "front"){
            if(back-front>0) cout << arr[front] << '\n';
            else cout << -1 << '\n';
        }
        else if(comm == "back"){
            if(back-front>0) cout << arr[back-1] << '\n';
            else cout << -1 << '\n';
        }
    }
}