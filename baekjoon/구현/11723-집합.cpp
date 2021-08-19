/* ----------<문제 정의>----------
문제: 집합 구현
입력: 명령어 숫자
출력: 명령어에 따른 값
*/
/* ----------<알고리즘>----------
시간 초과
n보다 적게 입력을 받고 끝남

set 라이브러리 사용 -> set.find() 메서드를 사용하여 조회하는데 O(N)
*/
/* -----<개선 방안>-----
- 조회시간을 줄이기 위해 배열을 사용할 수 있다.
- 여기서 공간까지 줄이기 위해서 비트마스킹을 사용할 수 있다.
*/
/* ----------<시간 개선 알고리즘>----------
- 배열을 사용해 조회 시간을 줄인다.
- 입출력 속도 향상을 위한 별도의 처리로 시간 초과를 면할 수 있었다.
    ios_base::sync_with_stdio(0);
    cin  tie(NULL);
    cout -> printf   
*/
/* -----<새롭게 안 것>-----
여러 케이스를 확인하는 알고리즘에서 cin 버퍼가 꽉 찰 수 있다.
    이때 cin.clear() 를 추가해줘야 한다.
    cin 버퍼가 가득차면 입력없이 바로 패스한다. 그리고 그 변수는 공백이 들어간다.
*/
#include<iostream>
#include <string>
using namespace std;
int arr[21];

int main(){
    ios_base::sync_with_stdio(0);//입출력 속도 향상
    cin.tie(NULL);
    int n;
    string comm;
    int input;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> comm;
        if(cin.fail()){
            cin.clear();  // cin 버퍼 비우기. cin이 21개 부터는 입력받지 않고 그냥 pass함. 출력하면 공백임
            cin >> comm;
        }
        if(comm == "add"){
            cin >> input;
            arr[input] = 1;
        } 
        else if(comm == "remove"){
            cin >> input;
            arr[input] = 0;
        }
        else if(comm == "check"){
            cin >> input;
            arr[input] == 1 ? printf("%d\n",1): printf("%d\n",0);

        }
        else if(comm == "toggle"){
            cin >> input;
            arr[input] == 1 ? arr[input] = 0:arr[input] = 1;
        }
        else if(comm == "all"){
            for(int i = 1; i <= 20; i++)
                arr[i] = 1;
        }
        else if(comm == "empty"){
            for(int i = 1; i <= 20; i++)
                arr[i] = 0;
        }

    }
}